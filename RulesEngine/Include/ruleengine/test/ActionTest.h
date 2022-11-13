#ifndef INC_ACTIONTEST_H
#define INC_ACTIONTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class ActionTest: public LT_TestCase
{
    public:
        ActionTest():LT_TestCase("ActionTest"){}

        void testAction_1();

        static Test *suite();
};


#endif
