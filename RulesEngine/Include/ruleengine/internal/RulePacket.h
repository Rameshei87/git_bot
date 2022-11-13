// RulePacket.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULEPACKET_H
#define INC_RULEPACKET_H

#include <string>
#include <list>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/Types.h>
/*********************************************************************
#   File        :   RulePacket.h
#   Abstract    :   RulePacket contains a set of rules. 
#   Date        :   04 May, 2007
#   Author(s)   :   Sangeeta
#   Design      :  
#   References    
#   Module      :   RuleEngine
======================================================================
#   Revision History
======================================================================
#   SI          Edited by       Date        Area Edited
#
======================================================================
#   Libraries   :    xerces
*********************************************************************/
namespace ruleengine
{
//Forward declaration
class ParseContext;
class Rule;
class RuleEngine;

/////////////////////////////////////////////////////////////////////
//  
//  This is a class contains a set of rules.
//  It will process each of the rule in the packet. 
//  The supressRule array is used to check whether a rule in the packet 
//  If the property multi-occurant is set to true then
//  the matching rule will be be removed from the set. 
//  If the property consume-inputis set to true then
//  the input will be be removed from the input queue. 
//  
//////////////////////////////////////////////////////////////////////
//##ModelId=463081AC034B
class RulePacket
{
  public:

    /////////////////////////////////////////////////////////////////////
    //
    //  This funtion is used to retrieve the value of the attribute ID 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Returns :
    //  uint_32
    //                 Id of the packet.
    //                  
    ////////////////////////////////////////////////////////////////////
    uint_32 getId()
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return _id;
    }
    
    //##ModelId=4630980803B9
    /////////////////////////////////////////////////////////////////////
    //  This funtion is used to processs each rule in the packet 
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   
    //  RuleEngine *engine
    //                          It will get the input context from the
    //                          engine and will process it.
    //
    ////////////////////////////////////////////////////////////////////
    void process(RuleEngine *engine);

    /////////////////////////////////////////////////////////////////////
    //
//  The constructor pushes each rule in a packet in a list.
    //  
    ////////////////////////////////////////////////////////////////////
    //  
    //  Parameters  :   
    //  DOMElement *element
    //                          This is the reference to the packet of 
    //                          DOMElement type in the XML configuration
    //                          file.
    //  ParseContext *context
    //                          This is a reference to the class 
    //                          ParseContext is used to map variables
    //
    ////////////////////////////////////////////////////////////////////
    //##ModelId=46383EE1006D
    RulePacket(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context);

    /////////////////////////////////////////////////////////////////////
    //
    //  This is the destructor of the class
    //  This releases each rule in a packet.
    //  
    ////////////////////////////////////////////////////////////////////
    ~RulePacket();

  private:
    /////////////////////////////////////////////////////////////////////
    //
    //  List of rules in a packet.
    //  
    ////////////////////////////////////////////////////////////////////
    //##ModelId=463093280203
    std::list<Rule*> _rules;        
    /////////////////////////////////////////////////////////////////////
    //
    //  Id of the packet
    //  
    ////////////////////////////////////////////////////////////////////
    uint_32 _id;                       
};

};

#endif
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

