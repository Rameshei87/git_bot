// BaseTypes.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULEENGINE_TYPES_H
#define INC_RULEENGINE_TYPES_H

/*********************************************************************
#    File        :  BaseTypes.h
#    Abstract    :  This file provides template classes for constants 
#                   and variables.
#    Date        :  01 May, 2007
#    Author(s)   :  Bhanu
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI        Edited by        Date            Area Edited
#
======================================================================
#    Libraries   :  xerces
*********************************************************************/

#ifdef ENABLE_RULEENGINE_STACK_TRACE 

#include<iostream>
#include<string>

class StackTraceLogger
{
    std::string _functionName;
public:
    int lineNo;
    StackTraceLogger(const char* functionName, int line)
    {
        _functionName = functionName;
        std::cout << line << " " << _functionName << "::Entry" << std::endl;
    }
    ~StackTraceLogger()
    {
        std::cout << lineNo << " " << _functionName << "::Exit" << std::endl;
    }
};

#define RULEENGINE_STACK_TRACE_ENTRY  StackTraceLogger stackTraceLogger(__FUNCTION__,__LINE__);

#define RULEENGINE_STACK_TRACE_EXIT stackTraceLogger.lineNo = __LINE__;

#else

#define RULEENGINE_STACK_TRACE_ENTRY
#define RULEENGINE_STACK_TRACE_EXIT

#endif


namespace ruleengine
{

typedef int int_32;
typedef short int_16;
typedef unsigned short uint_16;
typedef unsigned int uint_32;
typedef unsigned long long uint_64;
typedef long long int_64;

};


#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
