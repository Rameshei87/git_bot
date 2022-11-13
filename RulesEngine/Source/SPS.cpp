
#include <iostream>

#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ExpressionFactory.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/engine/RuleConfig.h>
#include <ruleengine/internal/FactInterfaceInputContext.h>
#include <ProvRequest.h>

XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace ruleengine;
        
int main()
{

    XMLPlatformUtils::Initialize();

    XERCES_CPP_NAMESPACE::DOMBuilder *parser=NULL;
    try
    {
		registerBaseTypes();
		registerArithmeticOperations();
		registerComparisonOperations();
		registerLogicalOperations();
		FactInterfaceInputContext :: initialize();

		RuleConfig *config;
        const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };
        DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
        parser = (static_cast<DOMImplementationLS*>(impl))->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
        parser->setFeature(XMLUni::fgDOMNamespaces, false);
        parser->setFeature(XMLUni::fgXercesSchema, false);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
        
		XERCES_CPP_NAMESPACE::DOMDocument *_sourceDoc = parser->parseURI("/home/sps/06-Provisioning/branches/SPS_5.1.0.0/trunk/RulesEngine/Source/rules2.xml");
        if(_sourceDoc == NULL)
        {
            cout<<"rules xml does not exist.. "<<endl;
            throw;
        }
        XERCES_CPP_NAMESPACE::DOMElement *node = _sourceDoc->getDocumentElement();

        if(node == NULL)
        {
            //check eror code .
            cout<<"rules xml is not valid.. "<<endl;
            throw;
        }
        config = new ruleengine::RuleConfig(node);
        parser->release(); //releasing the parser.
		std::cout<<"OK1"<<std::endl;

		SPS::Request::HeapCreate(100);
		SPS::Request *admessage = new SPS::Request();

		admessage->globalParamMap["NM"] = "9448865560";
		admessage->globalParamMap["OM"] = "08628233677";
		
		std::cout<<"OK1"<<std::endl;
		RuleEngine engine;
		FactInterfaceInputContext inputContext(admessage);
		std::cout<<"OK2"<<std::endl;
		engine.setInputContext(&inputContext);
		std::cout<<"OK3"<<std::endl;
		engine.start(config, "HLR");
		std::cout<<"OK4"<<std::endl;
		std::cout << admessage->GetGlobalParamValue("MSISDN") << std::endl;;
		delete config;
		delete admessage;
		int xyz;
		std::cin>>xyz;
		XMLPlatformUtils::Terminate();
    }      
    catch(...)
    {
        throw;
    }
}
