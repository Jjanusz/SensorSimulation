
#include "Sensor.h"
#include "JsonReader.h"
#include <filesystem>
#include <ios>
#include <istream>
#include <vector>
#include <memory>



int main()
{

	JsonReader config;
	config.ReadConfig();
	std::shared_ptr<Clasificator> clasificator(new Clasificator());
	std::vector<std::thread> StartSensors;
	std::unique_ptr<Sensor> sens;
	for (const auto& element : config.data["Sensors"])
	{
		int id = element.at("ID");
		float frequency = element.at("Frequency");
		int minvalue = element.at("MinValue");
		int maxvalue = element.at("MaxValue");
		std::string Type = element.at("Type");

		std::shared_ptr<Receiver> receiver = std::make_unique<Receiver>(clasificator);
		std::unique_ptr<Sensor> sens = std::make_unique<Sensor>(id, Type, minvalue, maxvalue, frequency, receiver);
		StartSensors.push_back(std::thread(&Sensor::startSensor,  std::move(sens)));
		
	}

	for (std::thread& i : StartSensors)
	{
		if (i.joinable())
		{
			i.join();
		}
	}
}