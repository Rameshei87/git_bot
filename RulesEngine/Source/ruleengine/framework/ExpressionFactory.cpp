//  ExpressionFactory.cpp :  
//
//////////////////////////////////////////////////////////////////////

#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleException.h>
/*********************************************************************
#   File        :	ExpressionFactory.cpp
#	Abstract	:	Implementation of ExpressionFactory class Methods
#	Date		:	17th May, 2007
#	Author(s)	:	Sabyasachi
#	Design		:	
#	References	
#	Module		:	RuleEngine
======================================================================
#	Revision History
======================================================================
#	SI  		Edited by		Date			Area Edited
======================================================================
*********************************************************************/
namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//  
//  Static Method to get an Instance of ExpressionFactory 
//
/////////////////////////////////////////////////////////////////////
//  Parameters  :   Nothing
//  Return Type :   ExpressionFactory Pointer
//
//////////////////////////////////////////////////////////////////////
ExpressionFactory& ExpressionFactory ::getInstance()
{
    RULEENGINE_STACK_TRACE_ENTRY
    static ExpressionFactory factory;
    RULEENGINE_STACK_TRACE_EXIT
    return factory;
}

/////////////////////////////////////////////////////////////////////
//  
//  Destructor to release all the creator in the creator Map
//
/////////////////////////////////////////////////////////////////////
ExpressionFactory::~ExpressionFactory()
{
    RULEENGINE_STACK_TRACE_ENTRY
    std::map< std::string , ExpressionCreator*  >::iterator mapIter;
    for(mapIter=creator.begin();mapIter!=creator.end();mapIter++)
    {
        delete mapIter->second;
    }
    RULEENGINE_STACK_TRACE_EXIT
}
};

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/





