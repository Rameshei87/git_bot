
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

int_32 X = 100;
int_32 Y;

class GetX;
class SetY;
class GetAbc;

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

/*
class GetAbc: public Integer32Expression
{
	public:
	GetAbc(XERCES_CPP_NAMESPACE::DOMElement* element, ParseContext* context)
    {
    }
  int_32 evaluate(RuleEngine *engine)
  {
    return 100;
  }
};
*/

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
   //factory->registerExpression( "get-integer32-variable", new PrimitiveCreator<GetAbc>() );
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
	/*
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
	  */
	

	  const char *ruleXML = 
        "<rule-config input-type=\"factinput\" output-type=\"factoutput\">"	 
	    "<declare-variables>"
		"<declare-integer32-variable name=\"??abc\" />"
	    "</declare-variables>"
        "   <packet id=\"0\">"
        "       <rule consume-input=\"true\" multi-occurrent=\"true\">"
		"           <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"        
		"           <action>"
        "               <set-integer32-variable name=\"??abc\">"
		"					<get-x/>"
		"				</set-integer32-variable>"
        "           </action>"  
		"		</rule>"		
		"       <rule consume-input=\"true\" multi-occurrent=\"true\">"
		"           <condition>"
        "               <equal-integer32-integer32>"
		"					<integer32-constant value=\"100\"/>"
		"					<integer32-constant value=\"100\"/>"
		"				</equal-integer32-integer32>"
        "           </condition>"        
        "           <action>"
        "               <set-y>"
		"					<add-integer32-integer32>"
		"						<integer32-variable name=\"??abc\"/>"
		"						<integer32-constant value=\"10\"/>"
		"					</add-integer32-integer32>"
		"				</set-y>"
        "           </action>"
        "		</rule>"		
        "   </packet>"
        "</rule-config>";

		/*
        "       <rule consume-input=\"true\" multi-occurrent=\"true\">"
		"           <condition>"
		"			<not>"
		"			<equal-integer32-integer32>"
		"				<integer32-variable name=\"??abc\"/>"
		"				<integer32-constant value=\"100\"/>"
		"			</equal-integer32-integer32>"
		"			</not>"
        "				</condition>"        
        "				<action>"
        "					<set-y>"
		"						<add-integer32-integer32>"
		"							<integer32-variable name=\"??abc\"/>"
		"							<integer32-constant value=\"120\"/>"
		"						</add-integer32-integer32>"
		"					</set-y>"
        "				</action>"
        "       </rule>"
        "   </packet>"
        "</rule-config>";
		*/

	/*
 const char *ruleXML = 
        "<rule-config input-type=\"factinput\" output-type=\"factoutput\">"	
		" <declare-variables>"
		"<declare-integer32-variable name=\"??abc\" />"
		" </declare-variables>" 
        "   <packet id=\"0\">"
        "   <rule consume-input=\"false\" multi-occurrent=\"true\">"		
		"           <condition>"
        "               <boolean-constant value=\"true\" />"
        "           </condition>"
		"           <action>"
        "               <set-integer32-variable name=\"??abc\">"
		"		<get-x/>"
		"	</set-integer32-variable>"
        "           </action>"
        "           <action>"
        "               <set-y>"
		"		<add-integer32-integer32>"
		"			<integer32-variable name=\"??abc\"/>"
		"			<integer32-constant value=\"1000\"/>"
		"		</add-integer32-integer32>"
		"	</set-y>"
        "           </action>"
        "       </rule>"
        "   </packet>"
        "</rule-config>";
*/

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
