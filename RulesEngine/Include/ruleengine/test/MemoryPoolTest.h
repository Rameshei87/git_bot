#ifndef INC_MOMORYPOOLTEST_H
#define INC_MOMORYPOOLTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>
#include <ruleengine/internal/MemoryPool.h>

using namespace CppUnit;
using namespace ruleengine;

class MemoryPoolTest: public LT_TestCase
{
    public:
        MemoryPoolTest():LT_TestCase("MemoryPoolTest"){}
        void testMemoryPoolTest_1();
        //void testRuleConfig_2();
        static Test *suite();
};

#endif
