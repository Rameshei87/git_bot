#ifndef INC_BASETYPESTEST_H
#define INC_BASETYPESTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class BaseTypesTest: public LT_TestCase
{
    public:
        BaseTypesTest():LT_TestCase("BaseTypesTest"){}

        void testBaseTypes_boolean();
        void testBaseTypes_string();
        void testBaseTypes_int16();
        void testBaseTypes_int32();
        void testBaseTypes_int64();
        void testBaseTypes_uint16();
        void testBaseTypes_uint32();
        void testBaseTypes_uint64();
        void testBaseTypes_float();
        void testBaseTypes_double();
        static Test *suite();
};


#endif
