
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
#include <ruleengine/framework/ParseContext.h>
#include <ruleengine/internal/Action.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>
#include <ruleengine/test/ActionTest.h>

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
        if( inputCount ) return false;

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

void ActionTest :: testAction_1()
{

    const char *actionXML = "<action>"
        "   <integer32-constant value=\"10\" />"
        "</action>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(actionXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;
    
    //RuleConfig ruleConfig(config);

    //RuleEngine *engine;
    //engine.setInputContext(&inputContext);
    //engine.setOutputContext(&outputContext);
    ParseContext *context=NULL;
    Action action(node,context);
    ////action.execute(engine);
    //engine.start(&ruleConfig);

    //CPPUNIT_ASSERT(false);

    //CPPUNIT_ASSERT_NO_THROW(
    
    // Delete the parser, this also releases the parsed document
    parser->release();
}

Test *ActionTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("ActionTest");

    // add the tests
    testSuite->addTest (new TestCaller<ActionTest>  ("testAction_1", &ActionTest::testAction_1));

    return testSuite;
}
