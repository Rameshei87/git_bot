// EnginePool.cpp: implementation of the EnginePool class Methods.
//
//////////////////////////////////////////////////////////////////////

#include <ruleengine/internal/RulePacket.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/EnginePool.h>

/*********************************************************************
#   File        :	EnginePool.cpp
#	Abstract	:	Implementation of EnginePool class Methods
#	Date		:	14th May, 2007
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
//  Static Method to get an Instance of EnginePool 
//
/////////////////////////////////////////////////////////////////////
//  Parameters  :   Nothing
//  Return Type :   Pointer to EnginePool
//
//////////////////////////////////////////////////////////////////////

EnginePool& EnginePool::getInstance()
{
    RULEENGINE_STACK_TRACE_ENTRY
    static EnginePool Pool;
    RULEENGINE_STACK_TRACE_EXIT
	return Pool;
}

/////////////////////////////////////////////////////////////////////
//  
//  Destructor to pop all the engine from the Queue and delete those
//
/////////////////////////////////////////////////////////////////////
//  
//  
//////////////////////////////////////////////////////////////////////
EnginePool::~EnginePool()
{
    RULEENGINE_STACK_TRACE_ENTRY
    uint_16 size=getPoolSize();
    for ( uint_32 counter=0 ; counter < size ; counter++ )
    {
        RuleEngine *engn=_engineQueue.mb_get(); // Pop from the Queue    
        delete engn; // delete 
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
