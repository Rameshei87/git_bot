// RuleException.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULEEXCEPTION_H
#define INC_RULEEXCEPTION_H

#include <ruleengine/framework/Types.h>
/*********************************************************************
#   File        :   RuleException.h
#   Abstract    :   Implemetation of Rule Exception class
#                   to work with the exceptions in RuleEngine
#   Date        :   04 May, 2007
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
#   Libraries   :  
**********************************************************************/

namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//  
//  This is a derived class provides method to handle all the
//  RuleEngine exception
//
//////////////////////////////////////////////////////////////////////
    class RuleException : public std::exception
{
	std::string message;
public:
    /////////////////////////////////////////////////////////////////////
    //  Constructor 
    //  
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   String contains Exception Message
    //  Return Type :   void
    //
    //////////////////////////////////////////////////////////////////////
    RuleException(std::string message)
    {
        RULEENGINE_STACK_TRACE_ENTRY
		this->message = message;
        RULEENGINE_STACK_TRACE_EXIT
	}
    /////////////////////////////////////////////////////////////////////
    //  Method to get the exception Message 
    //  
    //  
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   NONE
    //  Return Type :   Constant Pointer to Char
    //                              contains exception Message
    //
    //////////////////////////////////////////////////////////////////////
	const char * what()
	{   
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
		return message.c_str();
	}
    /////////////////////////////////////////////////////////////////////
    //  Virtual Destructor to throw all the exception
    //  
    //  
    //////////////////////////////////////////////////////////////////////
    virtual ~RuleException() throw()
    {
        RULEENGINE_STACK_TRACE_ENTRY
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



