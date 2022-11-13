// ArithmeticOperations.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_ARITHMETICOPERATIONS_H
#define INC_ARITHMETICOPERATIONS_H
//#include <math.h>
#include <map>
#include <ruleengine/framework/BinaryOperation.h>
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>

/*********************************************************************
#    File        :  ArithmeticOperations.h
#    Abstract    :  Implementation of ArithmeticOperations.
#    Date        :  01 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date              Area Edited
#
#    1    Sangeeta     04-May-2007       New Preparation
#
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
//Forward declaration
class ExpressionCreator;
class ParseContext;
class RuleEngine;

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for addition on two operands of 
// different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Add : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Add(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evluate the value of the addition of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) + (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for subtraction on two operands 
// of different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Subtract : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Subtract(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of subtraction of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) - (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for multiplication on two operands 
// of different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Multiply : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Multiply(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of multiplication of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) * (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for division on two operands 
// of different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Divide : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Divide(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of division of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) / (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for modulo operation on two operands 
// of different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Modulo : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Modulo(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evaluate the value of modulation of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :    
    //
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)) % (ParentOperation::operand2->evaluate(engine));
    }
};

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for exponential operation on two 
// operands of different datatypes and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class Operand1Type,class Operand2Type,class ReturnType>
class Power : 
    BinaryOperation<
                Expression<Operand1Type>, 
                Expression<Operand2Type> 
                > ,
    public Expression<ReturnType>
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
    Power(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evluate the value of the exponential operation of two expressions.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, based 
    //                          on the operands after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        ReturnType tmp=1;
        for(int_64 i=0;i<abs(ParentOperation::operand2->evaluate(engine));i++)
        {
            tmp=tmp*(ParentOperation::operand1->evaluate(engine));
        }
        RULEENGINE_STACK_TRACE_EXIT
        if((ParentOperation::operand2->evaluate(engine))>0)
            return tmp;
        else if((ParentOperation::operand2->evaluate(engine))<0)
            return (1/tmp);
        else if((ParentOperation::operand2->evaluate(engine)) == 0)
            return (ReturnType)1;
        //return (ReturnType)pow((float)(ParentOperation::operand1->evaluate(engine)),(int)(ParentOperation::operand2->evaluate(engine)));
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
