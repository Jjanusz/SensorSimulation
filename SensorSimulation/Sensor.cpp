#pragma once
#include "Sensor.h"




Sensor::Sensor(int idz, std::string typez, int minz, int maxz)
{
	id = idz;
	type = typez;
	maxvalue = maxz;
	minvalue = minz;
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
	clasificator.calcLimits(minvalue, maxvalue);
	while (true)
	{
		clasificator.classify(generate());
		std::this_thread::sleep_for(std::chrono::nanoseconds(period));
		std::cout << generate();
	}
}

void Sensor::setRange(int min, int max )
{
	maxvalue = max;
	minvalue = min;
}

void Sensor::setPeriod(float f)
{
	float fperiod = (1.0/f);
	fperiod=fperiod * 1000000000;
	period = static_cast<int>(fperiod);
}
