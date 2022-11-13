#ifndef INC_CONDITIONTEST_H
#define INC_CONDITIONTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class ConditionTest: public LT_TestCase
{
    public:
        ConditionTest():LT_TestCase("ConditionTest"){}

        void testCondition_1();

        static Test *suite();
};


#endif
