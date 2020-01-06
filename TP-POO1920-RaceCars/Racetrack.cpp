#include <vector>
#include "Racetrack.h"
#include <algorithm>

std::vector<std::string> Racetrack::raceTrackNames;

Racetrack::Racetrack(int newMaxCars, int newLength, std::string newName): maxCars(newMaxCars), trackLength(newLength), isCarMax(false), time(0)
{
	if (raceTrackNames.empty())
	{
		name = newName;
		raceTrackNames.push_back(name);
	}
	else
	{
		for (int i = 0; i < static_cast<int>(raceTrackNames.size()); i++)
		{
			if (raceTrackNames[i] == newName)
			{
				newName += "1";
			}
		}

		name = newName;
		raceTrackNames.push_back(name);
	}
}

int Racetrack::getMaxCars() const
{
	return maxCars;
}

int Racetrack::getTrackLength() const
{
	return trackLength;
}

std::string Racetrack::getName() const
{
	return name;
}

std::vector<Car*> Racetrack::getCarsInTrack() const
{
	return carsInTrack;
}

std::vector<Car*> Racetrack::getCarsInGarage() const
{
	return carsInGarage;
}

std::vector<RaceResults> Racetrack::getRaceResults() const
{
	return raceResults;
}

bool Racetrack::getIsCarMax() const
{
	return isCarMax;
}

int Racetrack::getTime() const
{
	return time;
}

std::string Racetrack::getAsString() const
{
	std::string tmpString;

	tmpString += "[Autodromo: ";
	tmpString += getName();
	tmpString += " | ";
	tmpString += std::to_string(getTrackLength());
	tmpString += "m | ";
	tmpString += std::to_string(getMaxCars());
	tmpString += " lugares]";

	return tmpString;
}

Car* Racetrack::getCarById(char wantedID)
{
	int vectorSize = carsInTrack.size();
	for (int i = 0; i < vectorSize; i++)
	{
		char tmpChar = carsInTrack[i]->getID();
		if (tmpChar == wantedID)
			return carsInTrack[i];
	}

	vectorSize = carsInGarage.size();
	for (int i = 0; i < vectorSize; i++)
	{
		char tmpChar = carsInGarage[i]->getID();
		if (tmpChar == wantedID)
			return carsInGarage[i];
	}
	
	return nullptr;
}

void Racetrack::addCarToGarage(Car* newCar)
{
	carsInGarage.push_back(newCar);
}

void Racetrack::moveCarsToTrack()
{
	int garageSize = carsInGarage.size();
	carsInTrack.clear();
	for (int i = 0; i < garageSize; i++)
	{
		if (carsInGarage[i]->getDriver() != nullptr)
		{
			carsInTrack.push_back(carsInGarage[i]);
			carsInGarage.erase(carsInGarage.begin() + i);
			garageSize = carsInGarage.size();
			i--;
		}

		int trackSize = carsInTrack.size();

		if (trackSize == maxCars)
			break;
		
	}
}

void Racetrack::moveCarsToGarage()
{
	int trackSize = carsInTrack.size();

	for(int i=0; i<trackSize;i++)
	{
		carsInGarage.push_back(carsInTrack[i]);
	}
	carsInTrack.clear();
	
}

void Racetrack::resetCars()
{
	int vectorSize = carsInTrack.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
			carsInTrack[i]->reset();
	}

	vectorSize = carsInGarage.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
			carsInGarage[i]->reset();
	}
	
}

void Racetrack::resetRacetrack()
{
	raceResults.clear();
	carsInTrack.clear();
	carsInGarage.clear();
	time = 0;
}

bool Racetrack::chargeCar(char wantedID, int n)
{
	Car* tmpCar = getCarById(wantedID);

	if (tmpCar != nullptr)
		return tmpCar->energyCharge(n);

	return false;
}

void Racetrack::chargeAllCars()
{
	int vectorSize = carsInGarage.size();

	if (vectorSize > 0)
		for(int i=0;i<vectorSize;i++)
			carsInGarage[i]->energyFullCharge();

	vectorSize = carsInTrack.size();
	if (vectorSize > 0)
		for(int i=0;i<vectorSize;i++)
			carsInTrack[i]->energyFullCharge();
	
}

bool Racetrack::carsMovement()
{
	int trackSize = carsInTrack.size();

	++time;

	int carsInFinishLine = raceResults.size();

	for(int i = 0; i<trackSize;i++)
	{
		bool checker = true;
		if (carsInTrack[i]->getPosition() < trackLength)
		{
			checker = carsInTrack[i]->move(this);
		}
		if (checker)
		{
			if (carsInTrack[i]->getPosition() >= trackLength)
			{
				checker = false;

				for (int j = 0; j < carsInFinishLine; j++)
				{
					if (carsInTrack[i] == raceResults[j])
					{
						checker = true;
						break;
					}
				}

				if (!checker)
				{
					raceResults.emplace_back(carsInTrack[i], time);
				}
			}
		}
		else
		{
			trackSize = carsInTrack.size();
		}
	}

	carsInFinishLine = raceResults.size();
	
	if (carsInFinishLine == trackSize)
		return false;

	return true;
}

bool Racetrack::removeCarFromTrack(char wantedID)
{
	int vectorSize = carsInTrack.size();
	for (int i = 0; i < vectorSize; i++)
	{
		if (wantedID == carsInTrack[i]->getID())
		{
			carsInGarage.push_back(carsInTrack[i]);
			carsInTrack.erase(carsInTrack.begin() + i);
			return true;
		}
	}
	return false;
}

bool Racetrack::removeCarFromGarage(char wantedID)
{
	int vectorSize = carsInGarage.size();
	for (int i = 0; i < vectorSize; i++)
	{
		if (wantedID == carsInGarage[i]->getID())
		{
			carsInGarage.erase(carsInGarage.begin() + i);
			return true;
		}
	}
	return false;
}

bool Racetrack::detach(char wantedID)
{
	Car* tmpCar = getCarById(wantedID);

	if (tmpCar != nullptr)
	{
		Pilot* tmpPilot = tmpCar->getDriver();
		if (tmpPilot != nullptr)
		{
			if (tmpPilot->detach())
			{
				return tmpCar->detach();
			}
		}
	}
	return false;
}

bool Racetrack::accident(char wantedID)
{
	int vectorSize = carsInTrack.size();
	for (int i = 0; i < vectorSize; i++)
	{
		if (wantedID == carsInTrack[i]->getID())
		{
			carsInTrack[i]->accident();
			Pilot* tmpPilot = carsInTrack[i]->getDriver();
			killList.push_back(tmpPilot->getName());
			detach(wantedID);
			return removeCarFromTrack(wantedID);
		}
	}
	return false;
}

void Racetrack::updateLog(std::string newMessage)
{
	if(!newMessage.empty())
		tmpLog.push_back(newMessage);
}

std::vector<std::string> Racetrack::returnLog()
{
	std::vector<std::string> log = tmpLog;
	tmpLog.clear();
	return log;
}

std::vector<std::string> Racetrack::returnKillList()
{
	std::vector<std::string> kList = killList;
	killList.clear();
	return kList;
}

bool Racetrack::printCarsInGarage() const
{
	int vectorSize = carsInGarage.size();

	if (vectorSize == 0)
		return false;
	for(int i = 0; i < vectorSize; i++)
	{
		std::cout << *carsInGarage[i] << std::endl;
	}
	return true;
}

bool Racetrack::printCarsInTrack() const
{
	int vectorSize = carsInTrack.size();

	if(vectorSize == 0)
		return false;
	
	for (int i = 0; i < vectorSize; i++)
	{
		std::cout << *carsInTrack[i] << std::endl;
	}
	return true;
}

bool Racetrack::printRaceResults()
{
	int vectorSize = raceResults.size();

	if(vectorSize==0)
		return false;

	sortRaceResults();

	for(int i = 0; i < vectorSize; i++)
	{
		std::cout << raceResults[i] << std::endl;
	}
	return true;
}

bool Racetrack::checkCarsInTrack()
{
	int checker = carsInTrack.size();
	if(checker>0)
		return true;
	return false;
}

bool Racetrack::checkEndOfRace()
{
	int vectorSize = carsInTrack.size();

	if (vectorSize == 0)
		return true;

	for (int i = 0; i < vectorSize; i++)
	{
		int position = carsInTrack[i]->getPosition();
		if(position < trackLength)
			return false;
	}

	moveCarsToGarage();
	resetCars();
	
	return true;
	
}

bool Racetrack::copyGarage(std::vector<Car*> src)
{
	if (src.empty())
		return false;

	if (!carsInTrack.empty())
		return false;

	if(!carsInGarage.empty())
		return false;

	carsInGarage = src;
	return true;
}

bool Racetrack::sortCarByPosMethod(Car* lhs, Car* rhs)
{
	return lhs->getPosition() > rhs->getPosition();
}

bool Racetrack::sortRaceMethod(RaceResults& lhs, RaceResults& rhs)
{
	return lhs.getFinishTime() < rhs.getFinishTime();
}

bool Racetrack::sortCarByIDMethod(Car* lhs, Car* rhs)
{
	if(lhs->getID() == '?' || rhs->getID() == '?')
		return lhs->getID() > rhs->getID();
	return lhs->getID() < rhs->getID();
}

void Racetrack::sortRaceResults()
{
	std::vector<RaceResults> vectorCopy = raceResults;
	std::sort(vectorCopy.begin(), vectorCopy.end(), sortRaceMethod);
	raceResults = vectorCopy;
}

void Racetrack::sortCarsByPosition()
{
	std::vector<Car*> vectorCopy = carsInTrack;
	std::sort(vectorCopy.begin(), vectorCopy.end(), sortCarByPosMethod);
	carsInTrack = vectorCopy;
}

void Racetrack::sortCarsByID()
{
	std::vector<Car*> vectorCopy = carsInTrack;
	std::sort(vectorCopy.begin(), vectorCopy.end(), sortCarByIDMethod);
	carsInTrack = vectorCopy;
}

int Racetrack::getPosition(Car* c)
{
	int pos = 0;
	sortCarsByPosition();

	int vectorSize = carsInTrack.size();
	for (int i = 0; i < vectorSize; i++)
	{
		if(c == carsInTrack[i])
		{
			pos = i + 1;
			break;
		}
	}
	sortCarsByID();
	return pos;
}

Car* Racetrack::getCarInPosition(int pos)
{
	sortCarsByPosition();
	int maxCars = carsInTrack.size();
	
	if (pos < 1)
		return nullptr;
	if (pos > maxCars)
		return nullptr;

	Car *c = carsInTrack[pos - 1];
	
	sortCarsByID();
	
	return c;
}
