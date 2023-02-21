#pragma once
#include "Sensor.h"

Sensor::Sensor(int idz, std::string typez, int minz, int maxz, float frequencyz, std::shared_ptr<Receiver> receiverz)
	: id(idz), type(typez), minvalue(minz), maxvalue(maxz), receiver(receiverz)
{
	
	setPeriod(frequencyz);
	
}

int Sensor::generate()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minvalue, maxvalue);
	return distrib(gen);
}

void Sensor::startSensor()
{
	while (true)
	{
		int temp = generate();
		{
			std::unique_lock<std::mutex> lock(mutex);
			receiver->message(id,type,temp);
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(period));
	}
}

void Sensor::setPeriod(float f)
{
	float fperiod = (1.0f / f);
	fperiod = fperiod * 1000000000;
	period = static_cast<int>(fperiod);
}

std::mutex Sensor::mutex;
