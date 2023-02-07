#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include "Clasificator.h"
#include <thread >
#include <random>
class Sensor
{
public:

	
	Sensor(int, std::string, int, int);
	Clasificator clasificator;

	int generate();
	void setRange(int,int);
	void setPeriod(float);
	void startSensor();
	

private:
	int id;
	std::string type;
	int period;
	int maxvalue;
	int minvalue;
};

