// EnginePool.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_ENGINEPOOL_H
#define INC_ENGINEPOOL_H

#include <ruleengine/engine/RuleEngine.h>
#include <ABL_TPCQueue.h>
#include <ruleengine/framework/Types.h>
#include <iostream>

/*********************************************************************
#   File        :   EnginePool.h
#   Abstract    :   Implementation of EnginePool class
#   Date        :   14 May, 2007
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
*********************************************************************/

namespace ruleengine
{
//////////////////////////////////////////////////////////////////////
//
// This is a singleton class contains a queue of engines 
// and method to set size ,to get size of the Pool 
// get engine from Pool and release engine to the Pool
//
////////////////////////////////////////////////////////////////////// 
class EnginePool
{
public:
    //////////////////////////////////////////////////////////////////////
    // 
    //	Function to set the size of the Pool 
    //  
    //
    //////////////////////////////////////////////////////////////////////
    //  Parameter       :   uint_32 size to be set for the Pool size
    //	Return value    :   void
    //
    //////////////////////////////////////////////////////////////////////
    inline void setPoolSize(uint_32 size)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        for (uint_32 counter=0 ; counter<size ; counter++)
        {
           RuleEngine *engn=new RuleEngine(); //create a new ruleengine
           _engineQueue.mb_put(engn); // Push theruleengine into the Queue
        }
        RULEENGINE_STACK_TRACE_EXIT
    }

    //////////////////////////////////////////////////////////////////////
    // 
    //	Function to get the size of the Pool
    //
    //////////////////////////////////////////////////////////////////////
    //  
    //	Return value    :   uint_32 size of the Queue
    //
    //////////////////////////////////////////////////////////////////////
    inline uint_32 getPoolSize()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (uint_32)_engineQueue.num_of_elements();
    }
    //////////////////////////////////////////////////////////////////////
    // 
    //	Function to get an engine from the Engine Queue
    //
    //////////////////////////////////////////////////////////////////////
    //  
    //	Return value    :   Pointer to RuleEngine returned from the Queue
    //
    //////////////////////////////////////////////////////////////////////
    inline RuleEngine *getEngine()
    {   
        RULEENGINE_STACK_TRACE_ENTRY
        RuleEngine* engine=_engineQueue.mb_get();
        RULEENGINE_STACK_TRACE_EXIT
        return engine;
    }

    //////////////////////////////////////////////////////////////////////
    // 
    //	Function to release an engine into the Engine Queue
    //
    //////////////////////////////////////////////////////////////////////
    //  Parameter       :   void
    //	Return value    :   Pointer to RuleEngine
    //
    //////////////////////////////////////////////////////////////////////
    inline void releaseEngine(RuleEngine *engine)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        _engineQueue.mb_put(engine);
        RULEENGINE_STACK_TRACE_EXIT
    }

    /////////////////////////////////////////////////////////////////////
    //  
    //  Static Method to get an Instance of EnginePool 
    //
    /////////////////////////////////////////////////////////////////////
    //  Parameters  :   Nothing
    //  Return Type :   Pointer to EnginePool
    //
    //////////////////////////////////////////////////////////////////////
    static EnginePool &getInstance();

    /////////////////////////////////////////////////////////////////////
    //  
    //  Destructor to pop all the engine from the Queue and delete those
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //  
    //////////////////////////////////////////////////////////////////////
    ~EnginePool();
    
private:
    /////////////////////////////////////////////////////////////////////
    //  
    //  Private Constructor to make this class as Singleton Pattern
    //
    /////////////////////////////////////////////////////////////////////
    //  
    //
    ////////////////////////////////////////////////////////////////////
    EnginePool()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
    }
    ABL_TPCQueue<RuleEngine *> _engineQueue;
    
};

};

#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
