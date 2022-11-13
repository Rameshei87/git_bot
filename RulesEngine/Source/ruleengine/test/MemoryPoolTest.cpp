#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>
#include <ruleengine/framework/BaseVariables.h>
#include <ruleengine/test/MemoryPoolTest.h>


void MemoryPoolTest::testMemoryPoolTest_1()
{
    VariableMemory* varMemory = MemoryPool::getInstance().getMemory(200);
    MemoryPool::getInstance().releaseMemory(varMemory);
    CPPUNIT_ASSERT(true);
}

Test *MemoryPoolTest::suite () 
{
    TestSuite *testSuite = new TestSuite ("OperationTest");

    // add the tests
    testSuite->addTest (new TestCaller<MemoryPoolTest>  ("testMemoryPoolTest_1", &MemoryPoolTest::testMemoryPoolTest_1));

    return testSuite;
}
