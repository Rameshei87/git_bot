
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>

#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleEngine.h>

#include <ruleengine/test/ExpressionFactoryTest.h>

XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;

void ExpressionFactoryTest::setUp()
{
    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();
}


void ExpressionFactoryTest :: testExpressionFactory_1()
{

    const char *exprXML = 
        "<add-integer32-integer32>"
        "   <integer32-constant value=\"100\"/>"
        "   <integer32-constant value=\"100\"/>"
        "</add-integer32-integer32>";

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    XERCES_CPP_NAMESPACE::DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    XERCES_CPP_NAMESPACE::DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();
    ParseContext *context;

    
    //Create Expression

    try
    {
        ExpressionBase *expression = ExpressionFactory::getInstance().createExpression<ExpressionBase >(node, context);

        delete expression;
    }
    catch(std::exception &)
    {
        CPPUNIT_ASSERT(false);
    }

    //CPPUNIT_ASSERT_NO_THROW(

    // Delete the parser, this also releases the parsed document
    parser->release();
}

void ExpressionFactoryTest :: testExpressionFactory_2()
{

    const char *exprXML = 
        "<and>"
        "   <boolean-constant value=\"100\"/>"
        "   <boolean-constant value=\"100\"/>"
        "</and>";

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    XERCES_CPP_NAMESPACE::DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    XERCES_CPP_NAMESPACE::DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

   
    //Create Expression

    try
    {
        ExpressionBase *expression = ExpressionFactory::getInstance().createExpression<ExpressionBase >(node, NULL);

        delete expression;
    }
    catch(std::exception &)
    {
        CPPUNIT_ASSERT(false);
    }

    //CPPUNIT_ASSERT_NO_THROW(

    // Delete the parser, this also releases the parsed document
    parser->release();
}

Test *ExpressionFactoryTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("ExpressinoFactoryTest");

    // add the tests
    testSuite->addTest (new TestCaller<ExpressionFactoryTest>  ("testExpressionFactory_1", &ExpressionFactoryTest::testExpressionFactory_1));
    testSuite->addTest (new TestCaller<ExpressionFactoryTest>  ("testExpressionFactory_2", &ExpressionFactoryTest::testExpressionFactory_2));

    return testSuite;
}
