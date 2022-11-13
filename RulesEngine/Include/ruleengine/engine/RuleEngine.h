// RuleEngine.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULEENGINE_H
#define INC_RULEENGINE_H

#include <deque>
#include <map>

#include <ruleengine/internal/MemoryPool.h>
#include <ruleengine/framework/Types.h>
/*********************************************************************
#   File        :   RuleEngine.h
#   Abstract    :   This class provides functions  
#                   to start the rule engine.
#   Date        :   03 May, 2007
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
class RuleConfig;
class InputContext;
class OutputContext;
class ExpressionCreator;
class VariableMemory;

////////////////////////////////////////////////////////////////////////
//  
//  Usage of the class : Retrive engine from EnginePool,Set the 
//  inputcontext and output context on that engine,invoke start method 
//  on this engine to process rulepackets and to get inputcontext and
//  outputput context from the same.invoke processRulepacket method for 
//  packet Handover.
//
/////////////////////////////////////////////////////////////////////////
//##ModelId=46307B9800FA
class RuleEngine
{
public:
    /////////////////////////////////////////////////////////////////////
    //  Method to start RuleEngine 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Pointer to RuleConfig
    //  Return Type :   void
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=463098A801A5
    uint_32 start(RuleConfig *config);
    

    /////////////////////////////////////////////////////////////////////
    //  Method to get inputContext from the InputContexts Deque
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Nothing
    //  Return Type :   Pointer to InputContext
    //
    ////////////////////////////////////////////////////////////////////
    InputContext * getInputContext()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        InputContext *inputContext=inputContexts.front();
        RULEENGINE_STACK_TRACE_EXIT
        return inputContext;
    }

    /////////////////////////////////////////////////////////////////////
    //  Method to push into the InputContexts Deque 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Pointer to InputContext
    //  Return Type :   void
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=4631BA1B004E
    void setInputContext(InputContext *inputContext)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        inputContexts.push_back(inputContext);
        RULEENGINE_STACK_TRACE_EXIT
    }
    

    /////////////////////////////////////////////////////////////////////
    //  Method to get outputContext from the OutputContexts Deque
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Nothing
    //  Return Type :   Pointer to OutputContext
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=4631BB25030D
    OutputContext * getOutputContext()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        OutputContext *outputContext=outputContexts.front();
        RULEENGINE_STACK_TRACE_EXIT
        return outputContext;
    }
    
    /////////////////////////////////////////////////////////////////////
    //  Method to push into the OutputContexts Deque 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Void
    //  Return Type :   Pointer to OutputContext
    //
    ////////////////////////////////////////////////////////////////////
    void setOutputContext(OutputContext *outputContext)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        outputContexts.push_back(outputContext);
        RULEENGINE_STACK_TRACE_EXIT
    }
    
    /////////////////////////////////////////////////////////////////////
    //  Constructor Method
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   Nothing
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=46383EFD00CB
    RuleEngine();
    
    /////////////////////////////////////////////////////////////////////
    //
    //  Method to get RuleVariable from MemoryPool
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  
    //  Return Type :   Pointer to VariableMemory 
    //
    ////////////////////////////////////////////////////////////////////
    VariableMemory * getRuleVariables()
    {
        return ruleVariables.front();
    }

    /////////////////////////////////////////////////////////////////////
    //
    //  Method to get GlobalVariable from MemoryPool
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  
    //  Return Type :   Pointer to VariableMemory 
    //
    ////////////////////////////////////////////////////////////////////
    VariableMemory * getGlobalVariables()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return globalVariables;
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
    //
    ////////////////////////////////////////////////////////////////////
    void processRulePacket(uint_32 id);
    

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
    void pushRuleVariable();
    

    /////////////////////////////////////////////////////////////////////
    //
    //  Method to pop from the RuleVariables Queue 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //
    ////////////////////////////////////////////////////////////////////
    void popRuleVariable();
    
    /////////////////////////////////////////////////////////////////////
    //
    //  Method to clear the InputContext and OutputContext deque.
    //  Whenever any exception occurs
    //  
    ////////////////////////////////////////////////////////////////////
    void cleanUp();

    /////////////////////////////////////////////////////////////////////
    //
    //  Method to handover to a Packet 
    //  Handover involves pushing inputContext and outputContext into 
    //  the queue,processing the packet and poping inputContext and 
    //  outputContext from the Queue.
    //
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters: 
    //  uint_32 packetId    Location of the packet which is to be processed 
    //                      when handover occurs.
    //  InputContext *      Current InputContext when handover occurs
    //                      (can be NULL).
    //  OutputContext *     Current OutputContext when handover occurs
    //                      (can be NULL).
    //  Exception
    //  RuleException 
//                       Whenever the Rulepacket doesnot exist
//                       at the given location
    /////////////////////////////////////////////////////////////////
    void handOver(uint_32 packetId,InputContext *inputContext,OutputContext *outputContext)
    {
        if (inputContext !=NULL)
        {
            inputContexts.push_front(inputContext);
        }
        if (outputContext !=NULL)
        {
            outputContexts.push_front(outputContext);
        }

        try
        {
            processRulePacket(packetId);
        }
        catch(...)
        {
            if (inputContext !=NULL)
            {
                inputContexts.pop_front();
            }
            if (outputContext !=NULL)
            {
                outputContexts.pop_front();
            }
            throw;
        }

        if (inputContext !=NULL)
        {
            inputContexts.pop_front();
        }
        if (outputContext !=NULL)
        {
            outputContexts.pop_front();
        }
    }


private:
    //##ModelId=46307D22000F
    std::deque<InputContext *> inputContexts;
    //##ModelId=46307D22006D
    std::deque<OutputContext *> outputContexts;

    //##ModelId=463082690271
    RuleConfig  *ruleConfig;
    VariableMemory *globalVariables;
    std::deque<VariableMemory *> ruleVariables;
    
};

/////////////////////////////////////////////////////////////////////
//  Method to register All the Operations
//  
////////////////////////////////////////////////////////////////////
//  
//  
//  Return Type :   void 
//
////////////////////////////////////////////////////////////////////
void registerOperations();

//////////////////////////////////////////////////////////////////////////
//
// This is a template funtion adds entries to the map. Each entry maps    
// the operation name to the creator functor to create that operation.
//
/////////////////////////////////////////////////////////////////////////
//
//    Return value  : Void
//    Paramters     : A pointer to Map.
//
/////////////////////////////////////////////////////////////////////////
void registerArithmeticOperations();

//////////////////////////////////////////////////////////////////////////
//
// This is a templatized  funtion adds entries to the map. Each entry maps    
// the operation name to the creator functor to create that operation.
//
/////////////////////////////////////////////////////////////////////////
//
//    Return value  : Void
//    Paramters     : A reference to Map.
//
/////////////////////////////////////////////////////////////////////////

void registerComparisonOperations();

//////////////////////////////////////////////////////////////////////////
//
// This is a template funtion adds entries to the map. Each entry maps    
// the operation name to the creator functor to create that operation.
//
/////////////////////////////////////////////////////////////////////////
//
//    Return value  : void
//    Paramters     : A reference to Map.
//
/////////////////////////////////////////////////////////////////////////

void registerLogicalOperations();
void registerCastOperations();
void registerConversionOperations();



//////////////////////////////////////////////////////////////////////////////
//
// This template function is used to register the Base types.
//
//////////////////////////////////////////////////////////////////////////////
void registerBaseTypes();
};

#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/



