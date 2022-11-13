#ifndef INC_VARIABLECREATOR_H
#define INC_VARIABLECREATOR_H
/*********************************************************************
#   File        :   VariableCreator.h
#   Abstract    :   Variable Creator is a base class for all 
#                   VariableCreators like StringVariableCreator
#                   Integar16VariableCreator, etc.
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

// Forward Declaration
class VariableImplementation;

//////////////////////////////////////////////////////////////////////
// This class is the base class for all VariableCreators
//
// It has the function operator overloaded to create
// variableImplementations
//
//////////////////////////////////////////////////////////////////////
class VariableCreator
{
public:

    //////////////////////////////////////////////////////////////////////
    // Returns a new VariableImplementation
    //////////////////////////////////////////////////////////////////////
    // Parameters : NONE
    //
    // Returns
    //              A pointer to a newly created VariableImplementation
    //              It is the responsibility of the caller to delete
    //              this object.
    //
    //////////////////////////////////////////////////////////////////////
    virtual VariableImplementation* operator()() = 0;


    //////////////////////////////////////////////////////////////////////
    // Virtual destructor - Pointers of type VariableCreator will hold
    // derived class objects
    //////////////////////////////////////////////////////////////////////
    virtual ~VariableCreator(){}

};

//////////////////////////////////////////////////////////////////////
// Template class to create variable creators
//
// For e.g. code to create a new VariableCreator for 
// StringVariableImplementation
//      new PrimitiveVariableCreator<StringVariableImplementation>()
//
//////////////////////////////////////////////////////////////////////
template<class VariableImpl>
class PrimitiveVariableCreator : public VariableCreator
{
    //////////////////////////////////////////////////////////////////////
    // defined VariableCreator::operator()()
    //////////////////////////////////////////////////////////////////////
    virtual VariableImplementation* operator()()
    {
        return new VariableImpl;
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
