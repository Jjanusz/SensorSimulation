#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <thread >
#include <random>
#include <mutex>
#include "Clasificator.h"
class Sensor
{
public:

	static std::mutex mutex;
	Sensor(int, std::string, int, int, float);
	Clasificator clasificator;

	int generate();
	void setRange(int minvalue,int maxvalue);
	void setPeriod(float frequency);
	void startSensor();
	void Start();

private:
	int id;
	std::string type;
	int period;
	int maxvalue;
	int minvalue;
};

