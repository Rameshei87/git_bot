// LogicalOperations.h
//
//////////////////////////////////////////////////////////////////////

#ifndef INC_LOGICALOPERATIONS_H
#define INC_LOGICALOPERATIONS_H

#include <map>
#include <ruleengine/framework/BinaryOperation.h>
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>

/*********************************************************************
#    File        :  LogicalOperations.h
#    Abstract    :  Implementation of LogicalOperations.
#    Date        :  01 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI        Edited by        Date            Area Edited
#
#     1        Sangeeta     04-May-2007       New Preparation
#
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/
//Forward declaration
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{

// Forward Declaration
class ExpressionCreator;
class ParseContext;
class RuleEngine;

////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for logical And operation on two values
// of boolean datatype and returns a boolean value.
//
///////////////////////////////////////////////////////////////////////////
class And : 
    BinaryOperation<
                BooleanExpression, 
                BooleanExpression 
                > ,
    public BooleanExpression
{
public:
    typedef BinaryOperation<
                    BooleanExpression, 
                    BooleanExpression 
                    > ParentOperation;
    
    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //    The class inherits from BinaryOperation and Expression class.     
    //
    ///////////////////////////////////////////////////////////////////////
    //
    //    Paramters :
    //
    //    DOMElement* element
    //                              This is the reference to the operation of 
    //                              DOMElement type in the XML configuration
    //                              file.
    //    ParseContext* context
    //                              This is a reference to the class 
    //                              ParseContext is used to map variables      
    //
    ///////////////////////////////////////////////////////////////////////
    And(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :    
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type based 
    //                          on the operands
    //
    //////////////////////////////////////////////////////////////////////
    virtual bool evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) && (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for logical Or operation on two values
// of boolean datatype and returns a boolean value.
//
//////////////////////////////////////////////////////////////////////////
class Or : 
    BinaryOperation<
                BooleanExpression,
                BooleanExpression 
                > ,
    public BooleanExpression
{
public:

    typedef BinaryOperation<
                BooleanExpression, 
                BooleanExpression 
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //    The class inherits from BinaryOperation and Expression class.     
    //
    ///////////////////////////////////////////////////////////////////////
    //
    //    Paramters :
    //
    //    DOMElement* element
    //                              This is the reference to the operation of 
    //                              DOMElement type in the XML configuration
    //                              file.
    //    ParseContext* context
    //                              This is a reference to the class 
    //                              ParseContext is used to map variables
    //
    ///////////////////////////////////////////////////////////////////////
    Or(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        :  ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :    
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type based 
    //                          on the operands
    //
    //////////////////////////////////////////////////////////////////////
    virtual bool evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return ( ParentOperation::operand1->evaluate(engine)) || ( ParentOperation::operand2->evaluate(engine));
    }
};

////////////////////////////////////////////////////////////////////////// 
//
//This is a templatized class used for logical Not operation on two values
// of boolean datatype and returns a boolean value.
//
//////////////////////////////////////////////////////////////////////////
class Not
    : UnaryOperation<
                BooleanExpression 
                > ,
      public BooleanExpression
{
public:

    typedef UnaryOperation<
                BooleanExpression 
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //    The class inherits from BinaryOperation and Expression class.     
    //
    ///////////////////////////////////////////////////////////////////////
    //
    //    Paramters :
    //
    //    DOMElement* element
    //                              This is the reference to the operation of 
    //                              DOMElement type in the XML configuration
    //                              file.
    //    ParseContext* context
    //                              This is a reference to the class 
    //                              ParseContext is used to map variables      
    //
    ///////////////////////////////////////////////////////////////////////
    Not(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :    
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type based 
    //                          on the operands
    //
    //////////////////////////////////////////////////////////////////////
    virtual bool evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return !(ParentOperation::operand1->evaluate(engine));
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
