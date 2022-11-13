#ifndef INC_RULEPACKETTEST_H
#define INC_RULEPACKETTEST_H

#include <cppunit/TestCase.h>
#include <LT_TestCase.h>

using namespace CppUnit;


class RulePacketTest: public LT_TestCase
{
    public:
        RulePacketTest():LT_TestCase("RulePacketTest"){}

        void testRulePacket_1();

        static Test *suite();
};


#endif
