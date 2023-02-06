#include "pch.h"

#include "../SensorSimulation/Sensor.h"
#include "../SensorSimulation/Clasisificator.h"

using namespace testing;


MATCHER_P2(IsBetween, a, b,
    std::string(negation ? "isn't" : "is") + " between " + PrintToString(a)
    + " and " + PrintToString(b))
{
    return a <= arg && arg <= b;
}




class MockSensor
{
    public:

	MOCK_METHOD(int, Generate, ());
};


TEST(NumberGenerator, IsInRange)
{
    MockSensor mock;
    EXPECT_CALL(mock, Generate);
    EXPECT_THAT(Sensor::Generate, IsBetween(40, 46));
}





