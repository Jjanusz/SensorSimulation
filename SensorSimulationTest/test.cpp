#include "pch.h"
#include "../SensorSimulation/Sensor.h"
#include "../SensorSimulation/Clasificator.h"
#include "../SensorSimulation/Constants.h"
using namespace testing;


TEST(Classificator, NormalPositive)
{
    //minwarning = 10 maxwarning = 90
     //minnormal = 25 maxnormal = 75
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(50), normaltext);
    EXPECT_EQ(x.classify(25), normaltext);
    EXPECT_EQ(x.classify(26), normaltext);
}


TEST(Classificator, AlarmPositive)
{
    //minwarning = 10 maxwarning = 90
    //minnormal = 25 maxnormal = 75
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(92), alarmtext);
    EXPECT_EQ(x.classify(6), alarmtext);
}


TEST(Classificator, WarningPositive)
{
    //minwarning = 10 maxwarning = 90
    //minnormal = 25 maxnormal = 75
    Clasificator x;
    x.calcLimits(0, 100);
    EXPECT_EQ(x.classify(80), warningtext);
    EXPECT_EQ(x.classify(20), warningtext);
}


TEST(Classificator, NormalOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(30), normaltext);
    EXPECT_EQ(x.classify(60), normaltext);
}


TEST(Classificator, AlarmOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(-55), alarmtext);
    EXPECT_EQ(x.classify(94), alarmtext);
}


TEST(Classificator, WarningOneNegative)
{
    //minwarning = -44 maxwarning = -84
    //minnormal = -20 maxnormal = 60
    Clasificator x;
    x.calcLimits(-60, 100);
    EXPECT_EQ(x.classify(-42), warningtext);
    EXPECT_EQ(x.classify(70), warningtext);
}


TEST(Classificator, NormalAllNegative)
{
    //minwarning = -190 maxwarning = -110
   //minnormal = -175 maxnormal = -125
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-150), normaltext);
    EXPECT_EQ(x.classify(-170), normaltext);
}

TEST(Classificator, AlarmAllNegative)
{
    //minwarning = -190 maxwarning = -110
   //minnormal = -175 maxnormal = -125
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-105), alarmtext);
    EXPECT_EQ(x.classify(-192), alarmtext);
}


TEST(Classificator, WarningAllNegative)
{
    //minwarning = -190 maxwarning = -110
   //minnormal = -175 maxnormal = -125
    Clasificator x;
    x.calcLimits(-200, -100);
    EXPECT_EQ(x.classify(-180), warningtext);
    EXPECT_EQ(x.classify(-120), warningtext);
}
