#include "DGV.h"
#include "View.h"
#include <algorithm>

DGV::DGV()
{
	
}

DGV::~DGV()
{
	//todo libertar memoria dos vetores
}

bool DGV::addCar(const Car newCar)
{
	carNames.push_back(new Car(newCar));
	Car* tmpCar = carNames.back();

	
	if(tmpCar==newCar)
	{
		View::printMessage("Car copied correctly", View::SuccessTypeMessage);
		return true;
	}
	return false;
}


bool DGV::addPilot(const Pilot newPilot)
{
	return false;
}

void DGV::printPosition()
{
	for (int i = 0; i < static_cast<int>(carNames.size()); i++)
		std::cout << *carNames[i] << std::endl;
}

bool DGV::sortFunc(Car *lhs, Car *rhs)
{
	return lhs->getPosition() > rhs->getPosition();
}

void DGV::sortCarsByPosition()
{
	printPosition();
	std::vector<Car*> vectorCopy = carNames;

	std::sort(vectorCopy.begin(),vectorCopy.end(), sortFunc);
	View::printMessage("Vector Sorted.", View::SuccessTypeMessage);
	
	carNames = vectorCopy;
	printPosition();
}