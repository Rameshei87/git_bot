#ifndef INC_ENGINEPOOLTEST_h
#define INC_ENGINEPOOLTEST_h

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class EnginePoolTest: public LT_TestCase
{
    public:
        EnginePoolTest():LT_TestCase("EnginePoolTest"){}
        void setUp();
        void testEnginePool_1();
        //void testRuleConfig_2();

        static Test *suite();
};

#endif
