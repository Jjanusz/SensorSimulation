
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
	
	std::vector<std::unique_ptr<Sensor>> Sensors;
	std::vector<std::thread> StartSensors;
	for (const auto& element : config.data["Sensors"])
	{
		int id = element.at("ID");
		float frequency = element.at("Frequency");
		int minvalue = element.at("MinValue");
		int maxvalue = element.at("MaxValue");
		std::string Type = element.at("Type");

		std::unique_ptr<Sensor> Sens(new Sensor(id, Type, minvalue, maxvalue, frequency));
		
		StartSensors.push_back(std::thread (&Sensor::startSensor, *Sens));
	}

	for (std::thread& i : StartSensors)
	{
		if (i.joinable())
		{
			i.join();
		}

	}

	
}