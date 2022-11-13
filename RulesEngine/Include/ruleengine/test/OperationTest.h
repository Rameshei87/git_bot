#ifndef INC_OPERATIONTEST_H
#define INC_OPERATIONTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class OperationTest : public LT_TestCase
{
    public:
        OperationTest():LT_TestCase("ExpressionFactoryTest"){}

        void testOperationTest_1();
		void testOperationTest_2();
        static Test *suite();
};


#endif
