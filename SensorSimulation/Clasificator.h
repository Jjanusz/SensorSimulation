#pragma once

#include <string>







class Clasificator
{
	
public:
	using LimitRange = std::pair<float, float>;
	void calcLimits(float, float);
	std::string classify(int) const;
	LimitRange calcLimitRange(float min, float max, float width) const;
private:
	float alarm = 0.1f;
	float warning = 0.15f;
	float minnormal;
	float maxnormal;
	float minwarning;
	float maxwarning;
};
