#include "pch.h"
#include "../SensorSimulation/Sensor.h"
#include "../SensorSimulation/Clasificator.h"

using namespace testing;


TEST(Classificator, NormalPositive)
{
   
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(50), "Normal");
    EXPECT_EQ(x.classify(25), "Normal");
    EXPECT_EQ(x.classify(26), "Normal");
}


TEST(Classificator, AlarmPositive)
{
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(92), "Alarm");
    EXPECT_EQ(x.classify(6), "Alarm");
}


TEST(Classificator, WarningPositive)
{
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(80), "Warning");
    EXPECT_EQ(x.classify(20), "Warning");
}


TEST(Classificator, NormalOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(30), "Normal");
    EXPECT_EQ(x.classify(60), "Normal");
}


TEST(Classificator, AlarmOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(-55), "Alarm");
    EXPECT_EQ(x.classify(94), "Alarm");
}


TEST(Classificator, WarningOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(-42), "Warning");
    EXPECT_EQ(x.classify(70), "Warning");
}


TEST(Classificator, NormalAllNegative)
{
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-150), "Normal");
    EXPECT_EQ(x.classify(-170), "Normal");
}

TEST(Classificator, AlarmAllNegative)
{
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-105), "Alarm");
    EXPECT_EQ(x.classify(-192), "Alarm");
}


TEST(Classificator, WarningAllNegative)
{
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-180), "Warning");
    EXPECT_EQ(x.classify(-120), "Warning");
}
