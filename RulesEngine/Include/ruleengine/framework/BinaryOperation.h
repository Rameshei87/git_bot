// BinaryOperation.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_BINARYOPERATION_H
#define INC_BINARYOPERATION_H

#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <xercesc/dom/DOMAttr.hpp>
#include <ruleengine/engine/RuleException.h>
/*********************************************************************
#   File        :   BinaryOperation.h
#   Abstract    :   Implementation of BinaryOperation class
#                   for creation of Binary operands from XML file 
#                   and to release those operands.
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
//  This is class to get appropriate operands required for a 
//  Binary Operation 
//  Usage : Whenever evaluate method on Expression Object 
//          or its derived object is invoked
//
//////////////////////////////////////////////////////////////////////

//##ModelId=4631AA8900BB
template <class OP1, class OP2>
class BinaryOperation 
{
protected:
    OP1* operand1;
    OP2* operand2;
public:
    /////////////////////////////////////////////////////////////////////
    //  Constructor method to get 2 binary operands from DOMElement
    //  
    ////////////////////////////////////////////////////////////////////
    //  Parameters  :   Pointer to DOMElement which Contains Operation
    //                  Pointer to ParseContext
    //                  
    //  Algorithm   :                  
    //                  1>  Traverse all the childnodes of the DOMElement 
    //                  2>  Check childnode type is of ELEMENT_NODE type and 
    //                              Childnode is not NULL
    //                  3>  get the operand from ExpressionFactory
    //                      depending on the no of Operand required
    //                  4>  if No. of operands is not 2 
    //                          throw exception
    ////////////////////////////////////////////////////////////////////
    BinaryOperation(XERCES_CPP_NAMESPACE::DOMElement* element,ParseContext *parseContext)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        operand1=NULL;
        operand2=NULL;
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
			            case 1:
				            operand2 = ExpressionFactory::getInstance().template createExpression<OP2>((XERCES_CPP_NAMESPACE::DOMElement *)child,parseContext);
				            operandCount++;
				            break;
			            default:
                            RULEENGINE_STACK_TRACE_EXIT
				            throw RuleException("Number of Operands must not be greater than 2");
				            break;
			            }
                    }
                }
            }

            if(operandCount != 2 )
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Number of Operands must be 2");
            }
        }
        catch(...)
        {
            delete operand1;
            delete operand2; 
            RULEENGINE_STACK_TRACE_EXIT
            throw;
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

    /////////////////////////////////////////////////////////////////////
    //  Destructor method to free 2 binary operands made virtual 
    //  
    ////////////////////////////////////////////////////////////////////
    virtual ~BinaryOperation()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        delete operand1;
        delete operand2;
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
