// Expression.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_EXPRESSION_H
#define INC_EXPRESSION_H
#include <string>
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/ExpressionBase.h>
#include <ABL_DateTime.h>
#include <ABL_Date.h>

/*********************************************************************
#   File        :   Expression.h
#   Abstract    :   Implemetation of Expression Class
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
/////////////////////////////////////////////////////////////////////
//  
//  This is an abstract  templatized base class derived from 
//  ExpressionBase class provides method to evaluate Any type of 
//  Expressions and Type specific Expressions.
//  
//////////////////////////////////////////////////////////////////////

//##ModelId=4630843A02BF
template <class Type>
class Expression : public ExpressionBase
{
public:
    /////////////////////////////////////////////////////////////////////
    //
    //  Pure virtual method to make this class an Abstract class
    //  this method should be overridden in derived classes to evaluate
    //  type specific Expressions.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //
    //  RuleEngine*
    //     
    //
    //  Returns:
    //
    //  Template Type
    //      Type of the newly evaluated Expression
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=463085460213
    virtual Type evaluate(RuleEngine *engine) = 0;

    /////////////////////////////////////////////////////////////////////
    //
    //  overridden virtual method to evaluate Any Type of expression 
    //  invokes evaluate method for type specific Expression.
    //
    //  See ExpressionBase.h
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //  
    //  RuleEngine*
    //
    ////////////////////////////////////////////////////////////////////
    virtual void evaluateAny(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
	    evaluate(engine);
        RULEENGINE_STACK_TRACE_EXIT
    }

    
};
// Synonyms for Different Expression Type
typedef Expression<bool> BooleanExpression;
typedef Expression<char> CharacterExpression;
typedef Expression<int_16> Integer16Expression;
typedef Expression<int_32> Integer32Expression;
typedef Expression<int_64> Integer64Expression;
typedef Expression<uint_16> UnsignedInteger16Expression;
typedef Expression<uint_32> UnsignedInteger32Expression;
typedef Expression<uint_64> UnsignedInteger64Expression;
typedef Expression<double> DoubleExpression;
typedef Expression<float> FloatExpression;
typedef Expression<std::string> StringExpression;
typedef Expression<void> VoidExpression;
typedef Expression<ABL_DateTime> DateTimeExpression;
typedef Expression<ABL_Date> DateExpression;

};

#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

