// ExpressionBase.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_EXPRESSIONBASE_H
#define INC_EXPRESSIONBASE_H

#include <ruleengine/framework/Types.h>
/*********************************************************************
#   File        :   ExpressionBase.h
#   Abstract    :   Implemetation of ExpressionBase Class
#   Date        :   01 May, 2007
#   Author(s)   :   Sabyasachi
#   Design      :  
#   References    
#   Module      :   RuleEngine
======================================================================
#   Revision History
======================================================================
#   SI          Edited by       Date        Area Edited
#
#   1           Sabyasachi      01-May-07   New Preparation
#
======================================================================
#   Libraries   :   
*********************************************************************/


namespace ruleengine
{
//Forward declaration of RuleEngine Class
class RuleEngine;

/////////////////////////////////////////////////////////////////////
//  
//  This is abstract base class provides method to evaluate Any 
//  type of Expression .
//  Usage:  Classes expecting type specific expressions should 
//          invoke this class (e.g Action class)
//
//////////////////////////////////////////////////////////////////////
//##ModelId=463179BA007D

class ExpressionBase
{
public:
    /////////////////////////////////////////////////////////////////////
    //
    //  Pure virtual method to make this class as abstract
    //  
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   
    //  RuleEngine*
    //              Which contains context specific operations and
    //              global variables.
    //  Returns:
    //  void
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=463179DD002E
    virtual void evaluateAny(RuleEngine *engine) = 0;

    /////////////////////////////////////////////////////////////////////
    //
    //  virtual destructor 
    //  
    ////////////////////////////////////////////////////////////////////
    virtual ~ExpressionBase()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
    }
    /////////////////////////////////////////////////////////////////////
    //
    //  virtual method to get InputType from the expression 
    //  should be overloaded in the derived classes of this class
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //  Returns:
    //
    //  std::string
    //      containing inputtype of the expression
    //      default is "*"
    //
    ////////////////////////////////////////////////////////////////////
    virtual std::string getInputType()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return "*";
    }

    /////////////////////////////////////////////////////////////////////
    //
    //  virtual method to get OutputType from the expression 
    //  should be overloaded in the derived classes of this class
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //  Returns:
    //
    //  std::string
    //      containing outputtype of the expression
    //      default is "*"
    //
    ////////////////////////////////////////////////////////////////////
    virtual std::string getOutputType()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return "*";
    }


};

};


#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/







