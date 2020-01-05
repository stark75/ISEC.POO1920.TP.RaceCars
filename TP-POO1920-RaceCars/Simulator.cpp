#include <iostream>
#include "Simulator.h"

Simulator::Simulator(): championship(nullptr)
{
}

Simulator::~Simulator()
{
	int vectorSize = racetracks.size();

	if (vectorSize > 0)
		for (int i = vectorSize - 1; i >= 0; i--)
			delete racetracks[i];

	racetracks.clear();

	delete championship;
}

DGV* Simulator::getDGV()
{
	return &currentDGV;
}

Championship* Simulator::getChampionship()
{
	return championship;
}

Racetrack* Simulator::getCurrentRace()
{
	return championship->getCurrentRacetrack();
}

std::vector<std::string> Simulator::getLog()
{
	return log;
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
	if (mE < 100 || mS < 1 || e < 0 || e > mE)
		return false;
	
    Car tmpCar(e,mE, mS,b,m);
	return currentDGV.addCar(tmpCar);
}

bool Simulator::addPilot(std::string type, std::string newName)
{
	if (type == "generico") //remover para a proxima meta
	{
		Pilot tmpPilot(newName);
		return currentDGV.addPilot(tmpPilot);
	}
	
	if (type == "crazy")
	{
		//TODO
		return false;
	}

	if (type == "rapido")
	{
		//TODO
		return false;
	}

	if (type == "surpresa")
	{
		//TODO
		return false;
	}

	return false;
}

bool Simulator::addRacetrack(int maxCars, int length, std::string newName)
{
	if (maxCars < 2 || length < 1)
		return false;
	
	Racetrack tmpRacetrack(maxCars, length, newName);
	racetracks.push_back(new Racetrack(tmpRacetrack));
	return true;
}

bool Simulator::addChampionship(std::string racetrack)
{
	std::vector<Car*> newList = currentDGV.getCarsWithPilots();

	if (newList.empty())
		return false;

	if (championship == nullptr)
	{
		championship = new Championship(getRacetrackByName(racetrack), newList);
		return true;
	}

	return false;
}

bool Simulator::addChampionship(std::vector<std::string> racetrackList)
{
	std::vector<Car*> newList = currentDGV.getCarsWithPilots();

	if(newList.empty())
		return false;

	if(championship == nullptr)
	{
		int vectorSize = racetrackList.size();
		std::vector<Racetrack*> championshipRacetracks;
		
		for(int i=0;i<vectorSize;i++)
		{
			championshipRacetracks.push_back(getRacetrackByName(racetrackList[i]));
		}

		championship = new Championship(championshipRacetracks, newList);
		return true;
	}
	return false;
}

bool Simulator::removeCar(char wantedID)
{
	return currentDGV.removeCar(wantedID);
}

bool Simulator::removePilot(std::string wantedName)
{
	return currentDGV.removePilot(wantedName);
}

bool Simulator::removeRacetrack(std::string wantedName)
{

	/* TODO
	 * if(racetrackIsInAChampionship())
	 * return false;
	 */
	
	int vectorSize = racetracks.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			std::string tmpID = racetracks[i]->getName();
			if (wantedName == tmpID)
			{
				delete racetracks[i];
				racetracks.erase(racetracks.begin() + i);
				return true;
			}
		}
	}

	return false;
}

bool Simulator::destroyCar(char wantedID)
{
	if (championship->removeCarFromChampionship(wantedID))
		return removeCar(wantedID);
	return false;
}

bool Simulator::accident(char wantedID)
{
	if(championship->accident(wantedID))
	{
		Car* tmpCar = currentDGV.getCarById(wantedID);
		Pilot* tmpPilot = tmpCar->getDriver();
		detach(wantedID);
		return removePilot(tmpPilot->getName());
	}
	return false;
}

int Simulator::checkIfItsPossibleToStartAChampionship(std::string tmpString)
{
	/*
	 * Returns 1 if it's Possible
	 * Returns 0 if the number of valid cars is invalid
	 * Returns -1 if the Racetrack is invalid
	 * Returns -2 if the both are invalid
	 */
	
	if (getRacetrackByName(tmpString) != nullptr && currentDGV.getNumberOfCarsWithPilots() >= 2)
		return 1;

	if (getRacetrackByName(tmpString) != nullptr && currentDGV.getNumberOfCarsWithPilots() < 2)
		return 0;

	if (getRacetrackByName(tmpString) == nullptr && currentDGV.getNumberOfCarsWithPilots() >= 2)
		return -1;

	return -2;
	
}

void Simulator::clearChampionship()
{
	delete championship;
	championship = nullptr;
}

void Simulator::addMessageToLog(std::string newMessage)
{
	log.push_back(newMessage);
}

bool Simulator::printRacetracks()
{
	int vectorSize = racetracks.size();
	if(vectorSize == 0)
		return false;
	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
			std::cout << racetracks[i]->getAsString() << std::endl;
	}
	return true;
}

void Simulator::chargeAllCars()
{
	if (championship != nullptr)
	{
		championship->chargeAllCars();
	}
}

bool Simulator::startRace()
{
	return championship->startRace();
}

bool Simulator::nextRace()
{
	return championship->nextRace();
}

bool Simulator::passOneSecond()
{
	bool pass = championship->passOneSecond();
	//getlog
	return pass;
}

void Simulator::updateStandings()
{
	championship->updateStandings();
}

bool Simulator::checkEndOfRace()
{
	if(championship->checkEndOfRace())
	{
		updateStandings();
		return true;
	}
	return false;
}

Racetrack* Simulator::getRacetrackByName(std::string wantedName)
{
	int vectorSize = racetracks.size();
	for (int i = 0; i < vectorSize; i++)
	{
		std::string tmpString = racetracks[i]->getName();
		if (tmpString == wantedName)
			return racetracks[i];
	}
	return nullptr;
}

bool Simulator::checkIfItsPossibleToStartARace()
{
	return championship->areCarsInTrack();
}

bool Simulator::addDGV(const std::string& cs)
{
	int vectorSize = dgvStorage.size();
	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if (cs == dgvStorage[i].getName())
				return false;
		}
	}
	dgvStorage.emplace_back(currentDGV, cs);
	return true;
}

bool Simulator::deleteDGV(const std::string& cs)
{
	int vectorSize = dgvStorage.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if(cs == dgvStorage[i].getName())
			{
				dgvStorage.erase(dgvStorage.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool Simulator::loadDGV(const std::string& cs)
{
	int vectorSize = dgvStorage.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if (cs == dgvStorage[i].getName())
			{
				DGV tmpDGV = dgvStorage[i].getDGV();
				currentDGV = tmpDGV;
				return true;
			}
		}
	}
	return false;
}
