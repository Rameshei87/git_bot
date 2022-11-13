#ifndef INC_RULEENGINE_XERCESHELPERS_H
#define INC_RULEENGINE_XERCESHELPERS_H

#include <string>
#include <ABL_DateTime.h>
#include <ABL_Date.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/AbstractDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>

#include <ruleengine/engine/RuleException.h>
#include <ruleengine/framework/Types.h>
/*********************************************************************
#    File        :  XercesHelpers.h
#    Abstract    :  This class provides helper functions to work
#                   with Xerces library.
#    Date        :  07 May, 2007
#    Author(s)   :  Sangeeta
#    Design      :    
#    References    
#    Module      :  RuleEngine
======================================================================
#    Revision History
======================================================================
#    SI     Edited by        Date            Area Edited
#
#
======================================================================
#   Libraries    :  
*********************************************************************/

namespace ruleengine
{

//////////////////////////////////////////////////////////////////////
//
//  This class provide helper functions for working with Xerces parser
//
//  All the functions are static and accessed by class name
//
//  The node names here are assumed to be of a maximum MAX_NAME_SIZE-1
//  characters
//
//////////////////////////////////////////////////////////////////////
//##ModelId=461B7C120128
class XercesHelpers
{
public:

    //////////////////////////////////////////////////////////////////////
    //
    //  Creates a new DOMElement as a child of a root DOMElement 
    //  in the doc XMLDocument with the atrributes name and value
    //
    //
    //////////////////////////////////////////////////////////////////////
    //  
    //  Parameters:
    //
    //  string name
    //              The contents of the 'name' attribute 
    //
    //  string value
    //              The contents of the 'value' attribute 
    //
    //  DOMElement *root
    //              The newly created DomElement will be 
    //              added as the child of this DOMElement
    //
    //  DOMDocument *doc
    //              The newly created DomElement will be 
    //              added as an element in this DOMDocument
    //
    //////////////////////////////////////////////////////////////////////
    static void addNode(std::string name, std::string value, XERCES_CPP_NAMESPACE::DOMElement *root, XERCES_CPP_NAMESPACE::DOMDocument *doc)
	{
		
        
        XMLCh xmlFieldBuffer[MAX_NAME_SIZE+1];
        XMLCh xmlAttNameBuffer[MAX_NAME_SIZE+1];
        XMLCh xmlAttValueBuffer[MAX_NAME_SIZE+1];
        XMLCh xmlNameBuffer[MAX_NAME_SIZE+1];
        XMLCh xmlValueBuffer[MAX_NAME_SIZE+1];
        // set the tagname of the newly created node to field
        XERCES_CPP_NAMESPACE::XMLString::transcode("field", xmlFieldBuffer, MAX_NAME_SIZE);
        // set an attribute of the newly created node to name
        XERCES_CPP_NAMESPACE::XMLString::transcode("name", xmlAttNameBuffer, MAX_NAME_SIZE);
        // set an attribute of the newly created node to value
        XERCES_CPP_NAMESPACE::XMLString::transcode("value", xmlAttValueBuffer, MAX_NAME_SIZE);
        // set the value of the attribute 'name' of the newly created node
        XERCES_CPP_NAMESPACE::XMLString::transcode(name.c_str(), xmlNameBuffer, MAX_NAME_SIZE);
        // set the value of the attribute 'value' of the newly created node
        XERCES_CPP_NAMESPACE::XMLString::transcode(value.c_str(), xmlValueBuffer, MAX_NAME_SIZE);

        XERCES_CPP_NAMESPACE::DOMElement *element;
        element=doc->createElement(xmlFieldBuffer);                 //Adds the new element to the document
        element->setAttribute(xmlAttNameBuffer, xmlNameBuffer);     //sets the attribute name
        element->setAttribute(xmlAttValueBuffer, xmlValueBuffer);   //sets the attribute value
        root->appendChild(element);                                 //Adds the new element to the root node
	}

    //////////////////////////////////////////////////////////////////////
    //
    //  Creates XMLDocument from a string
    //
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  
    //  A pointer to DOMDocument
	//				The XML document
    //
    //  Parameters:
    //
    //  string xmlString
    //              XML Document will be created from this string
    //
    //  DOMBuilder *parser
    //              XML Document will be created with the help of it
    //
    //////////////////////////////////////////////////////////////////////
    static XERCES_CPP_NAMESPACE::DOMDocument* createDocumentFromString(std::string xmlString, XERCES_CPP_NAMESPACE::DOMBuilder *parser)
    {
        RULEENGINE_STACK_TRACE_ENTRY

        XERCES_CPP_NAMESPACE::MemBufInputSource *inputSource = new XERCES_CPP_NAMESPACE::MemBufInputSource((const XMLByte *)xmlString.c_str(), xmlString.length(), "fake-id" );
        XERCES_CPP_NAMESPACE::Wrapper4InputSource *wrapper = new XERCES_CPP_NAMESPACE::Wrapper4InputSource(inputSource, false);
        try
        {
            XERCES_CPP_NAMESPACE::DOMDocument *doc = parser->parse(*wrapper);

            delete wrapper;
            delete inputSource;
            RULEENGINE_STACK_TRACE_EXIT
            return doc;
        }
        catch(...)
        {
            delete wrapper;
            delete inputSource;
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to parse");
        }            
    }

   
    //////////////////////////////////////////////////////////////////////
    //
    //  Check if the node name matches the given name
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  true        If the nodename matches
    //  false       If the nodename does not match
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose name is to be matched
    //
    //  const char *name
    //              This should be a null terminated string.
    //              It is matched with the node name
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=461B7C120138
    static bool checkNodeName(XERCES_CPP_NAMESPACE::DOMNode *node, const char *name)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        char buffer[MAX_NAME_SIZE+1];

        // Get the node name and transcode it into a char buffer 
        // Throws Exception if transcode fails.
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(node->getNodeName(), buffer, 100))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Node name not found");  
        }

        // Return true if name matches
        if( 0 == strcmp(name, buffer))
        {
            RULEENGINE_STACK_TRACE_EXIT
            return true;
        }
        RULEENGINE_STACK_TRACE_EXIT
        // Name does not match
        return false;
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  To get the name of a node
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  The name of this node, depending on its type.
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose name is needed.
    //
    //////////////////////////////////////////////////////////////////////
    static std::string getNodeName(XERCES_CPP_NAMESPACE::DOMNode *node)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        char buffer[MAX_NAME_SIZE+1];

        // Get the node name and transcode it into a char buffer 
        // Throws Exception if transcode fails.
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(node->getNodeName(), buffer, 100))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Node name not found");  
        }
        RULEENGINE_STACK_TRACE_EXIT
        return std::string(buffer);      
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a uint_16 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  uint_16     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static uint_16 getUint16AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (uint_16)getUint64AttributeValue(node, attrName);
       
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a uint_32 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  uint_32     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static uint_32 getUint32AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {       
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (uint_32)getUint64AttributeValue(node,attrName);
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a uint_64 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  uint_64     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=461B7C12014B
    static uint_64 getUint64AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[] and throws exception if Transcode fails.
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute name not found");  
        }

        // Get Attributes. Throws exception if node is not of DOMNode type.
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute not found");
        }

        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);
        
        // Get Attribute Value
        XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE);
        RULEENGINE_STACK_TRACE_EXIT
        // Convert to uint_32
        return (uint_64)(atol(buffer));
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a int_16 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  int_16     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static int_16 getInt16AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (int_16)getInt64AttributeValue(node, attrName);
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a int_32 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  int_32     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static int_32 getInt32AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (int_32)getInt64AttributeValue(node, attrName);
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a int_64 value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  int_64     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static int_64 getInt64AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[] and throws exception if Transcode fails.
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute not found");  
        }

        // Get Attributes. Throws exception if node is not of DOMNode type.
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute not found");
        }

        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);

        // Get Attribute Value
        XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE);
        RULEENGINE_STACK_TRACE_EXIT
        // Convert to int_64
        return (int_64)(atol(buffer));
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a bool value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  bool     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static bool getBooleanAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        std::string attr = getStringAttributeValue(node,attrName);
        if(attr == "true")
        {
            RULEENGINE_STACK_TRACE_EXIT
            return true;
        }
        else if(attr == "false")
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }
        else
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to get value of the string attribute");
        }
    }
     
    //////////////////////////////////////////////////////////////////////
    //
    //  Get a float value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  float     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static float getFloatAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[] and throws exception if Transcode fails.
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to get name of the atrribute");  
        }

        // Get Attributes. Throws exception if node is not of DOMNode type.
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to get attribute");
        }

        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);

        // Get Attribute Value
        XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE);
        RULEENGINE_STACK_TRACE_EXIT
        // Convert to float
        return (float)(atof(buffer));
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get a double value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  double     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static double getDoubleAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {        
        RULEENGINE_STACK_TRACE_ENTRY
        RULEENGINE_STACK_TRACE_EXIT
        return (double)getFloatAttributeValue(node,attrName);
        
    }


    //////////////////////////////////////////////////////////////////////
    //
    //  Get a DateTime value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  ABL_DateTime
    //              The attribute value
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static ABL_DateTime getDateTimeAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        ABL_DateTime date(getStringAttributeValue(node, attrName).c_str());
        RULEENGINE_STACK_TRACE_EXIT
        return date;
        
    }


    //////////////////////////////////////////////////////////////////////
    //
    //  Get a Date value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  ABL_Date
    //              The attribute value
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static ABL_Date getDateAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        ABL_Date date(getStringAttributeValue(node, attrName).c_str());
        RULEENGINE_STACK_TRACE_EXIT
        return date;
        
    }



    //////////////////////////////////////////////////////////////////////
    //
    //  Get a string value of an attribute of a DOMNode
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  string     The attribute value
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=461B7C120159
    static std::string getStringAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[]
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to get name of the atrribute");   
        }

        // Get Attributes
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Unable to get the atrribute"); 
        }
        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);

        // Get Attribute Value
        XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE);
        RULEENGINE_STACK_TRACE_EXIT
        // Convert to string
        return std::string(buffer);
        
    }


    //////////////////////////////////////////////////////////////////////
    //
    //  Returns true if a string value of an attribute of a DOMNode is 
    //  present.
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  boolean
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static bool getStringAttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName, std::string &value)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[]
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }

        // Get Attributes
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }
        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);
        if(NULL == textnode)
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }

        // Get Attribute Value
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute's value not found");
            return false;
        }
        else
        {
        // Convert to string
        value = std::string(buffer);
        RULEENGINE_STACK_TRACE_EXIT
        return true;
       
        }
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Returns true if a uint_32 value of an attribute of a DOMNode is 
    //  present.
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  boolean
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose attribute is to be retrived
    //
    //  char *attrname
    //              This should be a null terminated string.
    //              It is the attribute name whose corresponding value is
    //              retrieved from node.
    //
    //////////////////////////////////////////////////////////////////////
    static bool getUint32AttributeValue(XERCES_CPP_NAMESPACE::DOMNode *node, char *attrName, uint_32 &value)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        XMLCh xmlbuffer[MAX_NAME_SIZE];
        char buffer[MAX_NAME_SIZE+1];

        // Convert char * to XMLCh[]
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(attrName, xmlbuffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }

        // Get Attributes
        XERCES_CPP_NAMESPACE::DOMNamedNodeMap *pAttributes = node->getAttributes();
        if(NULL == pAttributes)
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }
        // Get Attribute Node
        XERCES_CPP_NAMESPACE::DOMNode *textnode = pAttributes->getNamedItem(xmlbuffer);
        if(NULL == textnode)
        {
            RULEENGINE_STACK_TRACE_EXIT
            return false;
        }

        // Get Attribute Value
        if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(textnode->getNodeValue(), buffer, MAX_NAME_SIZE))
        {
            RULEENGINE_STACK_TRACE_EXIT
            throw RuleException("Attribute's value not found");
            return false;
        }
        else
        {
        // Convert to string
        value = (uint_32)(atol(buffer));
        RULEENGINE_STACK_TRACE_EXIT
        return true;
        }
        
    }

    
    //////////////////////////////////////////////////////////////////////
    //
    //  Get the first child node whose nodename matches a given name
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  DOMNode*    The child node if found
    //              NULL, if no child by that name is found
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose children are to be searched
    //
    //  char *name
    //              This should be a null terminated string.
    //              It is the name to be matched with the child nodename
    //
    //////////////////////////////////////////////////////////////////////
    //##ModelId=461B7C120167
    static XERCES_CPP_NAMESPACE::DOMNode* getChildByNodeName(XERCES_CPP_NAMESPACE::DOMNode *node, char *name)
    {     
        RULEENGINE_STACK_TRACE_ENTRY
        char buffer[MAX_NAME_SIZE+1];

        // loop through all the children
        for( XERCES_CPP_NAMESPACE::DOMNode *child = node->getFirstChild(); child != NULL; child = child->getNextSibling() )
        {
            // Get child node name
            const XMLCh *nodename = child->getNodeName();

            // Convert node name from XMLCh[] to char[]

            if(false == XERCES_CPP_NAMESPACE::XMLString::transcode(nodename, buffer, MAX_NAME_SIZE))
            {
                RULEENGINE_STACK_TRACE_EXIT
                throw RuleException("Node name not found");
            }

            // Compare nodename with name
            if( 0 == strcmp(name, buffer) )
            {
                RULEENGINE_STACK_TRACE_EXIT
               // Return the first match
                return child;
            }
            
        }
        RULEENGINE_STACK_TRACE_EXIT
        // No child's nodename matched
        return NULL;
        
    }

    //////////////////////////////////////////////////////////////////////
    //
    //  Get the name of the first child node
    //
    //////////////////////////////////////////////////////////////////////
    //  Return:
    //  DOMNode*    The child node if found
    //              NULL, if no child by that name is found
    //
    //  Parameters:
    //
    //  DOMNode *node
    //              The node whose children are to be searched
    //
    //////////////////////////////////////////////////////////////////////
    static XERCES_CPP_NAMESPACE::DOMElement* getFirstChildElement(XERCES_CPP_NAMESPACE::DOMNode *node)
    {
        RULEENGINE_STACK_TRACE_ENTRY
        // loop through all the children
        for( XERCES_CPP_NAMESPACE::DOMNode *child = node->getFirstChild(); child != NULL; child = child->getNextSibling() )
        {
            if(child->getNodeType() == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
            {
                RULEENGINE_STACK_TRACE_EXIT
                return (XERCES_CPP_NAMESPACE::DOMElement *)child;
            }
        }
        RULEENGINE_STACK_TRACE_EXIT
        // No child element
        return NULL;
        
    }

private:
    enum
    {
        // The buffers used in this class for holding names would be
        // of this size
        MAX_NAME_SIZE = 1024,
    };

};

};


#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
