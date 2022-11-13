#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>
#include <ABL_ThreadMacro.h>
#include <ruleengine/framework/ArithmeticOperations.h>
#include <ruleengine/framework/ComparisonOperations.h>
#include <ruleengine/framework/LogicalOperations.h>
#include <ruleengine/engine/XercesHelpers.h>
#include <ruleengine/engine/EnginePool.h>
#include <ruleengine/engine/RuleEngine.h>
#include <ruleengine/test/EnginePoolTest.h>

XERCES_CPP_NAMESPACE_USE
using namespace CppUnit;
using namespace std;
using namespace ruleengine;

class TestEngine
{
 public:
   static int_16 count;
    //int_16 count=0;
   
    void testEng()
    {  
        /*std::cout<<"Inside TestEngine Function...\n"<<std::endl;*/
        for(int_16 i=0; i<10;i++)
        {
             /*std::cout<<"Inside loop...\n"<<std::endl;*/
             count++;
             RuleEngine *engine = EnginePool ::getInstance().getEngine();
             for(uint_32 i=0;i<10000;i++);
             /*std::cout << "Counting = " << count << std::endl;*/
             if(count>10)
             {
                /* std::cout<<"Counting...."<<std::endl;*/
                 CPPUNIT_ASSERT(false);
             }
                 EnginePool ::getInstance().releaseEngine(engine);
                 count--;
         }
    }
};
int_16 TestEngine::count = 0;

void EnginePoolTest::setUp()
{
    //RegisterArithmeticOperations
    registerBaseTypes();
    registerArithmeticOperations();
    registerComparisonOperations();
    registerLogicalOperations();

}


void EnginePoolTest :: testEnginePool_1()
{
    EnginePool::getInstance().setPoolSize(10);
   
    pthread_t t1[20];

    for(uint_16 i=0;i<20;i++)
    {
        TestEngine t;
        ExecuteInNewThread0(&t1[i], NULL, TestEngine, t, void, &TestEngine::testEng);
    }
       for(uint_16 i=0;i<20;i++)
    {
 //       pthread_join(t1[i],NULL);
    }

    
}

Test *EnginePoolTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("EnginePoolTest");

    // add the tests
    testSuite->addTest (new TestCaller<EnginePoolTest>  ("testEnginePool_1", &EnginePoolTest::testEnginePool_1));

    return testSuite;
}
