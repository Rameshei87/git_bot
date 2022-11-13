#include <cppunit/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TextTestProgressListener.h>
#include <LT_TestCase.h>

#include <ruleengine/test/ActionTest.h>
#include <ruleengine/test/BaseTypesTest.h>
#include <ruleengine/test/ConditionTest.h>
#include <ruleengine/test/EnginePoolTest.h>
#include <ruleengine/test/ExpressionFactoryTest.h>
#include <ruleengine/test/OperationTest.h>
#include <ruleengine/test/RuleConfigTest.h>
#include <ruleengine/test/RuleEngineTest.h>
#include <ruleengine/test/RulePacketTest.h>
#include <ruleengine/test/RuleTest.h>
//#include <ruleengine/test/FTC_PrefixToInfix.h>
#include <ruleengine/test/MemoryPoolTest.h>

#include <ABL_RWLock.h>

using namespace CppUnit;


int main( int argc, char* argv[] )
{
	TestResult controller;
	TestResultCollector result;
	controller.addListener( &result );
	TextTestProgressListener progress;
	controller.addListener( &progress );
	TestRunner runner;
	//LT_TestCase *ptr;

    runner.addTest( ActionTest::suite() );
    runner.addTest( BaseTypesTest::suite() );
    runner.addTest( ConditionTest::suite() );
    runner.addTest( ExpressionFactoryTest::suite() );
    runner.addTest( OperationTest::suite() );
    runner.addTest( RuleConfigTest::suite() );
    runner.addTest( RuleEngineTest::suite() );
    runner.addTest( RulePacketTest::suite() );
    runner.addTest( RuleEngineTest::suite() );
    runner.addTest( RuleTest::suite() );
 //   runner.addTest( FTC_Factorial::suite() );
//    runner.addTest( FTC_PrefixToInfix::suite() );
    runner.addTest( MemoryPoolTest::suite() );

    runner.run( controller );
	CompilerOutputter outputter( &result, stdCOut() );
	outputter.write();
	return result.wasSuccessful() ? 0 : 1;
}
