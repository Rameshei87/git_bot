
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
#include <ruleengine/engine/RuleConfig.h>
//#include <ruleengine/test/FTC_Factorial.h>
#include <ruleengine/engine/InputContext.h>
#include <ruleengine/engine/OutputContext.h>

XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;

int_32 X = 5;
int_32 Y;

class GetX;
class SetY;

class GetX : public Integer32Expression
{
	public:
	GetX(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
    {
    }
  int_32 evaluate(RuleEngine *engine)
  {
    return X;
  }
};


class SetY : public VoidExpression, UnaryOperation<Integer32Expression>
{
	public:
	 SetY(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context) 
        : UnaryOperation<Integer32Expression>( element, context )
    {
    }
  void evaluate(RuleEngine *engine)
  {
    Y = operand1->evaluate(engine);
  }
};
void registerCustomOperations()
{
   ExpressionFactory *factory = &ExpressionFactory::getInstance();
   factory->registerExpression( "get-x", new PrimitiveCreator<GetX>() );
   factory->registerExpression( "set-y", new PrimitiveCreator<SetY>() );
}
    
class XInputContext : public InputContext
{
public:
  int X;
  //bool inputPresent;
  int count;

  XInputContext()
  {
    //inputPresent = true
    count=0;
  }

  void discardInput()
  {
    //inputPresent = false;
    count++;
  }

  bool isEmpty()
  {
    //return inputPresent;
    return (count==10);
  }
};


int main()
{
	  const char *ruleXML = 
                    "<rule-config input-type=\"factinput\" output-type=\"factoutput\">"
					"   <packet id=\"0\">"
					"       <rule consume-input=\"true\" multi-occurrent=\"true\">"
					"           <condition>"
					"               <boolean-constant value=\"true\" />"
					"           </condition>"
					"           <action>"
					"               <set-y>"
					"		<add-integer32-integer32>"
					"			<get-x/>"
					"			<integer32-constant value=\"10\"/>"
					"		</add-integer32-integer32>"
					"	</set-y>"
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

	registerBaseTypes();
	registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();
    registerCustomOperations();

    try
    {
        RuleConfig config(node);
        RuleEngine engine;
        {
            XInputContext inputContext;
            engine.setInputContext(&inputContext);
            //engine.setOutputContext(&outputContext);
            engine.start(&config);
			std::cout<<"X = "<<X<<std::endl;
			std::cout<<"Y = "<<Y<<std::endl;
			int abc;
			std::cin>>abc;
            //std::cout<<outputContext.getFactorial();
            //CPPUNIT_ASSERT_EQUAL(6, outputContext.getFactorial() );
        }

        
    }
    catch(...)
    {
        // Delete the parser, this also releases the parsed document
        parser->release();
        throw;
    }
}
