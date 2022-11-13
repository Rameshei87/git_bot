// Condition.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include<ruleengine/internal/Condition.h>

/*********************************************************************
#   File        :   Condition.cpp
#   Abstract    :   Implemetation of Condition Class
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
*********************************************************************/
namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//
//  This constructs a Condition from a DOMElement* pointing to a 
//  <conditon> XML tag and a ParseContext ( which is paased on for 
//  creating a boolean expression )
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters :
//  DOMElement *element
//          This should point to the <condition> tag. The constructor
//          traverses the tag and creates _expression.
//
//  ParseContext *context
//
////////////////////////////////////////////////////////////////////
//##ModelId=46383EC6030D
Condition :: Condition(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context)
{
    RULEENGINE_STACK_TRACE_ENTRY
    XERCES_CPP_NAMESPACE::DOMElement *exprElem = XercesHelpers::getFirstChildElement((XERCES_CPP_NAMESPACE::DOMNode*)element);
    if(!exprElem)
    {
        RULEENGINE_STACK_TRACE_EXIT
        throw RuleException( "Condition not found" );
    }
    
    _expression = ExpressionFactory::getInstance().createExpression< Expression<bool> >(exprElem, context);
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//
//  The destructor releases _expression.
//  
////////////////////////////////////////////////////////////////////
Condition :: ~Condition()
{
    RULEENGINE_STACK_TRACE_ENTRY
    delete _expression;
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//
//  This funtion evaluates this condition. Internally it evaluates
//  _expression.
//  
////////////////////////////////////////////////////////////////////
//
//  Returns :
//  bool        
//              true - If _expression evaluates to true
//              false - If _expression evaluates to false
//
//  Parameters :
//  RuleEngine *engine
//              This is passed on to _expression.evaluate()
//              Condition::evaluate does not use it
//
////////////////////////////////////////////////////////////////////
//##ModelId=463092B803B9
bool Condition :: evaluate(RuleEngine *engine)
{
    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT
    return _expression->evaluate(engine);
}

};
