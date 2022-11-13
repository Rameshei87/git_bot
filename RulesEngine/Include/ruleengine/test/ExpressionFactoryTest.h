#ifndef INC_EXPRESSIONFACTORYTEST_h
#define INC_EXPRESSIONFACTORYTEST_h

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class ExpressionFactoryTest: public LT_TestCase
{
    public:
        ExpressionFactoryTest():LT_TestCase("ExpressionFactoryTest"){}
        void setUp();
        void testExpressionFactory_1();
        void testExpressionFactory_2();

        static Test *suite();
};

#endif
