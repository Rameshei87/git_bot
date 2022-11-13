
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>

#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/Types.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/test/BaseTypesTest.h>
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
void BaseTypesTest :: testBaseTypes_boolean()
{

    const char *exprXML = "<boolean-constant value=\"true\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    CPPUNIT_ASSERT_EQUAL(true, ExpressionFactory::getInstance().createExpression<BooleanExpression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_string()
{

    const char *exprXML = "<string-constant value=\"lifetree\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    CPPUNIT_ASSERT_EQUAL(std::string("lifetree"), ExpressionFactory::getInstance().createExpression<StringExpression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_int16()
{

    const char *exprXML = "<integer16-constant value=\"10\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //Integer16Constant int16obj(node,context);
    int_16 ret=10;
    CPPUNIT_ASSERT_EQUAL(ret, ExpressionFactory::getInstance().createExpression<Integer16Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_int32()
{

    const char *exprXML = "<integer32-constant value=\"100\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //Integer32Constant int32obj(node,context);
    CPPUNIT_ASSERT_EQUAL((int_32)100, ExpressionFactory::getInstance().createExpression<Integer32Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_int64()
{

    const char *exprXML = "<integer64-constant value=\"1000\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //Integer64Constant int64obj(node,context);
    CPPUNIT_ASSERT_EQUAL((int_64)1000, ExpressionFactory::getInstance().createExpression<Integer64Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_uint16()
{

    const char *exprXML = "<unsigned-integer16-constant value=\"50\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //UnsignedInteger16Constant uint16obj(node,context);
    CPPUNIT_ASSERT_EQUAL((uint_16)50, ExpressionFactory::getInstance().createExpression<UnsignedInteger16Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_uint32()
{

    const char *exprXML = "<unsigned-integer32-constant value=\"500\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //UnsignedInteger32Constant uint32obj(node,context);
    CPPUNIT_ASSERT_EQUAL((uint_32)500, ExpressionFactory::getInstance().createExpression<UnsignedInteger32Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_uint64()
{

    const char *exprXML = "<unsigned-integer64-constant value=\"5000\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //UnsignedInteger64Constant uint64obj(node,context);
    CPPUNIT_ASSERT_EQUAL((uint_64)5000,ExpressionFactory::getInstance().createExpression<UnsignedInteger64Expression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_float()
{

    const char *exprXML = "<float-constant value=\"100.9\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //FloatConstant floatobj(node,context);
    CPPUNIT_ASSERT_EQUAL((float)100.9 , ExpressionFactory::getInstance().createExpression<FloatExpression>(node,context)->evaluate(NULL));
  
    parser->release();
}
void BaseTypesTest :: testBaseTypes_double()
{

    const char *exprXML = "<double-constant value=\"1000\"/>";
        

    XMLPlatformUtils::Initialize();
    const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };

    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    parser->setFeature(XMLUni::fgDOMNamespaces, false);
    parser->setFeature(XMLUni::fgXercesSchema, false);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);

    XERCES_CPP_NAMESPACE::DOMDocument *doc = XercesHelpers::createDocumentFromString(exprXML,parser);
    XERCES_CPP_NAMESPACE::DOMElement *node = doc->getDocumentElement();

    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

    TestInputContext inputContext;
    TestOutputContext outputContext;

    ParseContext *context=NULL;
    //DoubleConstant doubleobj(node,context);
    CPPUNIT_ASSERT_EQUAL((double)1000,ExpressionFactory::getInstance().createExpression<DoubleExpression>(node,context)->evaluate(NULL) );
  
    parser->release();
}
Test *BaseTypesTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("BaseTypesTest");

    // add the tests
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_boolean", &BaseTypesTest::testBaseTypes_boolean));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_string", &BaseTypesTest::testBaseTypes_string));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_int16", &BaseTypesTest::testBaseTypes_int16));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_int32", &BaseTypesTest::testBaseTypes_int32));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_int64", &BaseTypesTest::testBaseTypes_int64));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_uint16", &BaseTypesTest::testBaseTypes_uint16));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_uint32", &BaseTypesTest::testBaseTypes_uint32));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_uint64", &BaseTypesTest::testBaseTypes_uint64));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_float", &BaseTypesTest::testBaseTypes_float));
    testSuite->addTest (new TestCaller<BaseTypesTest>  ("testBaseTypes_double", &BaseTypesTest::testBaseTypes_double));
    return testSuite;
}
