#pragma once
#include  "Clasificator.h"
#include  <string>


std::string Clasificator::classify(int value)
{
	std::string alarm = "Alarm";
	std::string normal = "Normal";
	std::string warning = "Warning";

	if (value >= minnormal && value <= maxnormal)
	{
		return normal;
	}
	else if (value >= minwarning && value <= maxwarning)
	{
		return warning;
	}
	else
	{
		return alarm;
	}
	
}

void Clasificator::calcLimits(float min, float max)
{
	 minnormal = (max - min) * (warning + alarm) + min;
	 maxnormal = (max - min) * (1.0 - warning - alarm) + min;
	 minwarning = (max - min) * (alarm) + min;
	 maxwarning = (max - min) * (1.0 - alarm) + min;
}