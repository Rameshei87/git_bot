#include <ruleengine/internal/MemoryPool.h>
#include <ruleengine/framework/VariableCreator.h>
#include <ruleengine/framework/VariableImplementation.h>

/*********************************************************************
#   File        :   MemoryPool.cpp
#   Abstract    :   see MemoryPool.h
#   Date        :   14 May, 2007
#   Author(s)   :   Kishore
#   Design      :  
#   References    
#   Module      :   RuleEngine
======================================================================
#   Revision History
======================================================================
#   SI          Edited by       Date        Area Edited
#
#   1           Kishore         14-May-2007 New Preparation
#
======================================================================
#   Libraries   :   
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////
// Returns an instance to MemoryPool
//////////////////////////////////////////////////////////////////////
MemoryPool& MemoryPool::getInstance()
{
    static MemoryPool memoryPool;

    RULEENGINE_STACK_TRACE_ENTRY
    RULEENGINE_STACK_TRACE_EXIT

    return memoryPool;
}

//////////////////////////////////////////////////////////////////////
//
// The destructor would delete VariableCreators and Memory objects
// in _memory
// 
//////////////////////////////////////////////////////////////////////
MemoryPool::~MemoryPool()
{
    RULEENGINE_STACK_TRACE_ENTRY
    for(uint_32 i=0; i<_creators.size(); i++)
    {
        delete _creators[i];
    }

    while( _memory.size() > 0 )
    {
        delete _memory.front();

        _memory.pop_front();
    }
    RULEENGINE_STACK_TRACE_EXIT
}


//////////////////////////////////////////////////////////////////////
//
// Gets memory from the pool. If the pool is empty, creates one and
// returns
//
// Allocates a new memory if the pool is empty.
//
// If memory is less than required size, instead of resizing existing
// memory, delets existing memory and allocates a new one.
// 
//////////////////////////////////////////////////////////////////////
//
// Parameters :
//
// uint_32 size
//          The size of memory to 
//          create types.
//
//          The object whose pointer is passed here should be 
//          allocated using the new operator
//
//          On Application exit MemoryPool deletes this object
//
//////////////////////////////////////////////////////////////////////
VariableMemory* MemoryPool::getMemory(uint_32 size)
{
    RULEENGINE_STACK_TRACE_ENTRY
    // Only one thread can getMemory / releaseMemory at a time
    ABL_WriteGuard guard(lock);

    // Allocate a new memory if the pool is empty
    if( 0 == _memory.size() )
    {
        RULEENGINE_STACK_TRACE_EXIT
        return new VariableMemory(_creators, size);
    }

    // Get a memory from the pool
    VariableMemory* varMemory = _memory.front();
    _memory.pop_front();

    // If memory is less than required size, instead of resizing existing
    // memory, delete existing memory and allocate a new one.
    if( varMemory->getSize() < size || varMemory->getTypeCount() < this->_creators.size() )
    {
        delete varMemory;
        RULEENGINE_STACK_TRACE_EXIT
        return new VariableMemory(_creators, size);
    }
    else
    {
        // Memory is of proper size
        // return it
        RULEENGINE_STACK_TRACE_EXIT
        return varMemory;
    }
}

//////////////////////////////////////////////////////////////////////
//
// Returns memory back to the pool
// 
//////////////////////////////////////////////////////////////////////
//
// Parameters :
//
// VariableMemory* memory
//          The memory to return back
//
//////////////////////////////////////////////////////////////////////
void MemoryPool::releaseMemory(VariableMemory* memory)
{
    RULEENGINE_STACK_TRACE_ENTRY
    // Only one thread can getMemory / releaseMemory at a time
    ABL_WriteGuard guard(lock);

    _memory.push_back( memory );
    RULEENGINE_STACK_TRACE_EXIT
}


//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
// Parameters :
//
// std::vector<VariableCreator *> &creators
//          The creators used to create the memory. The number of 
//          elements in this vector is the number of rows in the
//          2D array
//
// uint_32 size
//          The number of variables of each type. This is the number
//          of columns in the 2D array
//
//////////////////////////////////////////////////////////////////////
VariableMemory::VariableMemory(std::vector<VariableCreator *> &creators, uint_32 size)
{
    RULEENGINE_STACK_TRACE_ENTRY
    this->countTypes = creators.size();
    this->size = size;

    variable = new VariableImplementation**[countTypes];

    for(uint_32 i=0; i<countTypes; i++)
    {
        variable[i] = new VariableImplementation*[size];

        for(uint_32 j=0; j<size; j++)
        {
            variable[i][j] = (*creators[i])();
        }
    }
    RULEENGINE_STACK_TRACE_EXIT
}

//////////////////////////////////////////////////////////////////////
// Destructs the variables allocated in the constructor
//////////////////////////////////////////////////////////////////////
VariableMemory::~VariableMemory()
{
    RULEENGINE_STACK_TRACE_ENTRY
    for(uint_32 i=0; i<countTypes; i++)
    {
        for(uint_32 j=0; j<size; j++)
        {
            delete variable[i][j];
        }
        delete[] variable[i];
    }

    delete[] variable;
    RULEENGINE_STACK_TRACE_EXIT
}

};

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
