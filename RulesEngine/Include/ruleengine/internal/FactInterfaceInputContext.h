// FactInterfaceInputContext.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_FACTINTERFACEINPUTCONTEXT_H
#define INC_FACTINTERFACEINPUTCONTEXT_H

#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/RuleException.h>
#include <ruleengine/engine/InputContext.h>
//#include <common/Types.h>

#include <ruleengine/framework/UnaryOperation.h>
#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/engine/EnginePool.h>
#include <ProvRequest.h>

/*********************************************************************
#   File        :   FactInterfaceInputContext
#   Abstract    :   
#   Date        :   
#   Author(s)   :   shankar/abdul
#   Design      :  
#   References    
#   Module      :   common
======================================================================
#   Revision History
======================================================================
#   SI  Edited by    Date              Area Edited
#   1   shankar      05-09-07          initial implementation
#   2   sumit        22-10-07          moved this from interface and 
#                                      guiding to common
#   3   Sumit        14-03-07          removed code to source file.
======================================================================
#   Libraries   :    xerces, ruleengine
*********************************************************************/

/////////////////////////////////////////////////////////////////////
//
//  This class sets the input, can check whether the conext is empty,
//  can discard an input in the FactInterface.
//  
////////////////////////////////////////////////////////////////////
class FactInterfaceInputContext : public ruleengine::InputContext
{
    //////////////////////////////////////////////////////////////////////////
    //  bool value set to false if no _factInterface is received
    /////////////////////////////////////////////////////////////////////////    
    bool _empty;                        
	

public:

    SPS::ProvisioningRequest 	*req;
    SPS::uint_32  				physicalNEID;
	bool								conditionResult;

    //////////////////////////////////////////////////////////////////////////
    //
    //  This funtion registers Operations in the ExpressionFactory.
    //
    //  This function should be called only once in the lifetime of an
    //  applicaton.
    //
    //  Exceptions :     
    //      std::bad_alloc exception
    //  
    //
    ///////////////////////////////////////////////////////////////////////////
    static void initialize()throw(std::bad_alloc);

    /////////////////////////////////////////////////////////////////////
    //
    //  This constructs the input for encoding.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters :
    //  FactInterface inputfactInterface
    //                This set the inputs for encoding and  set the
    //                empty to false as the FactInterface is recieved.
    //
    //  Exceptions :     
    //      throw() empty list
    //  
    //
    ////////////////////////////////////////////////////////////////////
    FactInterfaceInputContext(SPS::ProvisioningRequest *pReq)throw();
    bool AddNewRequest(SPS::ProvisioningRequest *pReq)throw();


    //////////////////////////////////////////////////////////////////////////
    //
    //  This function returns true until the discareInput() function is called.
    //  
    /////////////////////////////////////////////////////////////////////////
    //  
    //  Returns :
    //  bool
    //            It returns true if input is received from the FactInterface.
    //
    //  Exceptions :     
    //      throw() empty list
    //  
    //
    /////////////////////////////////////////////////////////////////////////
    bool isEmpty()throw();

    
    /////////////////////////////////////////////////////////////////////
    //
    //  This function is called after encoding to discard the input in 
    //  the FactInterface. The value of the empty is set to true.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters :
    //  FactInterface inputfactInterface
    //                    This set the inputs for encoding and the set
    //                    empty to false as FactInterface is recieved.
    //
    //  Exceptions :     
    //      throw() empty list
    //  
    //
    ////////////////////////////////////////////////////////////////////
    void discardInput()throw();
    void addInput()throw();


};
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
