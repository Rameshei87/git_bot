#ifndef INC_RULETEST_H
#define INC_RULETEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class RuleTest: public LT_TestCase
{
    public:
        RuleTest():LT_TestCase("RuleTest"){}

        void testRule_1();

        static Test *suite();
};


#endif
