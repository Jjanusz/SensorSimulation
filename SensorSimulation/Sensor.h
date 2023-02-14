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
	Sensor(int, std::string, int, int, float);
	static std::mutex mutex;
	Clasificator clasificator;

	int generate();
	void setPeriod(float frequency);
	void startSensor();

private:
	int id;
	std::string type;
	int period;
	int maxvalue;
	int minvalue;
};

