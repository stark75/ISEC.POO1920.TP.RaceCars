#include "Simulator.h"


Simulator::Simulator()
{
}

bool Simulator::addCar(int e, int mE, int mS, std::string b, std::string m)
{
    Car tmpCar(e,mE, mS,b,m);
	currentDGV.addCar(tmpCar);
	
	return false;
}

bool Simulator::addPilot(std::string newName)
{
    Pilot tmpPilot(newName);
	return false;
}