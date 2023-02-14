#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <iostream>

using json = nlohmann::json;

class JsonReader
{
public:
	void ReadConfig();
	json data;

private:
};
