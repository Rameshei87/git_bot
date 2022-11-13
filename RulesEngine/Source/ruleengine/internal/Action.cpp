//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/internal/Action.h>
/*********************************************************************
#   File        :   Action.cpp
#   Abstract    :   Implemetation of Action Class
#   Date        :   04 May, 2007
#   Author(s)   :   Sangeeta
#   Design      :  
#   References    
#   Module      :   RuleEngine
======================================================================
#   Revision History
======================================================================
#   SI          Edited by       Date        Area Edited
#
======================================================================
#   Libraries   :  xerces 
**********************************************************************/
namespace ruleengine
{

/////////////////////////////////////////////////////////////////////
//
//  This constructs an Action from a DOMElement* pointing to a 
//  <action> XML tag and a ParseContext ( The parse context is passed
//  passed on while creating _expression )
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters  :   
//  DOMElement *element
//          This should point to the <action> tag. The constructor
//          traverses the tag and creates _expression.
//
//  ParseContext *context
//
////////////////////////////////////////////////////////////////////
//##ModelId=46383E42009C
Action :: Action(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context)
{
    RULEENGINE_STACK_TRACE_ENTRY
    XERCES_CPP_NAMESPACE::DOMElement *exprElem = XercesHelpers::getFirstChildElement(element);

    if(!exprElem)
    {
        RULEENGINE_STACK_TRACE_EXIT
        throw RuleException("Action not found");
    }
    
    _expression = ExpressionFactory::getInstance().createExpression< ExpressionBase >(exprElem, context);
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  The destructor releases _expression.
//  
////////////////////////////////////////////////////////////////////
Action :: ~Action()
{
    RULEENGINE_STACK_TRACE_ENTRY
    delete _expression;
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  This funtion executes the action. It internally evaluates
//  _expression.
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters  : 
//  RuleEngine *engine
//                        This is passed on to _expression.execute()
//                        Action::execute does not use it
//
////////////////////////////////////////////////////////////////////
//##ModelId=4630927B006D
void Action :: execute(RuleEngine *engine)
{
    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT
    return _expression->evaluateAny(engine);
}
};
