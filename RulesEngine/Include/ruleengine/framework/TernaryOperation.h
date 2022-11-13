// TernaryOperation.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_TERNARYOPERATION_H
#define INC_TERNARYOPERATION_H

#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/framework/Types.h>
#include <xercesc/dom/DOMAttr.hpp>
/*********************************************************************
#   File        :   TernaryOperation.h
#   Abstract    :   Implemetation of TernaryOperation Class
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
//  Ternary Operation
//  Usage : Whenever evaluate method on Expression Object 
//          or its derived object is invoked
//
//////////////////////////////////////////////////////////////////////
//##ModelId=4631AAA5029F
template <class OP1, class OP2, class OP3>
class TernaryOperation 
{
protected:
	OP1* operand1;
	OP2* operand2;
	OP3* operand3;
public:
    /////////////////////////////////////////////////////////////////////
    //  Constructor method to get 3 Ternary operands from DOMElement
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
    //                  4>  if No. of operands is not 3 
    //                          throw exception
    ////////////////////////////////////////////////////////////////////
	TernaryOperation(XERCES_CPP_NAMESPACE::DOMElement* element,ParseContext *parseContext)
	{
        RULEENGINE_STACK_TRACE_ENTRY
        operand1=NULL;
        operand2=NULL;
        operand3=NULL;
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
					    case 2:
						    operand3 = ExpressionFactory::getInstance().template createExpression<OP3>((XERCES_CPP_NAMESPACE::DOMElement *)child,parseContext);
						    operandCount++;
						    break;
					    default:
                            RULEENGINE_STACK_TRACE_EXIT
			        	    throw RuleException("Number of Operands must not be greater than 1");
						    break;
					    }
				    }
			    }
                if(operandCount != 3 )
                {
                    RULEENGINE_STACK_TRACE_EXIT
                    throw RuleException("Number of Operands must be 3");
                }
		    }
        }
        catch(...)
        {
            delete operand1;
            delete operand2;
            delete operand3;
            RULEENGINE_STACK_TRACE_EXIT
            throw;
        }
        RULEENGINE_STACK_TRACE_EXIT
	}

    /////////////////////////////////////////////////////////////////////
    //  Destructor method to free 3 operands made virtual
    //  
    ////////////////////////////////////////////////////////////////////
    virtual ~TernaryOperation()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        delete operand1;
        delete operand2;
        delete operand3;
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



