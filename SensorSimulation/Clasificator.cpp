#include "Constants.h"
#include  "Clasificator.h"
#include  <string>
#include <tuple>

std::string Clasificator::classify(int value) const
{

	if (value >= minnormal && value <= maxnormal)
	{
		return normaltext;
	}
	else if (value >= minwarning && value <= maxwarning)
	{
		return warningtext;
	}
	else
	{
		return alarmtext;
	}
	
}

Clasificator::LimitRange Clasificator::calcLimitRange(float min, float max, float width) const
{
	const float tmpmin = (max - min) * width + min;
	const float tmpmax = (max - min) * (1.0 - width) + min;
	return std::make_pair(tmpmin, tmpmax);
}
void Clasificator::calcLimits(float min, float max)
{

	std::tie(minnormal, maxnormal) = calcLimitRange(min, max, warning + alarm);
	std::tie(minwarning, maxwarning) = calcLimitRange(min, max, alarm);
	
}

