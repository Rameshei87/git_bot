// CastOperations.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_CASTOPERATIONS_H
#define INC_CASTOPERATIONS_H
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>

/*********************************************************************
#    File        :  CastOperations.h
#    Abstract    :  Implementation of Cast Operations.
#    Date        :  03 Sep, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date              Area Edited
#
#    1    Sangeeta   08 Sep, 2007       New preparation
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
//Forward declaration
class ParseContext;
class RuleEngine;

//////////////////////////////////////////////////////////////////////
//
// This is a templatized class used for casting an operand into
// another datatype and returns the result.
//
//////////////////////////////////////////////////////////////////////
template<class OperandType,class ReturnType>
class Cast : 
    UnaryOperation<
                Expression<OperandType>
                > ,
    public Expression<ReturnType>
{
public:

    typedef UnaryOperation<
                Expression<OperandType>
                > ParentOperation;

    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    //    The class inherits from UaryOperation and Expression class.     
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
    Cast(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
        : ParentOperation( element, context )
    {
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  This function is inherited from Expression class and is used to 
    //  evluate the value of the casting of an expression.
    //
    //////////////////////////////////////////////////////////////////////
    //
    //  Parameters :     
    //  RuleEngine *engine
    //
    //  Returns :    
    //  ReturnType
    //                          A value, can be of any data type, is 
    //                          returned after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual ReturnType evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ReturnType)(ParentOperation::operand1->evaluate(engine));
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

