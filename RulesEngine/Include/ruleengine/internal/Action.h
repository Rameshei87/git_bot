// Action.h
//
//////////////////////////////////////////////////////////////////////
#ifndef    INC_ACTION_H
#define INC_ACTION_H

#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ExpressionBase.h>
/*********************************************************************
#   File        :   Action.h
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

class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
//Forward declaration
class RuleException;
class ParseContext;
class RuleEngine;

/////////////////////////////////////////////////////////////////////
//  
//  This class is instantiated when a <rule> tag encounters a 
//  <condition> and is evaluated to true. Then it evaluate the 
//  expression passes as an argument.
//
//////////////////////////////////////////////////////////////////////
//##ModelId=4630837903B9
class Action
{
  public:
    /////////////////////////////////////////////////////////////////////
    //  
    //  This constructs an Action from a DOMElement* pointing to a 
    //  <action> XML tag and a ParseContext ( The parse context is 
    //  passed on while creating _expression )
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  : 
    //  DOMElement* element
    //          This should point to the <action> tag. The constructor
    //          traverses the tag and creates _expression.
    //
    //  ParseContext *context
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=46383E42009C
    Action(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context);    

    /////////////////////////////////////////////////////////////////////
    //
    //  The destructor releases _expression.
    //  
    ////////////////////////////////////////////////////////////////////
    ~Action();

    /////////////////////////////////////////////////////////////////////
    //
    //  This funtion executes the action. It internally evaluates
    //  _expression.
    //  
    ////////////////////////////////////////////////////////////////////
    //
    //  Parameters  : 
    //  RuleEngine *engine
    //              This is passed on to _expression.execute()
    //              Action::execute does not use it
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=4630927B006D
    void execute(RuleEngine *engine);

  private:
    //##ModelId=4630922302FD
    /////////////////////////////////////////////////////////////////////
    //
    //  The action executes this expression.
    //  
    ////////////////////////////////////////////////////////////////////
    ExpressionBase *_expression;
};

};

#endif 
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

