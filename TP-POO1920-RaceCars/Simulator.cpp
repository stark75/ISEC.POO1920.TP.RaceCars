#include "Simulator.h"


Simulator::Simulator()
{
}

bool Simulator::addCar(int e, int mE, std::string b, std::string m)
{
    Car tmpCar(e,mE,b,m);
	return false;
}

bool Simulator::addPilot(std::string newName)
{
    Pilot tmpPilot(newName);
	return false;
}