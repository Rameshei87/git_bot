#ifndef INC_FTC_Factorial_H
#define INC_FTC_Factorial_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class FTC_Factorial: public LT_TestCase
{
    public:
        FTC_Factorial():LT_TestCase("FTC_Factorial"){}

        void test_1();

        static Test *suite();
};


#endif
