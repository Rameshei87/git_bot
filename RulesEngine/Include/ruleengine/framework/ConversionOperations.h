//  ConversionOperations.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_CONVERSIONOPERATIONS_H
#define INC_CONVERSIONOPERATIONS_H
#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>

/*********************************************************************
#    File        :  ConversionOperations.h
#    Abstract    :  Implementation of Conversion Operations.
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
// This class used for converts a string operand into int_64
// datatype and returns the result.
//
//////////////////////////////////////////////////////////////////////
class ConversionStringToInteger64 : 
    UnaryOperation<
                StringExpression
                > ,
    public Integer64Expression
{
public:

    typedef UnaryOperation<
                StringExpression
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
    ConversionStringToInteger64(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
    //  int_64
    //                          A value returned after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual int_64 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return atoi((ParentOperation::operand1->evaluate(engine)).c_str());
    }
};

class ConversionDateTimeToSeconds : 
    UnaryOperation<
                DateTimeExpression
                > ,
    public Integer64Expression
{
public:

    typedef UnaryOperation<
                DateTimeExpression
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
    ConversionDateTimeToSeconds(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
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
    //  int_64
    //                          A value returned after the operation.
    //
    //////////////////////////////////////////////////////////////////////
    virtual int_64 evaluate(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (ParentOperation::operand1->evaluate(engine)).mb_getJulianDateTime();
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

