// InputContext.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_INPUTCONTEXT_H
#define INC_INPUTCONTEXT_H
/*********************************************************************
#   File        :   InputContext.h
#   Abstract    :   Implementation of EnginePool class
#   Date        :   14 May, 2007
#   Author(s)   :   Bhanu 
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
// This class acts as abstract base class for the Input Context
//
////////////////////////////////////////////////////////////////////// 
class InputContext
{
public:
    virtual void discardInput() = 0;
    virtual bool isEmpty() = 0;
    virtual ~InputContext() {}
};

};

#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
