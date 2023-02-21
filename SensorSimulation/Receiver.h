#pragma once
#include <iostream>
#include "Clasificator.h"


class Receiver
{
public:
	Receiver(std::shared_ptr<Clasificator> clasificatorz);
	void message(int id, std::string type, int temp);
	
private:
	std::shared_ptr<Clasificator> clasificator;
};