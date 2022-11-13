// RuleConfig.cpp
//
//////////////////////////////////////////////////////////////////////

#include <ruleengine/engine/RuleConfig.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/engine/RuleException.h>

#include <ruleengine/framework/Expression.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/framework/ParseContext.h>
#include <ruleengine/framework/VariableAccessors.h>

#include <ruleengine/internal/RulePacket.h>

/*********************************************************************
#   File        :	RuleConfig.cpp
#	Abstract	:	Implementation of RuleConfig class Methods
#                   to work with rulepackets vector
#	Date		:	17th May, 2007
#	Author(s)	:	Sabyasachi
#	Design		:	
#	References	
#	Module		:	RuleEngine
======================================================================
#	Revision History
======================================================================
#	SI  		Edited by		Date			Area Edited
======================================================================
*********************************************************************/

namespace ruleengine
{
//////////////////////////////////////////////////////////////////////
//
//  Constructor Method 
//
//////////////////////////////////////////////////////////////////////
//  
//  Parameters  :
//  const char *    which contains the RulePackets 
//                  in the form of constant char*
//      
//  
//
//////////////////////////////////////////////////////////////////////
RuleConfig::RuleConfig(const char *xml)
{
    RULEENGINE_STACK_TRACE_ENTRY
    const XMLCh gLS[] = { XERCES_CPP_NAMESPACE::chLatin_L, XERCES_CPP_NAMESPACE::chLatin_S, XERCES_CPP_NAMESPACE::chNull };
	XERCES_CPP_NAMESPACE::DOMImplementation *impl =XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(gLS);
	XERCES_CPP_NAMESPACE::DOMBuilder *parser = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMBuilder(XERCES_CPP_NAMESPACE::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgDOMNamespaces, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchema, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchemaFullChecking, false);
	XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(xml,parser);
	XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

	if(node!=NULL)	
    {
        _initialize(node);
    }
    else
    {
        parser->release();
        RULEENGINE_STACK_TRACE_EXIT
        throw ;
    }
    parser->release();
    RULEENGINE_STACK_TRACE_EXIT
}
//////////////////////////////////////////////////////////////////////
//
//  Constructor Method 
//
//////////////////////////////////////////////////////////////////////
//  
//  Parameters  
//  std::string     which contains the RulePackets 
//                  in the form of std::string
//      
//  
//
//////////////////////////////////////////////////////////////////////
RuleConfig::RuleConfig(std::string xmlString)
{
    RULEENGINE_STACK_TRACE_ENTRY
    const XMLCh gLS[] = { XERCES_CPP_NAMESPACE::chLatin_L, XERCES_CPP_NAMESPACE::chLatin_S, XERCES_CPP_NAMESPACE::chNull };
	XERCES_CPP_NAMESPACE::DOMImplementation *impl =XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(gLS);
	XERCES_CPP_NAMESPACE::DOMBuilder *parser = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMBuilder(XERCES_CPP_NAMESPACE::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgDOMNamespaces, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchema, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchemaFullChecking, false);
	XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(xmlString,parser);
	XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

	if(node!=NULL)	
    {
        _initialize(node);
    }
    else
    {
        parser->release();
        RULEENGINE_STACK_TRACE_EXIT
        throw ;
    }
    parser->release();
    RULEENGINE_STACK_TRACE_EXIT
}

//////////////////////////////////////////////////////////////////////
//
//  Constructor Method 
//
//////////////////////////////////////////////////////////////////////
//  
//  Parameters  :
//  DOMElement*  which contains RulePacket 
//               in the form of XML
//  
//
//////////////////////////////////////////////////////////////////////
RuleConfig::RuleConfig(XERCES_CPP_NAMESPACE::DOMElement *element)
{
    RULEENGINE_STACK_TRACE_ENTRY
    _initialize(element);
    RULEENGINE_STACK_TRACE_EXIT
}

//////////////////////////////////////////////////////////////////////
//
//  Constructor Method 
//
//////////////////////////////////////////////////////////////////////
//  
//  Parameters  
//  std::istream*   which contains the RulePackets
//                  in the form of stream of characters
//  
//
//////////////////////////////////////////////////////////////////////
RuleConfig::RuleConfig(std::istream &stream)
{
    RULEENGINE_STACK_TRACE_ENTRY
    std::string xmlString="";
    std::string x;
    while(stream >> x)
    {
        xmlString=xmlString+x+" ";
    }
    std::cout<<xmlString<<"\n";
    const XMLCh gLS[] = { XERCES_CPP_NAMESPACE::chLatin_L, XERCES_CPP_NAMESPACE::chLatin_S, XERCES_CPP_NAMESPACE::chNull };
	XERCES_CPP_NAMESPACE::DOMImplementation *impl =XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(gLS);
	XERCES_CPP_NAMESPACE::DOMBuilder *parser = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMBuilder(XERCES_CPP_NAMESPACE::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgDOMNamespaces, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchema, false);
	parser->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgXercesSchemaFullChecking, false);
	XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(xmlString,parser);
	XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

	if(node!=NULL)	
    {
        _initialize(node);
    }
    else
    {
        parser->release();
        RULEENGINE_STACK_TRACE_EXIT
        throw ;
    }
    parser->release();
    RULEENGINE_STACK_TRACE_EXIT
    
}

/////////////////////////////////////////////////////////////////////
//  Method to get all the RulePackets from DOMElement 
//  and to store into the RulePacket Vector.
////////////////////////////////////////////////////////////////////
//  
//  Parameters  : Pointer to DOMElement which contains RulePacket
//  Return      : NONE
//
//  
//  Algorithm   :   
//              1> Traverse all the RulePacket node inside a DOMElement
//              2> creates RulePacket from the Rulepacket and context
//              3> gets the rulepacket ID
//              4> stores the same rulepacket in the Vector 
//                 accoring to rulepacket ID
////////////////////////////////////////////////////////////////////
void RuleConfig::_initialize(XERCES_CPP_NAMESPACE::DOMElement *element)
{
    RULEENGINE_STACK_TRACE_ENTRY
    try
    {
        ParseContext context;
        context.maxRuleVariables=0;
        context.inputType = XercesHelpers::getStringAttributeValue(element,"input-type");
        context.outputType = XercesHelpers::getStringAttributeValue(element,"output-type");
        maxGlobalVariables = 0;
        //Traversing the DOMElement
        for(XERCES_CPP_NAMESPACE::DOMNode *child = element->getFirstChild(); child != NULL; child = child->getNextSibling())
        {
            if(child->getNodeType()== XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
		    {
                if(XercesHelpers::checkNodeName(child,"declare-variables"))     // If declare-variables is present
                {
                    std::map<std::string,uint_16> typeCount;

                    for( XERCES_CPP_NAMESPACE::DOMNode *grandChild = child->getFirstChild(); grandChild != NULL; grandChild = grandChild->getNextSibling() )        //for each child-node in declare-variables
                    {
                        if(grandChild->getNodeType()== XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
		                {
                            // Get the typeIndex
                            DeclareExpression *declExpr = ExpressionFactory::getInstance().createExpression<DeclareExpression>((XERCES_CPP_NAMESPACE::DOMElement*)grandChild, &context);
                            uint_16 typeIndex = declExpr->getTypeIndex();
                            delete declExpr;

                            // Calculate varIndex - this index should be different for all variables of same type
                            uint_16 varIndex;

                            //GlobalVariables should starts with ??
                            std::string name = XercesHelpers::getStringAttributeValue(grandChild,"name");
                            std::string type = XercesHelpers::getNodeName(grandChild);

                            if( ( name.length() < 3 ) || ( name[0]!='?' ) || ( name[1]!='?' ) )
                            {
                                RULEENGINE_STACK_TRACE_EXIT
                                throw RuleException("Invalid Variable Name");
                            }

                            //Map each variables of different data types locally and maintain a counter for each data types
                            std::map<std::string,uint_16> ::iterator iterType = typeCount.find(type);
                            
                            if( iterType != typeCount.end() ) 
                            {    
                                // If a variable of the type exists, increment the counter
                                iterType->second=iterType->second+1;        //Increase the value of the counter if the data type is found again
                                varIndex = iterType->second;

                                if( maxGlobalVariables < iterType->second )
                                {
                                    maxGlobalVariables = iterType->second;
                                }
                            }
                            else 
                            {
                                // If a variable of the type does not exist,
                                // start from 0
                                typeCount[type] = 0;
                                varIndex = 0;
                            }

                        // Set variable index in ParseContext::ruleVariables
                        context.globalVariables[name] = ParseContext::VarIndexPair(typeIndex,varIndex);
                        varIndexes.push_back(VarIndexPair(typeIndex,varIndex));
                        }
                    }

                    // Index starts from zero, so increment count by 1
                    maxGlobalVariables++;                    
                }
                else
                {
                    RulePacket *rulePacket=new RulePacket((XERCES_CPP_NAMESPACE::DOMElement *)child , &context);
                    uint_16 id = rulePacket->getId();
                    if(id >=rulePackets.size())
                    {
                        //increase the size of the vector
                        rulePackets.resize(id+1);
                    } 
                    // store the rulepacket at the particular index
                    rulePackets[id]= rulePacket;
                }
            }
        }
        maxRuleVariables=context.maxRuleVariables;
    }
    catch(...)
    {
        std::vector<RulePacket *>::iterator rulePacketIter;
        for(rulePacketIter=rulePackets.begin();rulePacketIter!=rulePackets.end();rulePacketIter++)
        {
            delete (*rulePacketIter);
        }
        RULEENGINE_STACK_TRACE_EXIT
        throw;
    }
    RULEENGINE_STACK_TRACE_EXIT
}
/////////////////////////////////////////////////////////////////////
//
//  Destructor Method to delete all the RulePackets from 
//  RulePacket Vector.
//
////////////////////////////////////////////////////////////////////
RuleConfig::~RuleConfig()
{
    RULEENGINE_STACK_TRACE_ENTRY
    std::vector<RulePacket *>::iterator rulePacketIter;
    for(rulePacketIter=rulePackets.begin();rulePacketIter!=rulePackets.end();rulePacketIter++)
    {
        delete (*rulePacketIter);
    }
    RULEENGINE_STACK_TRACE_EXIT
}

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
RulePacket* RuleConfig::getRulePacket(uint_16 index)
{
    RULEENGINE_STACK_TRACE_ENTRY
    if(index < rulePackets.size() && rulePackets[index]!= NULL)
    {
        RULEENGINE_STACK_TRACE_EXIT
        return rulePackets[index]; 
    }
    else
    {
        RULEENGINE_STACK_TRACE_EXIT
        throw RuleException("Invalid Packet");
    }
}

void RuleConfig::invalidateGlobalVariables(RuleEngine* engine)
{
    VariableImplementation*** variables = engine->getGlobalVariables()->variable;
    for( VarIndexList::iterator it = varIndexes.begin(); it != varIndexes.end(); it++)
    {
        variables[ it->first ][ it->second ]->invalidate();
    }
}

};

/*********************************************************************
#
#                 Copyright 2006 - 2007
#                 Lifetree Convergence Ltd.
#
*********************************************************************/


