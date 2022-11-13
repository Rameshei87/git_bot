
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
#include <ruleengine/internal/RulePacket.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>
#include <ruleengine/test/RulePacketTest.h>

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

void RulePacketTest :: testRulePacket_1()
{

    const char *rulePacketXML = 
        "   <packet id=\"0\">"
        "       <rule consume-input=\"true\" multi-occurrent=\"true\">"
        "           <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "               <integer32-constant value=\"10\" />"
        "           </action>"
        "       </rule>"
        "   </packet>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(rulePacketXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    //RuleConfig ruleConfig(config);

    //RuleEngine engine;
    //engine.setInputContext(&inputContext);
    //engine.setOutputContext(&outputContext);
    ParseContext *context=NULL;
    RulePacket rulepacket(node,context);
    //engine.start(&ruleConfig);

    //CPPUNIT_ASSERT(false);

    //CPPUNIT_ASSERT_NO_THROW(

    // Delete the parser, this also releases the parsed document
    parser->release();
}

Test *RulePacketTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("RulePacketTest");

    // add the tests
    testSuite->addTest (new TestCaller<RulePacketTest>  ("testRulePacket_1", &RulePacketTest::testRulePacket_1));

    return testSuite;
}
