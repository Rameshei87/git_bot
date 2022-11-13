
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>

#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/RuleConfig.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>

#include <ruleengine/test/RuleConfigTest.h>

XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;

class RuleConfigTestInputContext : public InputContext
{
    int inputCount;

public:

    RuleConfigTestInputContext()
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

class RuleConfigTestOutputContext : public OutputContext
{
};


void RuleConfigTest :: testRuleConfig_1()
{

    const char *exprXML =    
        "<rule-config input-type=\"\" output-type=\"\">"
        "   <packet id=\"0\">"
        "	    <rule multi-occurrent=\"true\" consume-input=\"false\">"
        "		    <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "                   <integer64-constant value=\"1000\"/>"
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

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();
    
    //Create Expression
    try
    {
        RuleConfigTestInputContext inputContext;
        RuleConfigTestOutputContext outputContext;
        RuleConfig config(node);
        RuleEngine engine;
        engine.setInputContext(&inputContext);
        engine.setOutputContext(&outputContext);
        engine.start(&config);
    }
    catch(std::exception &)
    {
        CPPUNIT_ASSERT(false);
    }
    // Delete the parser, this also releases the parsed document
    parser->release();
}

void RuleConfigTest :: testRuleConfig_2()
{

    const char *exprXML =    
        "<rule-config input-type=\"\" output-type=\"\">"
        "   <packet id=\"0\">"
        "	    <rule multi-occurrent=\"true\" consume-input=\"false\">"
        "		    <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "                   <integer64-constant value=\"1000\"/>"
        "           </action>"
        "       </rule>"
        "   </packet>"
        "</rule-config>";

    std::string exprString(exprXML);
   
    //Create Expression
    try
    {
        RuleConfigTestInputContext inputContext;
        RuleConfigTestOutputContext outputContext;
        RuleConfig config(exprString);
        RuleEngine engine;
        engine.setInputContext(&inputContext);
        engine.setOutputContext(&outputContext);
        engine.start(&config);
    }
    catch(std::exception &)
    {
        CPPUNIT_ASSERT(false);
    }
}


void RuleConfigTest :: testRuleConfig_3()
{

    const char *exprXML =    
        "<rule-config input-type=\"\" output-type=\"\">"
        "   <packet id=\"0\">"
        "	    <rule multi-occurrent=\"true\" consume-input=\"false\">"
        "		    <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
        "           <action>"
        "                   <integer64-constant value=\"1000\"/>"
        "           </action>"
        "       </rule>"
        "   </packet>"
        "</rule-config>";

    std::string exprString(exprXML);
    std::stringstream ss(exprString);
   
    //Create Expression
    try
    {
        RuleConfigTestInputContext inputContext;
        RuleConfigTestOutputContext outputContext;
        RuleConfig config(ss);
        RuleEngine engine;
        engine.setInputContext(&inputContext);
        engine.setOutputContext(&outputContext);
        engine.start(&config);
    }
    catch(std::exception &)
    {
        CPPUNIT_ASSERT(false);
    }
}


Test *RuleConfigTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("RuleConfigTest");
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    // add the tests
    testSuite->addTest (new TestCaller<RuleConfigTest>  ("testRuleConfig_1", &RuleConfigTest::testRuleConfig_1));
    testSuite->addTest (new TestCaller<RuleConfigTest>  ("testRuleConfig_2", &RuleConfigTest::testRuleConfig_2));
    testSuite->addTest (new TestCaller<RuleConfigTest>  ("testRuleConfig_3", &RuleConfigTest::testRuleConfig_3));

    return testSuite;
}
