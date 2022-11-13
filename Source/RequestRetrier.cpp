#include <RequestRetrier.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;


namespace SPS
{
extern "C"
{
    /** @fn createqueuemanager()
        @brief This function returns the RequestRetrier object
    */
    AbstractComponent* createrequestretrier()
    {
        return (new RequestRetrier());
    }
}

//! Constructor
RequestRetrier :: RequestRetrier()
{
	reqParserPtr = NULL;
	xmlInputAdapterObjPtr = NULL;
	retProvReqObjPtr = NULL;
	reqReceiverPtr = NULL;
	ftpReqReceiverPtr = NULL;
}

//! Destructor
RequestRetrier :: ~RequestRetrier()
{
	delete reqParserPtr;
	
}

bool RequestRetrier :: Start(GlobalDataInfo *pGDIPtr, AbstractBaseData *pDiffParameterPtr)
{
	bool        lIsInitialized;     //!< Used to hold the return value of initialize function

    try
    {
        if (!pGDIPtr)
        {
            throw ABL_Exception(1100, __FILE__, __LINE__, "Global Data Info is NULL. Cannot get the Component ID");
        }


		//! Calling the initialize function
        lIsInitialized = initialize(pGDIPtr);

        if (!lIsInitialized)
        {
            PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "Initialization failed. Stopping", L_CRITICAL, GDIPtr)
            throw ABL_Exception(2016, __FILE__, __LINE__, "Initialization failed. Stopping");
        }

		stopNowSemaphore.mb_acquire();
		
		//! Creating a new thread of StartProcess, which will start fetchng requests from t_retry_provisioning_request.
        ExecuteInNewThread0(&threadID, NULL, RequestRetrier, this, bool, &RequestRetrier::StartProcess);

        PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Request Retrier Component Started Successfully", L_SYSTEM, GDIPtr);
		isThreadRunning = true;


	}
	catch (ABL_Exception &exception)
	{
		PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, exception.mb_getMessage(), L_ERROR, GDIPtr);
		isThreadRunning = false;
		return false;
	}
    return true;
	
}

bool RequestRetrier :: initialize(GlobalDataInfo * &GDI)
{
    try
    {
        GDIPtr = GDI;   //!< Taking a copy of the GlobalDataInfo

        //! Getting the component id of the Request-Retrier from the GlobalDataInfo
        componentID = GDIPtr->componentPrivateIDMap[REQUEST_RETRIER_COMPONENT_NAME];


        if(!componentID)
        {
            sprintf(logBuf, "Cannot Obtain Component Id of Request Retrier Component from ComponentPrivate Map");
        	PREPARE_LOG_MSG(componentID, 0, 0, "2014", 0, logBuf, L_CRITICAL, GDIPtr)
            throw ABL_Exception(2014, __FILE__, __LINE__, logBuf);
        }
		
		ComponentInfoMap::iterator lComponentInfoMapIter;
		lComponentInfoMapIter = GDIPtr->componentMap.find(componentID);

		if (lComponentInfoMapIter != GDIPtr->componentMap.end())
		{	
			_retryInterval = lComponentInfoMapIter->second->retryInterval;
		}	
		//! Checking if, the XMLInputAdapter pointer is null or not. If it is null, the component should be stopped.	
		if (!xmlInputAdapterObjPtr)
		{
			sprintf(logBuf, "The XMLInputAdapter Pointer is NULL. Cannot Start the Request Retrier");
			PREPARE_LOG_MSG(componentID, 0, 0, "2014", 0, logBuf, L_CRITICAL, GDIPtr)
			throw ABL_Exception(2014, __FILE__, __LINE__, logBuf);
		}
		
    }
    catch (ABL_Exception &exception)
    {
        return false;
    }
    return true;

}//RequestRetrier :: initialize

bool RequestRetrier :: StartProcess()
{
	int lRetryReqCount;					//!< Local variable to hold the count of requests in t_retry_provisioning_request.
	int lScheduleReqCount;					//!< Local variable to hold the count of requests in t_retry_provisioning_request.
	int lRetryIntervaltime;				//!< To sleep for the required time to fetch the requests from database
	int lScheduleIntervaltime;				//!< To sleep for the required time to fetch the requests from database
	JobIdMap::iterator lJobIdMapIter;	//!< Iterator to JobIdMap.

	//! Updating the thread id.
	this->threadID = pthread_self();
    	
	//! Creating a XML Request parser object
    reqParserPtr  = new XMLRequestParser();
	lRetryIntervaltime = 1;	
	while(true)
	{

		//! Iterating through the JobIdMap and deleting the RetryProvReq object.
		for (lJobIdMapIter = _jobIdMap.begin(); lJobIdMapIter != _jobIdMap.end(); lJobIdMapIter++)	
		{
			delete lJobIdMapIter->second;
		}

		//! Clearing the JobIdMap.
		_jobIdMap.clear();
		_scheduleJobIdVec.clear();

		/**
         *  Trying to acquire the stop now semaphore. If the semaphore is acquired, component should update its isThreadRunning to false
         *  and then exit the thread.
         */	
		if (stopNowSemaphore.mb_tryAcquire())
		{
        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Request Retrier Component Stopped Successfully", L_SYSTEM, GDIPtr);
			isThreadRunning = false;
			pthread_exit(NULL);
		}

		if (SCHEDULE_REQUEST_PICKING_TIME <= lScheduleIntervaltime)
        {
            /**
             *  Calling the fetchScheduleRequests, which will return the count of requests in t_schedule_request. It also
             *  fills the JobIdMap with the ScheduleProvReq objects.
             */
            lScheduleReqCount = fetchScheduleRequests();

            /**
             *  If there are some requests to be processed, then get the XML request for those job_id's from
             *  t_schedule_request table.
             */
            if (lScheduleReqCount > 0)
            {
        		PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "There are some scheduled provisioning requests for processing", L_DEBUG1, GDIPtr);
                fetchScheduleXMLRequest();
            }

            lScheduleIntervaltime = 1;
        }

		if (_retryInterval <= lRetryIntervaltime)	
		{
			/**
		 	 *	Calling the fetchRetryRequests, which will return the count of requests in t_retry_provisioning_request. It also
		 	 *	fills the JobIdMap with the RetryProvReq objects.
		 	 */
			lRetryReqCount = fetchRetryRequests();
	
			/**
			 *	If there are some requests to be processed, then get the XML request for those job_id's from 
			 *	t_provisioning_request table.
			 */	
			if (lRetryReqCount > 0)
			{
        		PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "There are some retry/rollback requests for processing", L_DEBUG1, GDIPtr);
				fetchXMLRequest();	
			}
			lRetryIntervaltime = 1;
		}
		//! Sleeping for cofigured time.
		sleep(1);
		lRetryIntervaltime++;
		lScheduleIntervaltime++;

	}//while

	return true;
		
}//RequestRetrier :: StartProcess

void RequestRetrier :: fetchXMLRequest()
{
	ABL_String 		lSQLQuery;					//!< Local ABL_String object for storing SQL query.
	bool 			lReturnVal;						//!< To hold the return value from addRetryRollBackParam function.
	ABL_ResultSet   lABLResultSetObj;		//!< ABL_ResultSet object for storing the rows fecthed.
    ABL_Statement   lABLStatementObj;		//!< ABL_Stement object for executing a query.
	char			lXMLRequest[MAX_BUF_SIZE + 1];	//!< Character buffer to store the XM request.
	char 			lSQLQueryBuffer[MAX_BUF_SIZE];	//!< Character buffer to store the SQL query.
	
	JobIdMap::iterator lJobIdMapIter;		//!< Iterator to the JobIdMap, to iterate through the RetryProvReq in the JobIdMap.

	ABL_Connection lABLConnection;			//!< ABL_Connection object to connect to database	
	
	//! Connecting to database
	lABLConnection.mb_createConnection(GDIPtr->ablService);


	//! Iterating through the JobIdMap	
	for (lJobIdMapIter = _jobIdMap.begin(); lJobIdMapIter != _jobIdMap.end(); lJobIdMapIter++)
	{
		sprintf(_queryBuffer, "select request from %s where job_id = %d", PROVISIONING_REQUEST_TABLE, lJobIdMapIter->first);
	    lSQLQuery = _queryBuffer;

		/**
		 *	Fetching the xml request from t_provisioning_request.
		 */
		lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);
	    lABLResultSetObj = lABLStatementObj.mb_executeQuery();
    	lABLResultSetObj.mb_fetch();
		
		strcpy(lXMLRequest, lABLResultSetObj.mb_getString(1).mb_getSTLString().c_str());

		lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
		lABLConnection.mb_terminateStatement(lABLStatementObj);
	
		/**
		 *	Calling the addRetryRollBackParam function, which will modify the XML request fetched from t_provisioning_request table,
		 *	to add RRT, OLD and PRT parameters.
		 */
		lReturnVal = addRetryRollBackParam(lXMLRequest, lJobIdMapIter->second, lJobIdMapIter->first);
		
		/**
		 *	If there's any error in forming or sending the request object, then continue with the next job_id.
		 */
		if (!lReturnVal)
		{
			continue;
		}
		
		/**
		 *	If the request object is successfully sent to the data queue of Request Processor,
		 *	then delete the entry from t_retry_provisioning_request table.
		 */	
		sprintf(lSQLQueryBuffer, "delete from t_retry_provisioning_request where job_id = %d", lJobIdMapIter->first);
		lSQLQuery = lSQLQueryBuffer;	
		lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);	
		lABLStatementObj.mb_execute();
		lABLConnection.mb_commit();
		lABLConnection.mb_terminateStatement(lABLStatementObj);	
	}//for (lJobIdMapIter = _jobIdMap.begin(); lJobIdMapIter != _jobIdMap.end(); lJobIdMapIter++)	

}//void RequestRetrier :: fetchXMLRequest()

void RequestRetrier :: fetchScheduleXMLRequest()
{
	ABL_String 		lSQLQuery;					//!< Local ABL_String object for storing SQL query.
	bool 			lReturnVal;						//!< To hold the return value from addRetryRollBackParam function.
	ABL_ResultSet   lABLResultSetObj;		//!< ABL_ResultSet object for storing the rows fecthed.
    ABL_Statement   lABLStatementObj;		//!< ABL_Stement object for executing a query.
	char 			lSQLQueryBuffer[MAX_BUF_SIZE];	//!< Character buffer to store the SQL query.
	
	unsigned int	lJobIndex;
	ABL_Connection lABLConnection;			//!< ABL_Connection object to connect to database	

	try
	{
	
	lABLConnection.mb_createConnection(GDIPtr->ablService);

	//! Looping through the JobId Vector	
	for (lJobIndex = 0; lJobIndex < _scheduleJobIdVec.size(); lJobIndex++)
	{
		sprintf(_queryBuffer, "select oss_user_id, session_id, request from %s where job_id = %lu", PROVISIONING_REQUEST_TABLE, _scheduleJobIdVec[lJobIndex]);
	    lSQLQuery = _queryBuffer;

		/**
		 *	Fetching the xml request from t_provisioning_request.
		 */
		lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);
	    lABLResultSetObj = lABLStatementObj.mb_executeQuery();
    	lABLResultSetObj.mb_fetch();
		
		lReturnVal = sendScheduleRequest(lABLResultSetObj.mb_getString(3).mb_getSTLString(), _scheduleJobIdVec[lJobIndex], lABLResultSetObj.mb_getInt(1), lABLResultSetObj.mb_getInt(2));

		lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
		lABLConnection.mb_terminateStatement(lABLStatementObj);
		
		/**
		 *	If there's any error in forming or sending the request object, then continue with the next job_id.
		 */
		if (!lReturnVal)
		{
			continue;
		}
		
		/**
		 *	If the request object is successfully sent to the data queue of Request Processor,
		 *	then delete the entry from t_retry_provisioning_request table.
		 */	
		sprintf(lSQLQueryBuffer, "delete from %s where job_id = %lu", SCHEDULE_REQUEST_TABLE, _scheduleJobIdVec[lJobIndex]);
		lSQLQuery = lSQLQueryBuffer;	
		lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);	
		lABLStatementObj.mb_execute();
		lABLConnection.mb_commit();
		lABLConnection.mb_terminateStatement(lABLStatementObj);	
	}//for	
	}
	catch(ABL_Exception &ex)
	{
    	PREPARE_LOG_MSG(componentID, 0, 0, "3001", 0, ex.mb_getMessage(), L_CRITICAL, GDIPtr)
		return;
	}

}//void RequestRetrier :: fetchScheduleXMLRequest()


bool RequestRetrier :: sendScheduleRequest(std::string pXMLReq, unsigned long pJobId, uint_32 pUserID, uint_32 pSessionID)
{
	ProvisioningRequest     *lProvRequest; 					//!< Provisioning request object pointer
	BSSInfoMap::iterator    lBSSInfoMapIter;       //!< BSSInfoMap iterator
    bool                    lIsReqRecvFound;

	lProvRequest = new Request();				//!< Creating a new request object.
	
	//! Parsing the xml request string fetched from t_provisioning_request. If parsing fails, return false.	
	if (!reqParserPtr->ParseRequestString(pXMLReq.c_str()))
	{
		return false;
	}
	//! Forming the request object from the RequestParser object.	
	if (lProvRequest->ParseRequest(reqParserPtr))
	{
		lProvRequest->request = pXMLReq;
	}
	else
	{
		return false;
	}
	
	lProvRequest->prevType = lProvRequest->type;
	lProvRequest->type = REQ_RETRY_STATUS;
	std::string local, local2;
	local = lProvRequest->type;
	local2 = lProvRequest->prevType;
	lProvRequest->AddGlobalParam(RETRY_ROLLBACK_GLOBAL_KEY, local);
	lProvRequest->AddGlobalParam(PREVIOUS_REQ_TYPE, local2);
	lProvRequest->AddGlobalParam(OLD_REQUEST_KEY, OLD_REQUEST_VALUE);
	lProvRequest->isOldRequest = true;
	lProvRequest->requestType =  ASYNCHRONOUS_REQUEST_TYPE;
	reqParserPtr->PrepareRequestString(lProvRequest);

	//! Get the data queue pointer to send the request
	lIsReqRecvFound = false;
    lBSSInfoMapIter = xmlInputAdapterObjPtr->reqThrDetailMap.find(pSessionID);
    if (lBSSInfoMapIter != xmlInputAdapterObjPtr->reqThrDetailMap.end())
    {
        reqReceiverPtr = dynamic_cast<RequestReceiver *>(lBSSInfoMapIter->second);
        lIsReqRecvFound = true;
    }
    else
    {
        for (lBSSInfoMapIter = xmlInputAdapterObjPtr->reqThrDetailMap.begin(); lBSSInfoMapIter != xmlInputAdapterObjPtr->reqThrDetailMap.end(); lBSSInfoMapIter++)
        {
            reqReceiverPtr = dynamic_cast<RequestReceiver *>(lBSSInfoMapIter->second);
            if (pUserID == reqReceiverPtr->userID)
            {
                lIsReqRecvFound = true;
                break;
            }
        }
    }
    if( lIsReqRecvFound )
    {
        if (reqReceiverPtr->reqProcQueue)
        {
    		ABL_SmartPointer<AbstractDataMessage> lAbsDataMsg;
            lAbsDataMsg = lProvRequest;
            reqReceiverPtr->reqProcQueue->mb_put(lAbsDataMsg);
            return true;
        }
    }
    return false;

}// RequestRetrier :: sendScheduleRequest

bool RequestRetrier :: addRetryRollBackParam(std::string pXMLReq, RetryProvReq *pRetryProvReqObj, int pJobId)
{
	ProvisioningRequest     *lProvRequest; 					//!< Provisioning request object pointer

	lProvRequest = new Request();				//!< Creating a new request object.
	
	//! Parsing the xml request string fetched from t_provisioning_request. If parsing fails, return false.
	//PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Inside addRetryRollback", L_DEBUG1, GDIPtr);
	
	if (!reqParserPtr->ParseRequestString(pXMLReq.c_str()))
	{
		sprintf(logBuf, "XML Request parsing failed, reason : %s", reqParserPtr->GetErrors().c_str());
        //PREPARE_LOG_MSG(componentID, 0, 0, "2000", 0, logBuf, L_ERROR, GDIPtr);
		return false;
	}
	//! Forming the request object from the RequestParser object.	
	//PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Before Parsing", L_DEBUG1, GDIPtr);
	if (lProvRequest->ParseRequest(reqParserPtr))
	{
		lProvRequest->request = pXMLReq;
		sprintf(logBuf, "Got the message of type : %s " , reqParserPtr->GetDataMessageType().c_str());
        //PREPARE_LOG_MSG(componentID, 0, 0, "0000", 0, logBuf, L_DEBUG1, GDIPtr);
	}
	else
	{
		return false;
	}
	 //PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "After Parsing", L_DEBUG1, GDIPtr);
	
	/**
	 *	If the process_flag = 'T', then add RRT Parameter with value "T" and type of the Request object to 'T'.
	 */	
	if (REQ_RETRY_STATUS == pRetryProvReqObj->processFlag)
	{
		lProvRequest->prevType = lProvRequest->type;
		lProvRequest->type = REQ_RETRY_STATUS;
		std::string local, local2;
		local = lProvRequest->type;
		local2 = lProvRequest->prevType;
		lProvRequest->AddGlobalParam(RETRY_ROLLBACK_GLOBAL_KEY, local);
		lProvRequest->AddGlobalParam(PREVIOUS_REQ_TYPE, local2);
	}
	/**
     *  If the process_flag = 'R', then uadd RRT Parameter with value "R" and type of the Request object to 'R'.
	 *	Also add PRT parameter with value "R". Update the prevType of the Request Object to 'R'.
     */ 
	else if (REQ_ROLLBACK_TYPE == pRetryProvReqObj->processFlag)
	{
		lProvRequest->prevType = lProvRequest->type;
		lProvRequest->type = REQ_ROLLBACK_TYPE;
		std::string local, local2;
		local = lProvRequest->type;
		local2 = lProvRequest->prevType;
		lProvRequest->AddGlobalParam(RETRY_ROLLBACK_GLOBAL_KEY, local);
		lProvRequest->AddGlobalParam(PREVIOUS_REQ_TYPE, local2);

	} 
	/**
     *  Adding the parameter RRT with value as "C'. Callback will be handled in future release.
     */
	else
	{
		lProvRequest->prevType = lProvRequest->type;
        lProvRequest->type = REQ_CALLBACK_TYPE;
        std::string local, local2;
        local = lProvRequest->type;
        local2 = lProvRequest->prevType;
        lProvRequest->AddGlobalParam(RETRY_ROLLBACK_GLOBAL_KEY, local);
        lProvRequest->AddGlobalParam(PREVIOUS_REQ_TYPE, local2);
	}
	
	/**
	 *	For all RETRY/ROLLBACK/CALLBACK requests, the OLD parameter should be added with value "Y".
	 *	Update the isOldRequest field of the Request object to true.
	 *	Update the requestType of the Request object to A(Asynchronous)
	 *	Then call the PrepareRequest, which will update the Request Object
	 */
	
	lProvRequest->AddGlobalParam(OLD_REQUEST_KEY, OLD_REQUEST_VALUE);
	lProvRequest->isOldRequest = true;
	lProvRequest->requestType =  ASYNCHRONOUS_REQUEST_TYPE;
	//lProvRequest->PrepareRequest();
	
	reqParserPtr->PrepareRequestString(lProvRequest);
	/**
	 *	If the request is a rollback request, then the xml request should be updated in t_provisioning_request.
	 */
	//if (REQ_ROLLBACK_TYPE == pRetryProvReqObj->processFlag)
	//{
//		ABL_Statement lABLStatementObj;
//		ABL_String lABLString;
//		sprintf(lSQLQueryBuf, "update t_provisioning_request set request = '%s' where job_id = %d", lProvRequest->request.c_str(), pJobId);
//		lABLString = lSQLQueryBuf; 
//		lABLStatementObj = lABLConnection.mb_createStatement(lABLString);
//		if (!lABLStatementObj.mb_executeUpdate())
//		{
//			return false;
//		}

//		lABLConnection.mb_terminateStatement(lABLStatementObj);
		
	//}
  	

		
	return sendRetryReqObject(lProvRequest, pRetryProvReqObj);	
	
} //bool RequestRetrier :: addRetryRollBackParam(std::string pXMLReq, RetryProvReq *pRetryProvReqObj, int pJobId)

bool RequestRetrier :: sendRetryReqObject(ProvisioningRequest *pRequestObjPtr, RetryProvReq *pRetryProvReqObjPtr)
{
	BSSInfoMap::iterator 	lBSSInfoMapIter;       //!< BSSInfoMap iterator
	bool 					lIsReqRecvFound = false;
	bool			lFtpReqRecvFound = false;
	ABL_SmartPointer<AbstractDataMessage> lAbsDataMsg;
	
	lBSSInfoMapIter = xmlInputAdapterObjPtr->reqThrDetailMap.find(pRetryProvReqObjPtr->sessionId);
    if (lBSSInfoMapIter != xmlInputAdapterObjPtr->reqThrDetailMap.end())
    {
        reqReceiverPtr = dynamic_cast<RequestReceiver *>(lBSSInfoMapIter->second);
	if(NULL == reqReceiverPtr)
	{

			ftpReqReceiverPtr = dynamic_cast<FTPInputAdapter *>(lBSSInfoMapIter->second);
			if (NULL == ftpReqReceiverPtr)
			{
				PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "No FTP Session to send the Retry/Rollback Request", L_WARNING, GDIPtr)
				return false;
			}
			lFtpReqRecvFound = true;
	}
	PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "Found the Session to send the Retry/Rollback Request", L_INFO, GDIPtr)	
        lIsReqRecvFound = true;
    }
    else
    {
        for (lBSSInfoMapIter = xmlInputAdapterObjPtr->reqThrDetailMap.begin(); lBSSInfoMapIter != xmlInputAdapterObjPtr->reqThrDetailMap.end(); lBSSInfoMapIter++)
        {
            reqReceiverPtr = dynamic_cast<RequestReceiver *>(lBSSInfoMapIter->second);
	if(NULL == reqReceiverPtr)
	{
		ftpReqReceiverPtr = dynamic_cast<FTPInputAdapter *>(lBSSInfoMapIter->second);
                if (NULL == ftpReqReceiverPtr)
                {
			PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "No FTP User Session to send the Retry/Rollback Request", L_WARNING, GDIPtr)
               		return false;
                }
		if (pRetryProvReqObjPtr->userId == ftpReqReceiverPtr->userID)
            	{
			lFtpReqRecvFound = true;
                	lIsReqRecvFound = true;
                	PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "Found the User Logged in to send the Retry/Rollback Request", L_INFO, GDIPtr) 
                	break;
            }
	}
            if (pRetryProvReqObjPtr->userId == reqReceiverPtr->userID)
            {
                lIsReqRecvFound = true;
		PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "Found the User Logged in to send the Retry/Rollback Request", L_INFO, GDIPtr)	
                break;
            }
        }
    }
	if( lIsReqRecvFound )
	{
		if (lFtpReqRecvFound)
		{
			if (ftpReqReceiverPtr->reqProcQueue)
                	{
                        	lAbsDataMsg = pRequestObjPtr;
                        	ftpReqReceiverPtr->reqProcQueue->mb_put(lAbsDataMsg);
                        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Successfully forwarded the request to FTP Session", L_DEBUG1, GDIPtr)   
                        	return true;
                	}
			return false;
			
		}
		if (reqReceiverPtr->reqProcQueue)
		{
			lAbsDataMsg = pRequestObjPtr;
			reqReceiverPtr->reqProcQueue->mb_put(lAbsDataMsg);
			PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Successfully forwarded the request to Client Session", L_DEBUG1, GDIPtr)	
			return true;
		}
	}
	PREPARE_LOG_MSG(componentID, 0, 0, "2016", 0, "Unable to find the ReqProcessor Queue to forward the request", L_CRITICAL, GDIPtr)
	return false;	

}//RequestRetrier :: sendRetryReqObject

int RequestRetrier :: fetchRetryRequests()
{
	ABL_ResultSet	lABLResultSetObj;
	ABL_Statement	lABLStatementObj;
	int 			lCountOfRetryReq;
	ABL_Connection 	lABLConnection;          //!< ABL_Connection object to connect to database
	ABL_String 		lSQLQuery;
	JobIdMap::iterator lJobIdMapIter;
	try
	{
   		lABLConnection.mb_createConnection(GDIPtr->ablService);	
	
#ifdef ORACLE
		sprintf(_queryBuffer, "select count(1) from %s where process_flag in ('R', 'T', 'C') order by job_id", RETRY_REQUEST_TABLE);
#else
		sprintf(_queryBuffer, "select count(1) from %s where process_flag order by job_id", RETRY_REQUEST_TABLE);
#endif
		lSQLQuery = _queryBuffer;
	
		lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery); 
		lABLResultSetObj = lABLStatementObj.mb_executeQuery();
		lABLResultSetObj.mb_fetch();
	
		lCountOfRetryReq =  lABLResultSetObj.mb_getInt(1);

		lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
		lABLConnection.mb_terminateStatement(lABLStatementObj);
	}	
	catch (ABL_Exception &exception)
    {
    	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Unable to get request details from Database-Stage:1", L_WARNING, GDIPtr);
    	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, exception.mb_getMessage(), L_ERROR, GDIPtr);
    	return 0;
    }
	if (lCountOfRetryReq > 0)
	{
	#ifdef ORACLE
		sprintf(_queryBuffer, "select job_id, process_flag, session_id, user_id from %s where process_flag in ('R', 'T', 'C') order by job_id", RETRY_REQUEST_TABLE);
	#else
		sprintf(_queryBuffer, "select job_id, process_flag, session_id, user_id from %s where process_flag order by job_id", RETRY_REQUEST_TABLE);
	#endif
		lSQLQuery = _queryBuffer;
		
		try
		{	
			lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);
			lABLResultSetObj = lABLStatementObj.mb_executeQuery();
			while(lABLResultSetObj.mb_fetch())
			{
				retProvReqObjPtr = new RetryProvReq();
				retProvReqObjPtr->processFlag = lABLResultSetObj.mb_getString(2).mb_getSTLString().c_str()[0];
				retProvReqObjPtr->sessionId 	= lABLResultSetObj.mb_getInt(3);
				retProvReqObjPtr->userId		= lABLResultSetObj.mb_getInt(4);
				_jobIdMap[lABLResultSetObj.mb_getInt(1)] =	retProvReqObjPtr; 
			}
			lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
	    	lABLConnection.mb_terminateStatement(lABLStatementObj);
		}
		catch (ABL_Exception &exception)
    	{
			for (lJobIdMapIter = _jobIdMap.begin(); lJobIdMapIter != _jobIdMap.end(); lJobIdMapIter++)
        	{
            	delete lJobIdMapIter->second;
        	}
        	//! Clearing the JobIdMap.
        	_jobIdMap.clear();
	
        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Unable to get request details from Database-Stage:2", L_WARNING, GDIPtr);
        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, exception.mb_getMessage(), L_ERROR, GDIPtr);
        	return 0;
    	}
	}
	return lCountOfRetryReq;

}//RequestRetrier :: fetchRetryRequests

int RequestRetrier :: fetchScheduleRequests()
{
    ABL_ResultSet   lABLResultSetObj;
    ABL_Statement   lABLStatementObj;
    int             lCountOfScheduleReq;
    ABL_Connection  lABLConnection;          //!< ABL_Connection object to connect to database
    ABL_String      lSQLQuery;
	
	try
	{
    	lABLConnection.mb_createConnection(GDIPtr->ablService);
     
#ifdef ORACLE
 	   	sprintf(_queryBuffer, "select count(1) from %s where schedule_datetime <= sysdate order by job_id", SCHEDULE_REQUEST_TABLE);
#else
		sprintf(_queryBuffer, "select count(1) from %s where schedule_datetime <= sysdate order by job_id", SCHEDULE_REQUEST_TABLE);
#endif
    	lSQLQuery = _queryBuffer;

    	lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);
    	lABLResultSetObj = lABLStatementObj.mb_executeQuery();
    	lABLResultSetObj.mb_fetch();

    	lCountOfScheduleReq =  lABLResultSetObj.mb_getInt(1);

    	lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
    	lABLConnection.mb_terminateStatement(lABLStatementObj);
    }
	catch (ABL_Exception &exception)
    {
        PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Unable to get request details from Database-Stage:3", L_WARNING, GDIPtr);
        PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, exception.mb_getMessage(), L_ERROR, GDIPtr);
        return 0;
    }
    if (lCountOfScheduleReq > 0)
    {
	
#ifdef ORACLE
        sprintf(_queryBuffer, "select job_id from %s where schedule_datetime <= sysdate order by job_id", SCHEDULE_REQUEST_TABLE);
#else
        sprintf(_queryBuffer, "select job_id from %s where schedule_datetime <= sysdate order by job_id", SCHEDULE_REQUEST_TABLE);
#endif
        lSQLQuery = _queryBuffer;
		try
		{
        	lABLStatementObj = lABLConnection.mb_createStatement(lSQLQuery);
        	lABLResultSetObj = lABLStatementObj.mb_executeQuery();
        	while(lABLResultSetObj.mb_fetch())
        	{
            	_scheduleJobIdVec.push_back(lABLResultSetObj.mb_getInt(1));
        	}
			lABLStatementObj.mb_closeResultSet(lABLResultSetObj);
	    	lABLConnection.mb_terminateStatement(lABLStatementObj);
		}
		catch (ABL_Exception &exception)
    	{
			_scheduleJobIdVec.clear();
        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, "Unable to get request details from Database-Stage:4", L_WARNING, GDIPtr);
        	PREPARE_LOG_MSG(componentID, 0, 0, "0", 0, exception.mb_getMessage(), L_ERROR, GDIPtr);
        	return 0;
    	}
    }
    return lCountOfScheduleReq;

}//RequestRetrier :: fetchScheduleRequests

};//namespace SPS
