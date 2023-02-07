
#include "Sensor.h"



int main()
{

	


	Sensor Speed(1, "Speed",-200,-100);
	Sensor Position(2, "Position",-10000,10000) ;
	Sensor Depth(3, "Depth",0,255);

	Speed.setPeriod(2);
	Position.setPeriod(1);
	Depth.setPeriod(10);

	std::thread t1(&Sensor::startSensor, &Speed);
	std::thread t2(&Sensor::startSensor, &Position);
	std::thread t3(&Sensor::startSensor, &Depth);

	t1.join();
	t2.join();
	t3.join();
}