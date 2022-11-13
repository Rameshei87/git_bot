#ifndef INC_RULEENGINETEST_H
#define INC_RULEENGINETEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class RuleEngineTest: public LT_TestCase
{
    public:
        RuleEngineTest():LT_TestCase("RuleEngineTest"){}

        void testRuleEngine_1();

        static Test *suite();
};


#endif
