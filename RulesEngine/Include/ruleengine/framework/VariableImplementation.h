//VariableImplementation.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_VARIABLEIMPLEMENTATION_H
#define INC_VARIABLEIMPLEMENTATION_H

#include<ruleengine/engine/RuleException.h>
#include<ruleengine/framework/Types.h>
/*********************************************************************
#    File        :  VariableImplementation.h
#    Abstract    :  Implementation of variables.
#    Date        :  14 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :  
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI   Edited by    Date              Area Edited
#
#
======================================================================
#    Libraries   :  
*********************************************************************/
namespace ruleengine
{
////////////////////////////////////////////////////////////////////////////////
//
// This is a class used to implement variables.  
//
///////////////////////////////////////////////////////////////////////////////
class VariableImplementation
{

protected:
    bool initialised;           //It is set to true if the variable is initialised.

public:
    //////////////////////////////////////////////////////////////////////////
    //
    //  This function is used to check whether the variable is initialised.
    //
    //////////////////////////////////////////////////////////////////////////
    //
    //  Return Type:    Void.
    //  Parameters:     Nothing. 
    //
    //////////////////////////////////////////////////////////////////////////
    void invalidate()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        initialised = false;
        RULEENGINE_STACK_TRACE_EXIT
    }
         
    //////////////////////////////////////////////////////////////////////
    //
    //    Default Constructor
    //
    ///////////////////////////////////////////////////////////////////////
    //
    //    Paramters     : Nothing.                  
    //
    ///////////////////////////////////////////////////////////////////////
    virtual ~VariableImplementation(){}     //Destructor
    
};

////////////////////////////////////////////////////////////////////////////////
//
// This is a class used to implement variables to retrieve their values
//  and set their values.
//
///////////////////////////////////////////////////////////////////////////////
template<class Type>
class PrimitiveVariableImplementation : public VariableImplementation
{
private:
    Type _value;

public:

    //////////////////////////////////////////////////////////////////////////
    //
    //  This function returns the value of the variable if it is
    //  initialised.
    //
    //////////////////////////////////////////////////////////////////////////
    //
    //  Returns :
    //  type
    //             The value stored in the variable.
    //
    //////////////////////////////////////////////////////////////////////////
    Type get() 
    {
        RULEENGINE_STACK_TRACE_ENTRY
        if(initialised==false)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Variable not initialized");
        }
        RULEENGINE_STACK_TRACE_EXIT
        return this->_value;
    }

    //////////////////////////////////////////////////////////////////////////
    //
    //  This function is used to set the value of the variable to a 
    //  data and set initialised to true.
    //
    //////////////////////////////////////////////////////////////////////////
    //
    //  Parameters :
    //  type
    //              The value to be stored in the variable. 
    //
    //////////////////////////////////////////////////////////////////////////
    void set(Type val)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        initialised = true;
        this->_value = val;
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
