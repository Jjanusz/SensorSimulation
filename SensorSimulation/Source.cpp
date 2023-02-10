
#include "Sensor.h"
#include "JsonReader.h"
#include <filesystem>
#include <ios>
#include <istream>
#include <vector>
#include <memory>



int main()
{
	
	JsonReader sensorconfig;
	JsonReader decoderconfig;
	sensorconfig.ReadConfig();
	decoderconfig.ReadDecoderConfig();

	std::vector < std::unique_ptr<SomeSubscriber>> subscribers;
	std::vector<std::unique_ptr<Sensor>> Sensors;
	std::vector<std::thread> StartSensors;

	for (const auto& element : sensorconfig.data["Sensors"])
	{
		int sensorid = element.at("ID");
		float frequency = element.at("Frequency");
		int minvalue = element.at("MinValue");
		int maxvalue = element.at("MaxValue");
		std::string Type = element.at("Type");
		
		std::unique_ptr<Sensor> Sens(new Sensor(sensorid, Type, minvalue, maxvalue, frequency));
		for (const auto& element : decoderconfig.data["Decoders"])
		{
			int decoderid = element.at("ID");
			int associatedsensorid = element.at("ConnectedSensorID");
			if (associatedsensorid == sensorid)
			{
				std::unique_ptr<SubscriberIf> subscriber(new SomeSubscriber(decoderid));
				
				Sens->registerSubscriber(*subscriber);
			}
			
		}
		
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