
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>
#include <ruleengine/test/OperationTest.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>

#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleEngine.h>

#include <ruleengine/test/RuleEngineTest.h>

#include <ruleengine/internal/RulePacket.h>
#include <ruleengine/engine/RuleException.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>

#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


#define VALID_XMLPATH "../xmls/validconfig.xml"
#define INVALID_XMLPATH "../xmls/invalidconfig.xml"



XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;


class TestInputContext : public InputContext
{
    int inputCount;

public:

    TestInputContext()
    {
        inputCount = 10;
    }

    bool isEmpty()
    {
        if( !inputCount ) return false;

        else return true;
    }

    void discardInput()
    {
        if(inputCount) inputCount--;
    }
    
};

class TestOutputContext : public OutputContext
{
};

void OperationTest::testOperationTest_1()
{

    try
    {

        // Initialize ExpressionFactory
        registerBaseTypes();
        registerArithmeticOperations();
        registerComparisonOperations();
        registerLogicalOperations();

        XMLPlatformUtils::Initialize();
        const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };
        DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);

        // Parse the XML
        DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
        parser->setFeature(XMLUni::fgDOMNamespaces, false);
        parser->setFeature(XMLUni::fgXercesSchema, false);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

        // TODO : Change the hardcoded xml filename
        XERCES_CPP_NAMESPACE::DOMDocument *doc = parser->parseURI(VALID_XMLPATH);
        XERCES_CPP_NAMESPACE::DOMNode *node = doc->getDocumentElement();
        
        for(DOMNode *expression = node->getFirstChild(); expression != NULL; expression = expression->getNextSibling())
        {
            if(expression->getNodeType() == DOMNode::ELEMENT_NODE)
            {
                string exprname;
                bool success = false;
                try{

                    XERCES_CPP_NAMESPACE::DOMElement *ruleExpression = XercesHelpers::getFirstChildElement(expression);
                    
                    exprname = XercesHelpers::getNodeName(ruleExpression);
                    try
                    {
                        ExpressionBase *expression1=ExpressionFactory::getInstance().createExpression<ExpressionBase>((DOMElement *)ruleExpression, NULL);
                        delete expression1;
                    }
                    catch(...)
                    {
                        CPPUNIT_ASSERT(false);
                    }
                    success = true;
                    CPPUNIT_ASSERT(true);
                }
                catch(RuleException &)
                {
                }

                if(!success)
                {
                    CPPUNIT_ASSERT(false);
                }

            }
        }

        parser->release();

    }
    catch(RuleException &)
    {
        CPPUNIT_ASSERT(false);
    }

}

void OperationTest::testOperationTest_2()
{
    try
    {

        // Initialize ExpressionFactory
        registerBaseTypes();
        registerArithmeticOperations();
        registerComparisonOperations();
        registerLogicalOperations();

        XMLPlatformUtils::Initialize();
        const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };
        DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);

        // Parse the XML
        DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
        parser->setFeature(XMLUni::fgDOMNamespaces, false);
        parser->setFeature(XMLUni::fgXercesSchema, false);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

        // TODO : Change the hardcoded xml filename
        XERCES_CPP_NAMESPACE::DOMDocument *doc = parser->parseURI(INVALID_XMLPATH);
        XERCES_CPP_NAMESPACE::DOMNode *node = doc->getDocumentElement();
        
        for(DOMNode *expression = node->getFirstChild(); expression != NULL; expression = expression->getNextSibling())
        {
            if(expression->getNodeType() == DOMNode::ELEMENT_NODE)
            {
                string exprname;
                bool success = false;
                try{

                    XERCES_CPP_NAMESPACE::DOMElement *ruleExpression = XercesHelpers::getFirstChildElement(expression);
                    
                    exprname = XercesHelpers::getNodeName(ruleExpression);
                    try
                    {
                       // std::cout << XercesHelpers::getUint32AttributeValue(expression ,"Testcase") << std::endl;
                        ExpressionBase *expression1=ExpressionFactory::getInstance().createExpression<ExpressionBase>((DOMElement *)ruleExpression, NULL);
                        delete expression1;
                    }
                    catch(...)
                    {
						CPPUNIT_ASSERT(true);
                    }
                    success = true;
                }
                catch(RuleException &)
                {

				}

                if(!success)
                {
                    CPPUNIT_ASSERT(false);
                }

            }
        }

        parser->release();

    }
    catch(RuleException &)
    {
        CPPUNIT_ASSERT(false);
    }

}

Test *OperationTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("OperationTest");

    // add the tests
    testSuite->addTest (new TestCaller<OperationTest>  ("testOperationTest_1", &OperationTest::testOperationTest_1));
    testSuite->addTest (new TestCaller<OperationTest>  ("testOperationTest_2", &OperationTest::testOperationTest_2));

    return testSuite;
}
