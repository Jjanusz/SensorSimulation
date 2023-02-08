#include "JsonReader.h"






void JsonReader::ReadConfig()
{
	std::string temppath = std::filesystem::current_path().string() + "\\sensorConfig.json";
	std::ifstream f(temppath);
	if (f.fail())
	{
		std::cout << "Config file couldnt be opened";
	}
	else
	{
		try
		{
			data = json::parse(f);
		}
		catch (json::parse_error& e)
		{
			// output exception information
			std::cout << "message: " << e.what() << '\n'
				<< "exception id: " << e.id << '\n'
				<< "byte position of error: " << e.byte << std::endl;
		}
	}
}
