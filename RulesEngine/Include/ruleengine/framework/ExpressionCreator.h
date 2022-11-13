// ExpressionCreator.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_EXPRESSIONCREATOR_H
#define INC_EXPRESSIONCREATOR_H

#include <ruleengine/framework/ExpressionBase.h>
#include <ruleengine/framework/Types.h>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/AbstractDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>

/*********************************************************************
#   File        :   ExpressionFactory.h
#   Abstract    :   Implemetation of ExpressionCreator Class
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
#   Libraries   :   xerces
*********************************************************************/

//Forward Declaration of DOMElement Class
class XERCES_CPP_NAMESPACE::DOMElement;

namespace ruleengine
{
//Forward Declaration of ParseContext class
class ParseContext;

/////////////////////////////////////////////////////////////////////
//  
//  This is an abstract base class provides overloaded operator()
//  to create an ExpressionBase from the DOMElement and ParseContext.
//
//////////////////////////////////////////////////////////////////////
//##ModelId=4631B6B7038A
class ExpressionCreator
{
public:
    /////////////////////////////////////////////////////////////////////
    //
    //  Pure virtual Overloaded operator () to make this class abstract
    //  which creates a ExpressionBase from DOMElement.
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //  DOMElement*
    //              Which contains xml node for Expression.
    //  ParseContext*
    //  
    //  Returns:
    //  ExpressionBase *
    //          Newly created ExpressionBase
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=4631B6D902EE
    virtual ExpressionBase *operator()(XERCES_CPP_NAMESPACE::DOMElement *element,ParseContext *parseContext) = 0;
	
};

/////////////////////////////////////////////////////////////////////
//  
//  This is a templatized derived class from ExpressionCreator class
//  provides overloaded operator()to create a Primitive ExpressionBase
//  from the DOMElement and ParseContext.
//
//////////////////////////////////////////////////////////////////////

template <class Operation>
class PrimitiveCreator : public ExpressionCreator
{
    /////////////////////////////////////////////////////////////////////
    //
    //  Overridden operator () 
    //  which creates a Primitive ExpressionBase from DOMElement.
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //  DOMElement*
    //              Which contains Expression node from Xml.
    //  ParseContext*
    //  
    //  Returns:
    //  ExpressionBase *
    //          Newly created Primitive ExpressionBase
    //
    //////////////////////////////////////////////////////////////////////
    ExpressionBase *operator()(XERCES_CPP_NAMESPACE::DOMElement *node, ParseContext *context)
	{
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT		
		return new Operation(node,context);
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





