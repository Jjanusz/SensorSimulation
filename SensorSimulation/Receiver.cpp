#include "Receiver.h"

Receiver::Receiver(std::shared_ptr<Clasificator> clasificatorz)
{
	clasificator = clasificatorz;
}

void Receiver::message(int id, std::string type, int temp)
{
	std::cout << "$FIX, [" << id << "], [" << type << "], [" << temp << "], [" << clasificator->classify(temp) << "]" << '\n';
}

