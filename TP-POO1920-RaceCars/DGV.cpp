#include "DGV.h"
#include "View.h"
#include <algorithm>

DGV::DGV()
{
	
}

DGV::~DGV()
{
	//todo libertar memoria dos vetores

	int pilotVectorSize = pilotList.size();

	if (pilotVectorSize > 0)
		for (int i = pilotVectorSize - 1; i >= 0; i--)
			delete pilotList[i];

	pilotList.clear();


	int carVectorSize = carList.size();

	if (carVectorSize > 0)
		for(int i = carVectorSize - 1; i >= 0; i--)
			delete carList[i];

	carList.clear();
	
	
}

bool DGV::addCar(const Car newCar)
{
	carList.push_back(new Car(newCar));
	return true;
}


bool DGV::addPilot(const Pilot newPilot)
{
	pilotList.push_back(new Pilot(newPilot));
	return true;
}

void DGV::printPilots()
{
	int vectorSize = pilotList.size();
	for (int i = 0; i < vectorSize; i++)
		std::cout << *pilotList[i] << std::endl;
}

void DGV::printPosition()
{
	int vectorSize = carList.size();
	for (int i = 0; i < vectorSize; i++)
		std::cout << *carList[i] << std::endl;
}

bool DGV::sortFunc(Car *lhs, Car *rhs)
{
	return lhs->getPosition() > rhs->getPosition();
}

void DGV::sortCarsByPosition()
{
	printPosition();
	std::vector<Car*> vectorCopy = carList;

	std::sort(vectorCopy.begin(),vectorCopy.end(), sortFunc);
	View::printMessage("Vector Sorted.", View::SuccessTypeMessage);
	
	carList = vectorCopy;
	printPosition();
}