
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
#include <ruleengine/internal/Rule.h>
#include <ruleengine/test/RuleTest.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>

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

void RuleTest::testRule_1()
{

    const char *ruleXML = 
        "       <rule consume-input=\"true\" multi-occurrent=\"true\">"
        "           <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "               <integer32-constant value=\"10\" />"
        "           </action>"
        "       </rule>";
        
    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(ruleXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    //RuleConfig ruleConfig(config);
    ParseContext *context=NULL;
    Rule rule(node,context);
    //RuleEngine engine;
    //engine.setInputContext(&inputContext);
    //engine.setOutputContext(&outputContext);

    //engine.start(&ruleConfig);

    //CPPUNIT_ASSERT(false);

    //CPPUNIT_ASSERT_NO_THROW(

    // Delete the parser, this also releases the parsed document
    parser->release();
}

Test *RuleTest::suite() 
{
    TestSuite *testSuite = new TestSuite ("RuleTest");

    // add the tests
    testSuite->addTest (new TestCaller<RuleTest>  ("testRule_1", &RuleTest::testRule_1));

    return testSuite;
}
