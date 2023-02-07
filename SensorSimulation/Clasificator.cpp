#pragma once
#include  "Clasificator.h"
#include  <string>

Clasificator::Clasificator(int min, int max)
{
	calcLimits(min, max);

};
std::string Clasificator::classify(int)
{
	
	
	
	std::string alarm = "Alarm";

	return alarm;
}



void Clasificator::calcLimits(int min, int max)
{

}