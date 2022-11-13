// Condition.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_CONDITION_H
#define INC_CONDITION_H

#include <ruleengine/framework/Expression.h>
#include <string>
/*********************************************************************
#   File        :   Condition.h
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
//Forward declaration
class RuleException;
class ParseContext;
class RuleEngine;

/////////////////////////////////////////////////////////////////////
//  
//  The class is constructed from the <condition> XML tag and it 
//  evaluates the boolean value of the expression in its child node.
//  It evaluates the <action> XML tag if the condition is evaluated 
//  to true.  
//  
//////////////////////////////////////////////////////////////////////
//##ModelId=4630832F0128
class Condition
{
  public:

    /////////////////////////////////////////////////////////////////////
    //
    //  This constructs a Condition from a DOMElement* pointing to a 
    //  <condition> XML tag and a ParseContext ( which is pased on for 
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
    //  Exceptions:
    //
    //  RuleException
    //          If <condition> tag does not contain a boolean expression
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=46383EC6030D
    Condition(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context);
    
    /////////////////////////////////////////////////////////////////////
    //
    //  The destructor releases _expression.
    //  
    ////////////////////////////////////////////////////////////////////
    ~Condition();


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
    bool evaluate(RuleEngine *engine);
    
    
  private:
    //##ModelId=463089C802EE
    /////////////////////////////////////////////////////////////////////
    //
    //  The condition evaluates this expression.
    //  
    ////////////////////////////////////////////////////////////////////
    BooleanExpression *_expression;
};

};


#endif 
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

