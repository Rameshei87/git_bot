#ifndef INC_MEMORYPOOL_H
#define INC_MEMORYPOOL_H
/*********************************************************************
#   File        :   MemoryPool.h
#   Abstract    :   MemoryPool holds a pool of memories for storing
#                   variables
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
#include <ruleengine/framework/Types.h>
#include <vector>
#include <deque>

#include <ABL_RWLock.h>

namespace ruleengine
{

// Forward Declarations
class VariableCreator;
class VariableImplementation;
class VariableMemory;


//////////////////////////////////////////////////////////////////////
//
// Memory Pool holds a pool of memory for variables
//
// The memory is used for both global and rule variables
//
// This is a singleton class whose instance is obtained using
// MemoryPool::getInstance()
//
// At application startup addTypeCreator() needs to be called 
// for each type or variable.
// 
// getMemory() and releaseMemory() get memory from the pool and
// release memory back to the pool respectively.
// The memory is a two dimensional array of 
// VariableImplementation pointers. In the 2D array the 
// number of rows is the number of types 
// ( or the number of VariableCreators added ).
// The number of columns is the maximum number of variables allowed
// for each type
//
// Whenever getMemory(uint_32 size) is called if the existing memory
// in the pool is of a lesser size, it is resized to the required 
// size. So, eventually, all memories may resize to the maximum size.
//
//////////////////////////////////////////////////////////////////////
class MemoryPool
{
public:

    //////////////////////////////////////////////////////////////////////
    //
    // Gets memory from the pool. If the pool is empty, creates one and
    // returns
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
    VariableMemory* getMemory(uint_32 size);

    //////////////////////////////////////////////////////////////////////
    //
    // The destructor would delete VariableCreators and Memory objects
    // in _memory
    // 
    //////////////////////////////////////////////////////////////////////
    ~MemoryPool();

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
    void releaseMemory(VariableMemory* memory);

    //////////////////////////////////////////////////////////////////////
    //
    // Adds a Type to MemoryPool
    //
    // Calls to this function should be made before any call to getMemory
    //
    // This function is called during application startup to add
    // necessary types
    //
    //////////////////////////////////////////////////////////////////////
    //
    // Parameters :
    //
    // VariableCreator *creator
    //          Pointer to a VariableCreator object. This will be used to
    //          create types.
    //
    //          The object whose pointer is passed here should be 
    //          allocated using the new operator
    //
    //          On Application exit MemoryPool deletes this object
    //
    // Returns :
    //
    // uint_32
    //          Index of the type added
    //
    //////////////////////////////////////////////////////////////////////
    uint_32 addTypeCreator(VariableCreator* creator)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        uint_32 index = (uint_32)_creators.size();

        _creators.push_back(creator);

        RULEENGINE_STACK_TRACE_EXIT
        return index;
    }

    //////////////////////////////////////////////////////////////////////
    // Returns an instance to MemoryPool
    //////////////////////////////////////////////////////////////////////
    static MemoryPool& getInstance();

private:

    //////////////////////////////////////////////////////////////////////
    // Only one thread can getMemory / releaseMemory at a time
    // getMemory and releaseMemory will use this lock
    //////////////////////////////////////////////////////////////////////
    ABL_RWLock lock;

    //////////////////////////////////////////////////////////////////////
    // These creators will be used to create objects
    // The size of this vector corresponds to the number of types
    // supported
    //////////////////////////////////////////////////////////////////////
    std::vector<VariableCreator *> _creators;

    //////////////////////////////////////////////////////////////////////
    // This is the actual memory pool.
    // It holds the unused memories.
    //////////////////////////////////////////////////////////////////////
    std::deque<VariableMemory*> _memory;

    //////////////////////////////////////////////////////////////////////
    // Private constructor. This is to make this class a singleton
    //////////////////////////////////////////////////////////////////////
    MemoryPool(){}

    //////////////////////////////////////////////////////////////////////
    // Private copy-constructor without definition.
    // Prevents copy-construction
    //////////////////////////////////////////////////////////////////////
    MemoryPool(MemoryPool&);
};


//////////////////////////////////////////////////////////////////////
//
// VariableMemory represents a chunk of memory holding variables
//
// The same memory is used for both global and rule variables
//
// Objects of VariableMemory are created and managed in MemoryPool
//
// At application startup addTypeCreator() needs to be called 
// for each type or variable.
// 
// getMemory() and releaseMemory() get memory from the pool and
// release memory back to the pool respectively.
// The memory is a two dimensional array of 
// VariableImplementation pointers. In the 2D array the 
// number of rows is the number of types 
// ( or the number of VariableCreators added ).
// The number of columns is the maximum number of variables allowed
// for each type
//
// Whenever getMemory(uint_32 size) is called if the existing memory
// in the pool is of a lesser size, it is resized to the required 
// size. So, eventually, all memories may resize to the maximum size.
//
//////////////////////////////////////////////////////////////////////
class VariableMemory
{
    //////////////////////////////////////////////////////////////////////
    // Private copy-constructor declaration
    // Prevents copy construction
    //////////////////////////////////////////////////////////////////////
    VariableMemory(VariableMemory&);

    //////////////////////////////////////////////////////////////////////
    // The number of types
    // This will be the number of rows in the 2D array
    //////////////////////////////////////////////////////////////////////
    uint_32 countTypes;

    //////////////////////////////////////////////////////////////////////
    // The number of variables of each type
    // This will be the number of columns in the 2D array
    //////////////////////////////////////////////////////////////////////
    uint_32 size;
public:

    //////////////////////////////////////////////////////////////////////
    // Returns the number of variables of each type
    //////////////////////////////////////////////////////////////////////
    uint_32 getSize()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return size;
    }

    //////////////////////////////////////////////////////////////////////
    // Returns the number types
    //////////////////////////////////////////////////////////////////////
    uint_32 getTypeCount()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return countTypes;
    }

    //////////////////////////////////////////////////////////////////////
    // A 2-D array of VariableImplementation*
    //////////////////////////////////////////////////////////////////////
    VariableImplementation*** variable;

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
    VariableMemory(std::vector<VariableCreator *> &creators, uint_32 size );
    
    //////////////////////////////////////////////////////////////////////
    // Destructs the variables allocated in the constructor
    //////////////////////////////////////////////////////////////////////
    ~VariableMemory();
};


};

#endif
/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
