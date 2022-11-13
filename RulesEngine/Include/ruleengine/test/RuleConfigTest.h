#ifndef INC_RULECONFIGTEST_h
#define INC_RULECONFIGTEST_h

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class RuleConfigTest: public LT_TestCase
{
    public:
        RuleConfigTest():LT_TestCase("RuleConfigTest"){}
        //void setUp();
        void testRuleConfig_1();
        void testRuleConfig_2();
        void testRuleConfig_3();
        static Test *suite();
};

#endif
