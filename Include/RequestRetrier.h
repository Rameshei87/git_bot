/*----------------------------------------------------------------------------*
*
* Design Reference      : MP_TECNOTREE_SPS_REQUESTRETRIER_LLD_A.doc
*
*-----------------------------------------------------------------------------*
* * * * *
* * * * *            Revision History
* * * * *
*-----------------------------------------------------------------------------*
* SI  | Edited by        | Date          |  Area Edited
------------------------------------------------------------------------------*
*     |                  |               |
*     |                  |               |
*     |                  |               |
*----------------------------------------------------------------------------*/

/** @file RequestRetrier.h
    @brief Common retry request handler component.

*/

#ifndef INC_REQUEST_RETRIER_H
#define INC_REQUEST_RETRIER_H

#include <CommonDefs.h>
#include <RequestReceiver.h>
#include <RequestParser.h>
#include <FTPInputAdapter.h>

//#define RETRY_REQUEST_PICKING_TIME 	60					//!< Time interval in seconds for fetching the requests from the t_retry_provisioning_request table.
#define SCHEDULE_REQUEST_PICKING_TIME 	2				//!< Time interval in seconds for fetching the requests from the t_retry_provisioning_request table.
#define RETRY_ROLLBACK_GLOBAL_KEY 	"RRT"				//!< Global Paramater Key whose value will indicate whether the request is RETRY/ROLLBACK/CALLBACK.
#define OLD_REQUEST_KEY				"OLD"				//!< Global Parameter Key whose value will indicate whether the request is an old request or not.
#define OLD_REQUEST_VALUE			"Y"					//!< This value indicates its an old request.
#define RETRY_REQ_GPARAM_VALUE		"T"					//!< This value indicates, the request is a RETRY request.
#define ROLLBACK_REQ_GPARAM_VALUE	"R"					//!< This value indicates, the request is a ROLLBACK request.
#define CALLBACK_REQ_GPARAM_VALUE	"C"					//!< This value inicates, the request is a CALLBACK request.
#define ASYNCHRONOUS_REQUEST_TYPE	'A'					//!< Value for the request type
#define PREVIOUS_REQ_TYPE			"PRT"				//!< Global Key to indicate the Previous Request Type.
#define SQL_QUERY_BUFFER_SIZE		5120				//!< Maximumbuffer size for SQL query.
namespace SPS			
{
	
	
	/** @class RetryProvReq
        @brief Class to store the information from the t_retry_provisioning_request for each job_id.

    */	
	class RetryProvReq
	{
		public:
			char	processFlag;						//!< Stores the value from process_flag field of t_retry_provisioning_request.
			long 	sessionId;							//!< Stores the value from session_id field of t_retry_provisioning_request.
			uint_32 	userId;								//!< Stores the value from user_id field of t_retry_provisioning_request.
			
	};
	
	//! JobIdMap with the job_id as the key and pointer to RetryProvReq object as the value.	
	typedef std::map<int, RetryProvReq *> JobIdMap;

	//! JobIdVector with the job_id as the key.	
	typedef std::vector<unsigned long > JobIdVector;
	
	 /** @class RequestRetrier
     	 @brief This class defines the member functions to fetch and process the requests populated in the t_retry_provisioning_request table..

    */ 
	class FTPInputAdapter;
	class RequestRetrier : public AbstractComponent
	{
		public:
			
			/** @fn Start
            	@param  pGDIPtr - Pointer to the GlobalDataInfo object.
            	@param  pDiffParameterPtr - Pointer to the AbstractBaseDat object.
            	@brief This is public function which will be called by the XMLInputAdapter for starting the initiating the Request-Retrier component.

        	*/	
			virtual bool  Start(GlobalDataInfo *pGDIPtr, AbstractBaseData *pDiffParameterPtr = NULL);
			
			/** @fn StartProcess
                @brief This is public function which will be called from the Start function of the Request-Retrier component.
				
				This will start the Request-Retrier component and then process the requests in t_retry_provisioning_request.		
            */
			bool StartProcess();
			RequestRetrier();
			~RequestRetrier();
			
			XMLInputAdapter *xmlInputAdapterObjPtr;		//!< Pointer to the XMLInputAdapter. The XMLInputAdapter will store its pointer after creating the RequestRetrier object.
			
			void  WriteLogs(char *pLog);			
		private:
			
			/** @fn initialize
                @param  pGDIPtr - Pointer to the GlobalDataInfo object.
                @brief This function will obtain the ABL_Service object from the GlobalDataInfo and establish a connection to the data base.

            */
			bool initialize(GlobalDataInfo * &GDI);

			/** @fn fetchRetryRequests
				@return It returns the number of requests fetched from t_retry_provisioning_table.
                @brief This function will fetch the requests from t_retry_provisioning_request table and store it into JobIdMap.

            */
			int fetchRetryRequests();
			int fetchScheduleRequests();

			/** @fn fetchXMLRequest
                @brief This function will fetch the xml request string from t_provisioning_request for the processing job_id.

            */
			void fetchXMLRequest();
			void fetchScheduleXMLRequest();
			
			/** @fn addRetryRollBackParam
				@param pXMLReq - The XML request.
				@param pRetryProvReqObj - The RetryProvReq object pointer.
				@param pJobId - The job id for which the requests are processed.
                @brief This function will modify the xml request string fetched from the t_provisioning_request to add extra parameters. It also changes the requestType to asynchronous.

            */
			bool addRetryRollBackParam(std::string pXMLReq, RetryProvReq *pRetryProvReqObj, int pJobId);

			/** @fn sendRetryReqObject
                @param pRequestObjPtr - The pointer to the request object that should be inserted into the data queue.
                @param pRetryProvReqObjPtr - The pointer to the RetryProvReq.
                @brief This function will identify the RequestProcessor's input data queue to which the Request object has to be inserted and then sends it to the corresponding RequestProcessor through its data queue. 
			*/
			bool sendRetryReqObject(ProvisioningRequest *pRequestObjPtr, RetryProvReq *pRetryProvReqObjPtr);
			bool sendScheduleRequest(std::string pXMLReq, unsigned long pJobId, uint_32 pUserID, uint_32 pSessionID);

			RequestParser           *reqParserPtr; 			//!< XML Request Parser Pointer.
			RetryProvReq			*retProvReqObjPtr;		//!< RetryProvReq object Pointer.
			RequestReceiver         *reqReceiverPtr;        //!< Pointer to RequestReceiver.
			FTPInputAdapter		*ftpReqReceiverPtr;
			JobIdMap _jobIdMap;								//!< Global map to store the RetryProvReq against job_id's.	
			JobIdVector 			_scheduleJobIdVec;		//!< Vector to store the schedule jobs	
			char _queryBuffer[1024];						//!< Character array to store the sql query.
			uint_32 _retryInterval;							//!< Stores the retry interval

	};
};

#endif

