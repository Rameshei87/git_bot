// ExpressionFactory.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_EXPRESSIONFACTORY_H
#define INC_EXPRESSIONFACTORY_H

#include <string>
#include <map>

#include <ruleengine/framework/ExpressionCreator.h>
#include <ruleengine/framework/Types.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ParseContext.h>

/*********************************************************************
#   File        :   ExpressionFactory.h
#   Abstract    :   Implemetation of ExpressionFactory Class
#                   to create several types of expression.
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
#   2   Kishore     10-Aug-2007     Added exprName when throwing
#                                   RuleException in createExpression
#
#   3   Kishore     05-Sep-2007     Added try catch in createExpression
#                                   
======================================================================
#   Libraries   :   xerces
*********************************************************************/

namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//  
//  This class is a Singleton class
//  
//  It has the method to create various types of Expressions from 
//  DOMElement and ParseContext .
//
//  Usage: This class is invoked To register expression . 
//         
//
//////////////////////////////////////////////////////////////////////

//##ModelId=46317B8E0232
class ExpressionFactory
{
public:
    /////////////////////////////////////////////////////////////////////
    //  
    //  Method to create Expression from DOMElement and ParseContext
    //
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //
    //  DOMElement*
    //          Containing the Expression Node from the XML  
    //  ParseContext*
    //          This class does not use it,It will be passed on to 
    //          ExpressionCreator
    //              
    //  Returns:
    //  template ExpressionType*
    //          newly constructed Expression. The caller has to free it
    //  Exception:
    //  RuleException
    //          Whenever Invalid Expression Name found.
    //          Whenever Invalid Expression Type found.
    //          Whenever Invalid Input-type found.
    //          Whenever Invalid Output-type found.
    //
    //////////////////////////////////////////////////////////////////////
    template<class ExpressionType>
    //##ModelId=4631810C001F
    ExpressionType* createExpression(XERCES_CPP_NAMESPACE::DOMElement *node,ParseContext *parseContext);
   
	/////////////////////////////////////////////////////////////////////
    //  
    //  Static Method to get an Instance of ExpressionFactory 
    //
    /////////////////////////////////////////////////////////////////////
    //
    //  Returns:
    //  ExpressionFactory*
    //              Newly created or the existing ExpressionFactory*
    //
    //////////////////////////////////////////////////////////////////////
    static ExpressionFactory &getInstance();

    /////////////////////////////////////////////////////////////////////
    //  
    //  Destructor to release all the creator from the creator Map
    //
    /////////////////////////////////////////////////////////////////////
    ~ExpressionFactory();

    /////////////////////////////////////////////////////////////////////
    //  
    //  Method to register an ExpressionCreator for an expression name 
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //  Parametes:
    //  std::string name
    //              contains the Expression Name
    //
    //  ExpressionCreator* 
    //              ExpressionCreator that creates the expression specified
    //              by name. This should have been allocated using new.
    //              ExpressionFactory calls delete on it at program exit.
    //
    //  Exception:
    //  RuleException
    //              If the name is already registered for some other
    //              Expression.
    //
    //////////////////////////////////////////////////////////////////////
    void registerExpression(std::string name,ExpressionCreator* expressionCreator)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        
        // Throw an exception if another creator exists with the same name
        if(creator.end() != creator.find(name))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Expression name already registered");
        }

        // Add creator to the map
        creator[name]=expressionCreator;
        RULEENGINE_STACK_TRACE_EXIT
    }
    
private:
    ////////////////////////////////////////////////////////////////////
    //
    //  creator is a map containing ExpressionName and corresponding
    //  ExpressionCreator functor. 
    //  
    /////////////////////////////////////////////////////////////////////
    //##ModelId=46318A9603B9
    std::map< std::string , ExpressionCreator*  > creator;

    /////////////////////////////////////////////////////////////////////
    //  
    //  Private Constructor to make this class as Singleton Pattern
    //
    /////////////////////////////////////////////////////////////////////
    ExpressionFactory(){}
};



/////////////////////////////////////////////////////////////////////
//  
//  Method to create Expression from DOMElement and ParseContext
//  
//////////////////////////////////////////////////////////////////////
//  
//  Parameters  : 
//  DOMElement*
//        Xml node which contains Expressions.
//  Returns:   
//  template ExpressionType*
//  
//  Algorithm:
//              1>  Get the expression name from DOMElement
//              2>  Search the expression name from the Map 
//                  if Not found
//                    Throw exception                                        
//              3>  Convert the object pointed by Expressioncreator 
//                  for the searched expressionname into ExpressionType
//                  pointer.
//                  if pointer is NULL
//                      Throw ruleException
//                  else
//                      return pointer
//
//////////////////////////////////////////////////////////////////////
template<class ExpressionType>
//##ModelId=4631810C001F
ExpressionType* ExpressionFactory::createExpression(XERCES_CPP_NAMESPACE::DOMElement *node,ParseContext *parseContext)
{
    RULEENGINE_STACK_TRACE_ENTRY
    std::string exprName=XercesHelpers::getNodeName(node);
    typename std::map< std::string , ExpressionCreator*  >::iterator mapIter=creator.find(exprName);
    if(mapIter==creator.end())
    {
        RULEENGINE_STACK_TRACE_EXIT
        throw RuleException( exprName + " : Expression Not found in the Map");
    }
    else
    {
        try
        {
			ExpressionType *expr=dynamic_cast<ExpressionType*>((*mapIter->second)(node,parseContext));
            if(expr==NULL)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException(exprName + ":Invalid Expression Type"); //Later change to Xpath of the node
            }
            std::string expressionInputType = expr->getInputType();
            std::string expressionOutputType = expr->getOutputType();
        
            if(expressionInputType != "*" && expressionInputType != parseContext->inputType)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException(std::string("Invalid inputType ") + expressionInputType + " for expression: " + exprName);
            }
            //compares both the output types ,on failure thows exception 
            if(expressionOutputType !="*" && expressionOutputType != parseContext->outputType)
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException(std::string("Invalid outputType ") + expressionOutputType + " for expression: " + exprName);
            }
            RULEENGINE_STACK_TRACE_EXIT
            return expr;
        }
        catch(RuleException &ex)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException( std::string("Could not create expression [") + exprName + "]. " + ex.what() );
        }
    }
}



};

#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/


