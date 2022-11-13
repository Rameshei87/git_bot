
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/internal/RulePacket.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>
#include <ruleengine/engine/RuleConfig.h>
#include <ruleengine/framework/BaseVariables.h>
#include <ruleengine/framework/VariableCreator.h>
#include <ruleengine/internal/MemoryPool.h>
#include <ruleengine/framework/Types.h>
#include <ruleengine/internal/FactInterfaceInputContext.h>

/*********************************************************************
#   File        :   RuleEngine.cpp
#   Abstract    :   see RuleEngine.h
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
#   
======================================================================
#   Libraries   :   
*********************************************************************/
namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//  Method to start RuleEngine 
//  
////////////////////////////////////////////////////////////////////
//  Return Type :   void
//  Parameters  :   Pointer to RuleConfig
////////////////////////////////////////////////////////////////////
uint_32 RuleEngine::start(RuleConfig *config)
{   
    RULEENGINE_STACK_TRACE_ENTRY
   uint_32 PhysicalNEID;
    ruleConfig=config;
    globalVariables = MemoryPool::getInstance().getMemory(config->getMaxGlobalVariables());
    try
    {
        config->getRulePacket(0)->process(this);
    }
    catch(...)
    {
        ruleConfig->invalidateGlobalVariables(this);
        MemoryPool::getInstance().releaseMemory(globalVariables);
        //cleanUp();
        RULEENGINE_STACK_TRACE_EXIT
        throw;
    }
    FactInterfaceInputContext *context = dynamic_cast<FactInterfaceInputContext*>(this->getInputContext());
    PhysicalNEID = context->physicalNEID;
    context->addInput();
    ruleConfig->invalidateGlobalVariables(this);
    MemoryPool::getInstance().releaseMemory(globalVariables);
    //cleanUp();
    RULEENGINE_STACK_TRACE_EXIT
    return PhysicalNEID;
}

/////////////////////////////////////////////////////////////////////
//
//  Method to clear the InputContext and OutputContext deque.
//  
////////////////////////////////////////////////////////////////////
void RuleEngine::cleanUp()
{
    inputContexts.clear();
    outputContexts.clear();
}

/////////////////////////////////////////////////////////////////////
//  Constructor Method to set Globalvariable to NULL
//  
////////////////////////////////////////////////////////////////////
//  
// 
//
////////////////////////////////////////////////////////////////////
//##ModelId=46383EFD00CB
RuleEngine::RuleEngine()
{
    RULEENGINE_STACK_TRACE_ENTRY
    globalVariables=NULL;
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  Method to process RulePacket 
//  Handover mechanism will call this method
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameter   : 
//  uint_32     RulePacket Id
//
//////////////////////////////////////////////////////////////////////
void RuleEngine::processRulePacket(uint_32 id)
{
    RULEENGINE_STACK_TRACE_ENTRY
    ruleConfig->getRulePacket(id)->process(this);
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  Method to push RuleVariable into the Queue
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameter   : 
//  Pointer to VariableMemory to be pushed into the Queue
//  
//
////////////////////////////////////////////////////////////////////
void RuleEngine::pushRuleVariable()
{
    RULEENGINE_STACK_TRACE_ENTRY
    VariableMemory *ruleVariable=MemoryPool::getInstance().getMemory(ruleConfig->getMaxRuleVariables());
    ruleVariables.push_front(ruleVariable);
    RULEENGINE_STACK_TRACE_EXIT
}
/////////////////////////////////////////////////////////////////////
//
//  Method to pop from the RuleVariables Queue 
//  
////////////////////////////////////////////////////////////////////
//  
//
////////////////////////////////////////////////////////////////////
void RuleEngine::popRuleVariable()
{
    RULEENGINE_STACK_TRACE_ENTRY
    VariableMemory *ruleVariable=ruleVariables.front();
    ruleVariables.pop_front();
    MemoryPool::getInstance().releaseMemory(ruleVariable);
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//
//  Method to register All the Operations 
//  
////////////////////////////////////////////////////////////////////
//  
//  Return Type :   void 
//
////////////////////////////////////////////////////////////////////
void registerOperations()
{
    RULEENGINE_STACK_TRACE_ENTRY
    registerCastOperations();
    registerConversionOperations();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();
    RULEENGINE_STACK_TRACE_EXIT
}
};

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/


