#pragma once

#include <string>







class Clasificator
{
public:
	void calcLimits(int, int);
	std::string classify(int);

private:
	float alarm = 0.1;
	float warning = 0.15;
	float minnormal;
	float maxnormal;
};
