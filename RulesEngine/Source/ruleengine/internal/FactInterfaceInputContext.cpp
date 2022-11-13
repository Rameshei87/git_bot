#include <ruleengine/internal/FactInterfaceInputContext.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>

#include <typeinfo>
using namespace ruleengine;
//using namespace SPS;

/*********************************************************************
#   File        :   FactInterfaceInputContext.cpp
#   Abstract    :   provides operations that use the ruleengine to get 
#                   relevant data
#   Date        :   
#   Author(s)   :   Sumit/Sangeeta
#   Design      :   
#   References    
#   Module      :   common
======================================================================
#   Revision History
======================================================================
#   SI  Edited by    Date              Area Edited
#
#   2    Sumit        27 Sept,2007      Code Restructuring
#   3    Sumit        22 Oct ,07        moved the handover operation to 
#                                       XMLConveter.cpp
#   4    sumit        22 Oct 07         moved HandoverNewTo to 
#                                       XmlConverter.cpp
#                                       moved this  file from interface 
#                                       to common
#   5    Sumit        14-03-07          removed code to source file.
======================================================================
#   Libraries   :    xerces, ruleengine
*********************************************************************/


/////////////////////////////////////////////////////////////////////
//
//  Class memeber of FactInterfaceInputContext
//  This constructs the input for encoding.
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters :
//  FactInterface inputfactInterface
//                This set the inputs for encoding and  set the
//                empty to false as the FactInterface is recieved.
//
//  Exceptions :     
//      throw() empty list
//  
//
////////////////////////////////////////////////////////////////////
FactInterfaceInputContext::FactInterfaceInputContext(SPS::ProvisioningRequest *pReq) throw():req(pReq),
                                                    _empty(false)
{
    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT
}

//////////////////////////////////////////////////////////////////////////
//
//  Class memeber of FactInterfaceInputContext
//  This function returns true until the discardInput() function is called.
//  
/////////////////////////////////////////////////////////////////////////
//  
//  Returns :
//  bool
//            It returns true if input is received from the FactInterface.
//
//  Exceptions :     
//      throw() empty list
//  
//
/////////////////////////////////////////////////////////////////////////
bool FactInterfaceInputContext::isEmpty()throw()
{
    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT
    return _empty;
}

bool FactInterfaceInputContext::AddNewRequest(SPS::ProvisioningRequest *pReq)throw()
{
    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT
    req = pReq;
	physicalNEID = 0;
	conditionResult = true;
    return true;
}

/////////////////////////////////////////////////////////////////////
//
//  Class memeber of FactInterfaceInputContext
//  This function is called after encoding to discard the input in 
//  the FactInterface. The value of the empty is set to true.
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters :
//  FactInterface inputfactInterface
//                    This set the inputs for encoding and the set
//                    empty to false as FactInterface is recieved.
//
//  Exceptions :     
//      throw() empty list
//  
//
////////////////////////////////////////////////////////////////////
void FactInterfaceInputContext::discardInput()throw()
{
    RULEENGINE_STACK_TRACE_ENTRY
    _empty = true;
    RULEENGINE_STACK_TRACE_EXIT
}

void FactInterfaceInputContext::addInput()throw()
{
    RULEENGINE_STACK_TRACE_ENTRY
    _empty = false;
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  Templatized class for evaluating an expression
//
//  This class gets the attribute fact eg <get-integer64-fact>
//  node in the XML document and determines the inputs.
//  
////////////////////////////////////////////////////////////////////
template<class T>
class GetFactOperation : public ruleengine::Expression <T>
{
private:

    /////////////////////////////////////////////////////////////////////
    //  uint_32 factId  for which the getfact is done
    /////////////////////////////////////////////////////////////////////
    std::string variableName;    
    std::string commandAction;    

public:

    /////////////////////////////////////////////////////////////////////
    //
    //  This constructor gets the fact attribute eg <get-integer64
    //  -fact> node in the XML document and sets _fact.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters :
    //      DOMElement* element
    //                  This points to <get-integer64-fact> node in the XML
    //                  document.
    //      ParseContext* context
    //                  This context provides the input.
    //
    //  Exceptions :     
    //      throws empty list (ie no exceptions)
    //  
    ////////////////////////////////////////////////////////////////////
    GetFactOperation(XERCES_CPP_NAMESPACE::DOMElement* element, ruleengine::ParseContext* context)
                                                                                throw()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        variableName = ruleengine::XercesHelpers::getStringAttributeValue(element,"name");
        commandAction = ruleengine::XercesHelpers::getStringAttributeValue(element,"action");
        RULEENGINE_STACK_TRACE_EXIT
    }

    /////////////////////////////////////////////////////////////////////
    //
    //  This function returns the value of the input in the Fact-
    //  Interface.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters :
    //  RuleEngine *engine
    //            This gets the input context
    //
    //  Returns:
    //  T
    //            It is the data type of the input ie the data type of the 
    //            the data in the FactInterface. The value of the 
    //          input is then returned.
    //
    //  Exceptions :     
    //      throws ruleengine::RuleException
    //  
    ////////////////////////////////////////////////////////////////////
    virtual T evaluate(ruleengine::RuleEngine *engine)throw(ruleengine::RuleException)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        FactInterfaceInputContext *context = dynamic_cast<FactInterfaceInputContext*>(engine->getInputContext());
        if(NULL == context)
        {
			std::cout<<"Dynamic Cast failed in GetFactOperation::evaluate"<<std::endl;
            RULEENGINE_STACK_TRACE_EXIT
            throw ruleengine::RuleException("Dynamic Cast failed in GetFactOperation::evaluate");
        }

		if(strlen(commandAction.c_str()))
			return context->req->GetLocalParamValue(commandAction, variableName);
		else
			return context->req->GetGlobalParamValue(variableName);
    }
};

class SetSwitchNum : public VoidExpression, UnaryOperation<Integer32Expression>
{
	public:
	 SetSwitchNum(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context) 
        : UnaryOperation<Integer32Expression>( element, context )
    {
    }
  void evaluate(RuleEngine *engine)
  {
	FactInterfaceInputContext *context = dynamic_cast<FactInterfaceInputContext*>(engine->getInputContext());
        if(NULL == context)
        {
			std::cout<<"Dynamic Cast failed in GetFactOperation::evaluate";
            RULEENGINE_STACK_TRACE_EXIT
            throw ruleengine::RuleException("Dynamic Cast failed in GetFactOperation::evaluate");
        }

	context->physicalNEID = operand1->evaluate(engine);
  }
};

class ExecuteCondition : public VoidExpression, UnaryOperation<BooleanExpression>
{
	public:
	 ExecuteCondition(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context) 
        : UnaryOperation<BooleanExpression>( element, context )
    {
    }
  void evaluate(RuleEngine *engine)
  {
	FactInterfaceInputContext *context = dynamic_cast<FactInterfaceInputContext*>(engine->getInputContext());
        if(NULL == context)
        {
			std::cout<<"Dynamic Cast failed in GetFactOperation::evaluate";
            RULEENGINE_STACK_TRACE_EXIT
            throw ruleengine::RuleException("Dynamic Cast failed in GetFactOperation::evaluate");
        }

	context->conditionResult = operand1->evaluate(engine);
  }
};

class HandoverNewTo : public ruleengine::VoidExpression
{
    //will hold the packet id to which the input is handed over .
    ruleengine::uint_32 _id;

public:

    /////////////////////////////////////////////////////////////////////
    //
    //  constructor method gets the _id value
    //
    /////////////////////////////////////////////////////////////////////
    HandoverNewTo(XERCES_CPP_NAMESPACE::DOMElement* element, ruleengine::ParseContext* context)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _id = ruleengine::XercesHelpers::getUint32AttributeValue( element, "packet" );
        RULEENGINE_STACK_TRACE_EXIT
    }

    /////////////////////////////////////////////////////////////////////
    //
    //  evaluate method that does the handover.
    //
    /////////////////////////////////////////////////////////////////////
    void evaluate(ruleengine::RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        FactInterfaceInputContext *inputContext = (static_cast<FactInterfaceInputContext* >(engine->getInputContext()));
        engine->handOver(_id, inputContext, NULL);
        RULEENGINE_STACK_TRACE_EXIT
    }

};

class EnrichParameter : public VoidExpression, UnaryOperation<StringExpression>
{
    public:
     EnrichParameter(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : UnaryOperation<StringExpression>( element, context )
    {
    }
  void evaluate(RuleEngine *engine)
  {
	char lParamValueString[1024];
	char *lTempParamVal;
	char lParam[16];
	char lValue[64];
	typedef std::map<std::string, std::string> ParamValueMap;
	ParamValueMap lParamValMap;
	int lIndex;

	FactInterfaceInputContext *context = dynamic_cast<FactInterfaceInputContext*>(engine->getInputContext());
        if(NULL == context)
        {
            std::cout<<"Dynamic Cast failed in GetFactOperation::evaluate";
            RULEENGINE_STACK_TRACE_EXIT
            throw ruleengine::RuleException("Dynamic Cast failed in GetFactOperation::evaluate");
        }

    std::string value = operand1->evaluate(engine);
	strcpy(lParamValueString, value.c_str());
	
	lTempParamVal = strtok(lParamValueString, "|");
	
	  while(NULL != lTempParamVal)
	  {
		memset(lParam, 0, sizeof(lParam));
		memset(lValue, 0, sizeof(lValue));
		for (lIndex = 0; lIndex < strlen(lTempParamVal); lIndex++)
		{
		  if ('=' == lTempParamVal[lIndex])
			break;
		}
		strncpy(lParam, lTempParamVal, lIndex);
		strcat(lParam, "\0");
		strcpy(lValue, lTempParamVal + lIndex +1);
		lParamValMap[lParam] = lValue;
		lTempParamVal = strtok(NULL, "|");
	  }
	   ParamValueMap::iterator lPIter;
	for (lPIter = lParamValMap.begin(); lPIter != lParamValMap.end(); lPIter++)
	{
		context->req->AddGlobalParam(lPIter->first, lPIter->second);

	}
  }
};

//////////////////////////////////////////////////////////////////////////
//
//  This funtion registers Operations in the ExpressionFactory.
//
//  This function should be called only once in the lifetime of an
//  applicaton.
//
///////////////////////////////////////////////////////////////////////////
//  
//  Parameters:
//      None
//
//  Exceptions :     
//       std::bad_alloc
//  
//
////////////////////////////////////////////////////////////////////
void FactInterfaceInputContext::initialize()throw(std::bad_alloc)
{
    RULEENGINE_STACK_TRACE_ENTRY
    ruleengine::ExpressionFactory* factory = &ruleengine::ExpressionFactory::getInstance();
    
    factory->registerExpression( "handover-new-to", new PrimitiveCreator<HandoverNewTo>() );
    factory->registerExpression( "get-parameter", new ruleengine::PrimitiveCreator<GetFactOperation<std::string> >() );
    factory->registerExpression( "set-switchno", new ruleengine::PrimitiveCreator<SetSwitchNum>() );
    factory->registerExpression( "enrich-parameter", new ruleengine::PrimitiveCreator<EnrichParameter>() );
	factory->registerExpression( "execute_condition", new ruleengine::PrimitiveCreator<ExecuteCondition>() );
    
    RULEENGINE_STACK_TRACE_EXIT
}
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
