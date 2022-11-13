
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>

#include <ruleengine/engine/XercesHelpers.h>
//#include <ruleengine/framework/BaseTypes.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/RuleConfig.h>
#include <ruleengine/test/RuleEngineTest.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>

XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;

class RuleEngineTestInputContext : public InputContext
{
    int inputCount;

public:

    RuleEngineTestInputContext()
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

class RuleEngineTestOutputContext : public OutputContext
{
};

void RuleEngineTest :: testRuleEngine_1()
{

    const char *ruleXML = 
        "<rule-config>"
        "   <packet id=\"0\">"
        "       <rule consume-input=\"true\" multi-occurrent=\"true\">"
        "           <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "               <integer32-constant value=\"10\" />"
        "           </action>"
        "       </rule>"
        "   </packet>"
        "</rule-config>";

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(ruleXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    try
    {
    RuleEngineTestInputContext inputContext;
    RuleEngineTestOutputContext outputContext;
    RuleConfig config(node);
    RuleEngine engine;
    engine.setInputContext(&inputContext);
    engine.setOutputContext(&outputContext);

    engine.start(&config);
    }

    //CPPUNIT_ASSERT(false);

    //CPPUNIT_ASSERT_NO_THROW(
    catch(...)
    {
    // Delete the parser, this also releases the parsed document
    parser->release();
    }
}

Test *RuleEngineTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("RuleEngineTest");

    // add the tests
    testSuite->addTest (new TestCaller<RuleEngineTest>  ("testRuleEngine_1", &RuleEngineTest::testRuleEngine_1));

    return testSuite;
}
