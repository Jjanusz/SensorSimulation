#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <thread >
#include <random>
#include <mutex>
#include "Clasificator.h"
#include "Receiver.h"


class Sensor
{
public:
	Sensor(int, std::string, int, int, float, std::shared_ptr<Receiver> receiverz);
	static std::mutex mutex;
	std::shared_ptr<Receiver> receiver;

	virtual int generate();
	void setPeriod(float frequency);
	virtual void startSensor();
	virtual ~Sensor()=default;
private:
	int id;
	std::string type;
	int period;
	int maxvalue;
	int minvalue;
};
