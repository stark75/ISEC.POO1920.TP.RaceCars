#include "Simulator.h"


Simulator::Simulator()
{
}

DGV* Simulator::getDGV()
{
	return &currentDGV;
}

bool Simulator::attach(char carID, std::string pilotName)
{
	return currentDGV.attach(carID, pilotName);
}

bool Simulator::detach(char carID)
{
	return currentDGV.detach(carID);
}

bool Simulator::addCar(int e, int mE, int mS, std::string b, std::string m)
{
    Car tmpCar(e,mE, mS,b,m);
	return currentDGV.addCar(tmpCar);
}

bool Simulator::addPilot(std::string type, std::string newName)
{
	if (type == "generico")
	{
		Pilot tmpPilot(newName);
		return currentDGV.addPilot(tmpPilot);
	}
	
	if (type == "crazy")
	{
		//TODO
	}

	if (type == "rapido")
	{
		//TODO
	}

	if (type == "surpresa")
	{
		//TODO
	}

	return false;
}

bool Simulator::addRacetrack(int maxCars, int length, std::string newName)
{
	Racetrack tmpRacetrack(maxCars,length,newName);
	racetracks.push_back(tmpRacetrack);
	return true;
}
