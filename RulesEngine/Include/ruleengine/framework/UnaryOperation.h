// UnaryOperation.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_UNARYOPERATION_H
#define INC_UNARYOPERATION_H

#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/framework/Types.h>
#include <xercesc/dom/DOMAttr.hpp>
/*********************************************************************
#   File        :   UnaryOperation.h
#   Abstract    :   Implemetation of UnaryOperation Class
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
======================================================================
#   Libraries   :   xerces 
*********************************************************************/
namespace ruleengine
{
//Forward Declaration of ParseContext class
class ParseContext;
/////////////////////////////////////////////////////////////////////
//  
//  This is class to get appropriate operands required for an 
//  Unary Operation
//  Usage : Whenever evaluate method on Expression Object 
//          or its derived object is invoked
//  
//////////////////////////////////////////////////////////////////////
//##ModelId=4631AA110213
template <class OP1>
class UnaryOperation 
{
protected:
    //##ModelId=4631ABD0003E
    OP1 *operand1;
public:
    /////////////////////////////////////////////////////////////////////
    //  Constructor method to get 1 unary operand from DOMElement
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Pointer to DOMElement which Contains Operation
    //                  Pointer to ParseContext
    //  Algorithm   :
    //                  1>  Traverse all the childnodes of the DOMElement 
    //                  2>  Check childnode type is of ELEMENT_NODE type and 
    //                              Childnode is not NULL
    //                  3>  get the operand from ExpressionFactory
    //                      depending on the no of Operand required
    //                  4>  if No. of operands is not 1 
    //                          throw exception
    ////////////////////////////////////////////////////////////////////
    //##ModelId=4631ABF00280
    UnaryOperation(XERCES_CPP_NAMESPACE::DOMElement* element,ParseContext *parseContext)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        operand1=NULL;
        try
        {
	        int operandCount = 0;
	        for(XERCES_CPP_NAMESPACE::DOMNode *child = element->getFirstChild(); child != NULL; child = child->getNextSibling())
	        {
		        if(child->getNodeType()== XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
		        {
			        if(child)
			        {
				        switch(operandCount)
				        {
				        case 0:
					        operand1 = ExpressionFactory::getInstance().template createExpression<OP1>((XERCES_CPP_NAMESPACE::DOMElement *)child,parseContext);
					        operandCount++;
					        break;
				        default:
                            RULEENGINE_STACK_TRACE_EXIT
                            throw RuleException("Number of Operands must not be greater than 1");
					        break;
				        }
			        }
		        }
	        }
            if(operandCount != 1 )
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Number of Operands must be 1");
            }
        }
        catch(...)
        {
            delete operand1;
            RULEENGINE_STACK_TRACE_EXIT
            throw;
        }
        RULEENGINE_STACK_TRACE_EXIT
    }
    
    /////////////////////////////////////////////////////////////////////
    //  Destructor method to free operand made virtual
    //  
    ////////////////////////////////////////////////////////////////////
    virtual ~UnaryOperation()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        delete operand1;
        RULEENGINE_STACK_TRACE_EXIT
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



