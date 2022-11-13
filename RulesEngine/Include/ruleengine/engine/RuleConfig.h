// RuleConfig.h
//
//////////////////////////////////////////////////////////////////////
#ifndef INC_RULECONFIG_H
#define INC_RULECONFIG_H

#include <string>
#include <vector>
#include <list>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/VariableImplementation.h>

/*********************************************************************
#   File        :   RuleConfig.h
#   Abstract    :   This class provides functions  
#                   to store and retrive rulepackets from the vector.
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
#   Libraries   :   xerces   
*********************************************************************/

namespace ruleengine
{
/////////////////////////////////////////////////////////////////////
//  
//  Forward Declaration of RulePacket Class
//  
//////////////////////////////////////////////////////////////////////

class RulePacket;
class RuleEngine;

/////////////////////////////////////////////////////////////////////
//  
//  This is a class having methods to 
//  get the RulePackets from DOMElement and store into a Vector
//  get index based rulepacket from the Vector
//  get the value of Maximum Global Variables in a XML
//  
//////////////////////////////////////////////////////////////////////
//##ModelId=463823A6008C
class RuleConfig
{
    public:
        //////////////////////////////////////////////////////////////////////
        //
        //  Constructor Method 
        //
        //////////////////////////////////////////////////////////////////////
        //  
        //  Parameters  :
        //  DOMElement*  which contains RuleConfig 
        //               in the form of XML
        //  
        //
        //////////////////////////////////////////////////////////////////////
        //##ModelId=46383DFE000F
        RuleConfig(XERCES_CPP_NAMESPACE::DOMElement *element);

        //////////////////////////////////////////////////////////////////////
        //
        //  Constructor Method 
        //
        //////////////////////////////////////////////////////////////////////
        //  
        //  Parameters  :
        //  const char *    which contains the RuleConfig
        //                  in the form of char*
        //      
        //  
        //
        //////////////////////////////////////////////////////////////////////
        RuleConfig(const char *xml);

        //////////////////////////////////////////////////////////////////////
        //
        //  Constructor Method 
        //
        //////////////////////////////////////////////////////////////////////
        //  
        //  Parameters  
        //  std::string     which contains the RuleConfig
        //                  in the form of std::string
        //      
        //  
        //
        //////////////////////////////////////////////////////////////////////
        RuleConfig(std::string xmlString);

        //////////////////////////////////////////////////////////////////////
        //
        //  Constructor Method 
        //
        //////////////////////////////////////////////////////////////////////
        //  
        //  Parameters  
        //  std::istream*   which contains the RuleConfig
        //                  in the form of stream of characters
        //  
        //
        //////////////////////////////////////////////////////////////////////
        RuleConfig(std::istream &stream);

        /////////////////////////////////////////////////////////////////////
        //
        //  Method to get RulePacket from the Vector existing 
        //  at a given location
        //  
        ////////////////////////////////////////////////////////////////////
        //  Parameters  : 
        //  uint_16 index   location of RulePacket in the Vector
        //
        //  Return Type :  
        //  RulePacket*     existing RulePacket 
        //
        //  Exception
        //  RuleException 
        //          Whenever the Rulepacket doesnot exist
        //          at the given location
        //
        ////////////////////////////////////////////////////////////////////
        RulePacket* getRulePacket(uint_16 index);

        /////////////////////////////////////////////////////////////////////
        //
        //  Method to get the value of maxGlobalVariables
        //
        ////////////////////////////////////////////////////////////////////
        //  
        //  Returns
        //  uint_16     value of the MaxGlobalVariables
        //
        ////////////////////////////////////////////////////////////////////
        uint_16 getMaxGlobalVariables()
        {
            RULEENGINE_STACK_TRACE_ENTRY
            RULEENGINE_STACK_TRACE_EXIT
            return maxGlobalVariables;
        }

        void invalidateGlobalVariables(RuleEngine* engine);

        /////////////////////////////////////////////////////////////////////
        //
        //  Method to get the value of maxRuleVariables
        //
        ////////////////////////////////////////////////////////////////////
        //  
        //  Returns
        //  uint_16     value of the MaxRuleVariables
        //
        ////////////////////////////////////////////////////////////////////
        uint_16 getMaxRuleVariables()
        {
            RULEENGINE_STACK_TRACE_ENTRY
            RULEENGINE_STACK_TRACE_EXIT
            return maxRuleVariables;
        }

        /////////////////////////////////////////////////////////////////////
        //
        //  Destructor Method to delete all the RulePackets from 
        //  RulePacket Vector.
        //
        ////////////////////////////////////////////////////////////////////
        ~RuleConfig();
    private:
        //##ModelId=463823D2030D
        std::vector<RulePacket *> rulePackets;
        //##ModelId=463823FC00FA
        uint_16 maxGlobalVariables;
        //##ModelId=463825640242
        uint_16 maxRuleVariables;

        /////////////////////////////////////////////////////////////////////
        //
        //  Method to get all the Rulepacket from DOMElement 
        //  and to Push those Rulepacket into the RulePacket Vector.
        //
        ////////////////////////////////////////////////////////////////////
        //  
        //  Parameters  :
        //  DOMElement*  which contains RuleConfig
        //  
        //
        //  
        /////////////////////////////////////////////////////////////////////
        void _initialize(XERCES_CPP_NAMESPACE::DOMElement *element);

        std::list< std::pair<uint_16, uint_16> > varIndexes;
        typedef std::list< std::pair<uint_16, uint_16> > VarIndexList;
        typedef std::pair<uint_16, uint_16> VarIndexPair;
};


};
#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/



