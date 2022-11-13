// ComparisonOperations.h
//
//////////////////////////////////////////////////////////////////////

#ifndef INC_COMPARISONOPERATIONS_H
#define INC_COMPARISONOPERATIONS_H

#include <map>
#include <string>
#include <ruleengine/framework/BinaryOperation.h>
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>
/**********************************************************************
#    File        :  ComparisonOperations.h
#    Abstract    :  Implementation of ComparisonOperations.
#    Date        :  01 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
=======================================================================
#    Revision History
=======================================================================
#    SI        Edited by        Date            Area Edited
#
#     1           Sangeeta     04-May-2007       New Preparation
#
#
=======================================================================
#    Libraries   :  xerces
**********************************************************************/

// Forward Declaration
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
// Forward Declaration
class RuleEngine;
class ParseContext;
class ExpressionCreator;

////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class used to compare equality on two values 
// of different datatypes and returns a boolean value.
//
///////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class Equal : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:

    typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
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
    Equal(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return ((ParentOperation::operand1->evaluate(engine)) == (ParentOperation::operand2->evaluate(engine)));
    }
};


////////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class used to compare non-equality on two values
// of different datatypes and returns boolean value.
//
///////////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class NotEqual : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:

    typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //      The class inherits from BinaryOperation and Expression class.     
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
    NotEqual(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return (ParentOperation::operand1->evaluate(engine)) != (ParentOperation::operand2->evaluate(engine));
    }
};

////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class do the less than comparison on two values
// of different datatypes and returns boolean value.
//
///////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class LessThan : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:

    typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //      The class inherits from BinaryOperation and Expression class.     
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
    LessThan(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return (ParentOperation::operand1->evaluate(engine)) < (ParentOperation::operand2->evaluate(engine));
    }
};

/////////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class do the greater than comparison on two values
// of different datatypes and returns boolean value.
//
////////////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class GreaterThan : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:
    
    typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
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
    GreaterThan(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return (ParentOperation::operand1->evaluate(engine)) > (ParentOperation::operand2->evaluate(engine));
    }
};

/////////////////////////////////////////////////////////////////////////////////
//
// This is a templatized class do the less than equality comparison on two values
// of different datatypes and returns boolean value.
//
////////////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class LessThanEqual : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:

     typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //      The class inherits from BinaryOperation and Expression class.     
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
    LessThanEqual(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return (ParentOperation::operand1->evaluate(engine)) <= (ParentOperation::operand2->evaluate(engine));
    }
};

///////////////////////////////////////////////////////////////////////////////// 
//
//  This is a templatized class do the greater than equality comparison on two 
//  values of different datatypes and returns boolean value.
//
////////////////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type>
class GreaterThanEqual : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public BooleanExpression
{
public:

     typedef BinaryOperation<
                Expression<Operand1Type>,
                Expression<Operand2Type>
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //      The class inherits from BinaryOperation and Expression class.     
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
    GreaterThanEqual(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
        return (ParentOperation::operand1->evaluate(engine)) >= (ParentOperation::operand2->evaluate(engine));
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
