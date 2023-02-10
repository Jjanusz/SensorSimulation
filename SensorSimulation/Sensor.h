#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <thread >
#include <random>
#include <mutex>
#include <functional >
#include "Clasificator.h"

class SubscriberIf
{
public:

    virtual void recvPublishedData(int data, std::string message, int id, std::string type) = 0;
};



class Sensor
{
public:

	static std::mutex mutex;
	Sensor(int, std::string, int, int, float);

    Clasificator clasificator;
	int generate();
	void setPeriod(float frequency);
	void startSensor();
	void Start();
    void registerSubscriber(SubscriberIf& subscriber)
    {
        subscribers.push_back(&subscriber);
    }

    void publishData(int data, std::string message, int id, std::string type);
      
   
private:
	int id;
	std::string type;
	int period;
	int maxvalue;
	int minvalue;
    std::vector<SubscriberIf*> subscribers;
};


class SomeSubscriber : public SubscriberIf
{
public:

    // Construct a subscriber and set its name
    SomeSubscriber(int idz) : id(idz)
    {

    }

    // From SubscriberIf
    virtual void recvPublishedData(int data, std::string message, int id, std::string type)
    {

        std::cout << "$FIX, [" << id << "], [" << type << "], [" << data << "], [" << message << "]" << '\n';
    }

private:
    int id;
};




