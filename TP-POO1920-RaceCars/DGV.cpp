#include "DGV.h"
#include "View.h"
#include <algorithm>

DGV::DGV(const DGV& src)
{
	int vectorSize = static_cast<int>(src.carList.size());
	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			carList.push_back(new Car(*src.carList[i]));
		}
	}

	vectorSize = static_cast<int>(src.pilotList.size());

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			pilotList.push_back(src.pilotList[i]->duplicate());
		}
	}

	detachAll();
}

DGV::~DGV()
{
	int pilotVectorSize = static_cast<int>(pilotList.size());

	if (pilotVectorSize > 0)
		for (int i = 0; i < pilotVectorSize; i++)
			delete pilotList[i];

	int carVectorSize = static_cast<int>(carList.size());

	if (carVectorSize > 0)
		for (int i = 0; i < carVectorSize; i++)
			delete carList[i];
}

std::vector<Car*> DGV::getCarList()
{
	return carList;
}

bool DGV::addCar(const Car newCar)
{
	carList.push_back(new Car(newCar));
	return true;
}

bool DGV::addCrazyPilot(const CrazyPilot& newPilot)
{
	pilotList.push_back(new CrazyPilot(newPilot));
	return true;
}

bool DGV::addFastPilot(const FastPilot& newPilot)
{
	pilotList.push_back(new FastPilot(newPilot));
	return true;
}

bool DGV::addSurprisePilot(const SurprisePilot& newPilot)
{
	pilotList.push_back(new SurprisePilot(newPilot));
	return true;
}

bool DGV::removeCar(const char wantedID)
{
	int vectorSize = static_cast<int>(carList.size());

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			char tmpID = carList[i]->getID();
			if (wantedID == tmpID)
			{
				Pilot* driver = carList[i]->getDriver();

				if(driver!=nullptr)
					driver->detach();

				delete carList[i];
				carList.erase(carList.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool DGV::removePilot(std::string wantedName)
{	
	int vectorSize = static_cast<int>(pilotList.size());

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			std::string tmpID = pilotList[i]->getName();
			if (wantedName == tmpID)
			{
				Car* currentCar = pilotList[i]->getCurrentCar();

				if(currentCar!=nullptr)
					currentCar->detach();
				
				delete pilotList[i];
				pilotList.erase(pilotList.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool DGV::printCars()
{
	int vectorSize = static_cast<int>(carList.size());
	if(vectorSize == 0)
		return false;
	for (int i = 0; i < vectorSize; i++)
		std::cout << *carList[i] << std::endl;
	return true;
}

bool DGV::printPilots()
{
	int vectorSize = static_cast<int>(pilotList.size());
	if(vectorSize == 0)
		return false;
	for (int i = 0; i < vectorSize; i++)
		std::cout << *pilotList[i] << std::endl;
	return true;
}

Car* DGV::getCarById(char wantedID)
{
	int vectorSize = static_cast<int>(carList.size());
	for(int i = 0; i < vectorSize; i++)
	{
		char tmpChar=carList[i]->getID();
		if (tmpChar == wantedID)
			return carList[i];
	}
	return nullptr;
}

Pilot* DGV::getPilotByName(std::string wantedName)
{
	int vectorSize = static_cast<int>(pilotList.size());
	for(int i = 0; i < vectorSize; i++)
	{
		std::string tmpString = pilotList[i]->getName();
		if (tmpString == wantedName)
			return pilotList[i];
	}
	return nullptr;
}

bool DGV::attach(char id, std::string name)
{
	Car*   tmpCar   = getCarById(id);
	Pilot* tmpPilot = getPilotByName(name);

	if(tmpCar!=nullptr && tmpPilot!=nullptr)
	{
		if (tmpCar->getDamage())
			return false;
		if (tmpCar->getDriver() != nullptr)
			return false;
		if (tmpPilot->getCurrentCar() != nullptr)
			return false;
		if (!tmpCar->attach(tmpPilot))
			return false;
		if(!tmpPilot->attach(tmpCar))
		{
			tmpCar->detach();
			return false;
		}
		return true;
	}
	return false;
}

bool DGV::detach(char id)
{
	Car* tmpCar = getCarById(id);

	if (tmpCar != nullptr)
	{
		Pilot* tmpPilot = tmpCar->getDriver();
		if (tmpPilot != nullptr)
		{
			if(tmpPilot->detach())
			{
				return tmpCar->detach();
			}
		}
	}
	return false;
}

void DGV::detachAll()
{
	int vectorSize = static_cast<int>(carList.size());
	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			carList[i]->detach();
		}
	}
	vectorSize = static_cast<int>(pilotList.size());
	if(vectorSize > 0)
	{
		for(int i = 0; i < vectorSize; i++)
		{
			pilotList[i]->detach();
		}
	}
}

std::vector<Car*> DGV::getCarsWithPilots()
{
	std::vector<Car*> newList;
	int vectorSize = static_cast<int>(carList.size());

	for(int i = 0; i < vectorSize; i++)
	{
		if (carList[i]->getDriver() != nullptr)
			newList.push_back(carList[i]);
	}

	return newList;
}

int DGV::getNumberOfCarsWithPilots()
{
	int numberOfCarsWithPilots = 0;

	int vectorSize = static_cast<int>(carList.size());
	
	for(int i = 0; i < vectorSize;i++)
	{
		if (carList[i]->getDriver() != nullptr)
			++numberOfCarsWithPilots;
	}

	return numberOfCarsWithPilots;
}

DGV& DGV::operator=(const DGV& src)
{
	//Cleaning the destination
	int vectorSize = static_cast<int>(this->pilotList.size());

	if (vectorSize > 0)
		for (int i = vectorSize - 1; i >= 0; i--)
			delete this->pilotList[i];

	this->pilotList.clear();

	vectorSize = static_cast<int>(this->carList.size());

	if (vectorSize > 0)
		for (int i = vectorSize - 1; i >= 0; i--)
			delete this->carList[i];

	this->carList.clear();

	//Assignment
	
	vectorSize = static_cast<int>(src.carList.size());

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			this->carList.push_back(new Car(*src.carList[i]));
		}
	}

	vectorSize = static_cast<int>(src.pilotList.size());

	if (vectorSize > 0)
	{
		for(int i = 0; i < vectorSize; i++)
		{
			this->pilotList.push_back(src.pilotList[i]->duplicate());
		}
	}

	this->detachAll();
	
	return *this;
}
