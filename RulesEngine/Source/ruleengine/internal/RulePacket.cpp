// RulePacket.cpp
//
//////////////////////////////////////////////////////////////////////
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/internal/RulePacket.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/internal/Rule.h>
#include <ruleengine/engine/XercesHelpers.h>
/*********************************************************************
#   File        :   RulePacket.cpp
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


/////////////////////////////////////////////////////////////////////
//
//  The constructor pushes each rule in a packet in a list.
//
//  Algorithm   :   1>  Get the value of the attribute id of the 
//                      packet node 
//                  2>  For each children of element check whether
//                      it is a DOMElement
//                  3>  If it is a DOMElement node, push the child 
//                      in the rule list                                        
//  
////////////////////////////////////////////////////////////////////
//  
//  Parameters  :   
//
//  DOMElement *element
//                          This is the reference to the packet of 
//                          DOMElement type in the XML configuration
//                          file.
//
//  ParseContext *context
//                          This is a reference to the class 
//                          ParseContext is used to map variables
//
////////////////////////////////////////////////////////////////////
RulePacket::RulePacket(XERCES_CPP_NAMESPACE::DOMElement *element, ParseContext *context)
{
    RULEENGINE_STACK_TRACE_ENTRY
    _id = XercesHelpers :: getUint32AttributeValue(element, "id");
    //add each rule in a list
    for( XERCES_CPP_NAMESPACE::DOMNode *child = element->getFirstChild(); child != NULL; child = child->getNextSibling() )
    {
        if( child->getNodeType() == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE )
        {
            _rules.push_back(new Rule((XERCES_CPP_NAMESPACE::DOMElement *)child, context));
        }
    }
    RULEENGINE_STACK_TRACE_EXIT
}


/////////////////////////////////////////////////////////////////////
//  
//  This funtion is used to processs each rule in the packet 
//  
//////////////////////////////////////////////////////////////////////////
 //  Parameters  :   
//  RuleEngine *engine
//                          It will get the input context from the
//                          engine and will process it.
//
//  Algorithm   :     1> If InputContext is not empty, it checks 
//                       each rule in a packet
//                    2> If the value of the attribute consume-input is
//                       true, it will remove the input from the queue                                        
//                    3> If the value of the attribute multi-occurent 
//                       is false, it will remove the rule from the packet                                        
//
/////////////////////////////////////////////////////////////////////////
void RulePacket::process(RuleEngine *engine)
{   
    RULEENGINE_STACK_TRACE_ENTRY
    InputContext *context = engine->getInputContext();

#ifdef WIN32
    // If window operating system is used then memory should be allocated explicitly
    bool *supressRule=new bool[_rules.size()];
#else
    //Other operating system can allocate memory dynamically
    bool supressRule[_rules.size()];
#endif

    //for each rule
    for (uint_32 i=0 ; i<_rules.size() ; i++)
    {
        supressRule[i]=false;           //supressedRule is initialised to false
    }

    // Enclosing in try block to delete[] suppressRule on exception

#ifdef WIN32            // If windows operating system 
    try
    {
#endif
        while(!context->isEmpty())  
        {       
            //if InputContext is not empty, check for each rule 
            int count=0;
            for(std::list<Rule*>::iterator iter = _rules.begin();
                                           iter != _rules.end();
                                           iter++, count++ )
            {
                if(!supressRule[count])
                {
                    if((*iter)->evaluate(engine))
                    {
                        if((*iter)->consumeInput)              //if consume-input is true         
                        {   
                            break;
                        }
                        if(!(*iter)->multiOccurrent)            //if multi-occurrent is false 
                        {
                            supressRule[count]=true;         //remove the rule
                        }
                    }
                }
            }
            context->discardInput();        //remove the Input
        }
#ifdef WIN32 
        // If window operating system is used then supressRule array should be deleted explicitly
        delete []supressRule;
    }
    //Catch the exception while deleting
    catch(...)
    {
        // TODO : delete should happen on exceptions also
        delete []supressRule;
        RULEENGINE_STACK_TRACE_EXIT   
        throw;
    }
#endif
    RULEENGINE_STACK_TRACE_EXIT
}

/////////////////////////////////////////////////////////////////////
//
//  This is the destructor of the class
//  This releases each rule in a packet.
//  
////////////////////////////////////////////////////////////////////
RulePacket::~RulePacket()
{
    RULEENGINE_STACK_TRACE_ENTRY
    for(std::list<Rule*>::iterator iter = _rules.begin();
                                     iter != _rules.end();
                                     iter++
        )
    {
        delete (*iter);
    }
    RULEENGINE_STACK_TRACE_EXIT
}

};
/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
