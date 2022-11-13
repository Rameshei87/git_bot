//
//   ParseContext.h
//
//////////////////////////////////////////////////////////////////////////////
#ifndef INC_PARSECONTEXT_H
#define INC_PARSECONTEXT_H
#include<map>
#include<string>
#include<ruleengine/framework/Types.h>
/*********************************************************************
#    File        :  BaseTypes.h
#    Abstract    :  This file provides template classes for constants 
#                   and variables.
#    Date        :  17 May, 2007
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
#    Libraries   :  
*********************************************************************/


//////////////////////////////////////////////////////////////////////
//
// This class stores globalVriables and ruleVariables and their counter.
// 
//
//////////////////////////////////////////////////////////////////////
namespace ruleengine
{
class ParseContext
{
public:
    typedef std::pair<uint_16, uint_16> VarIndexPair;
    typedef std::map<std::string,VarIndexPair> VarIndexMap;
    VarIndexMap globalVariables;
    VarIndexMap ruleVariables;
    std::string inputType;
    std::string outputType;
    uint_32 maxRuleVariables;
};
};

#endif
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
