#include <vector>
#include "Racetrack.h"

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

bool Racetrack::getIsCarMax() const
{
	return isCarMax;
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
	tmpString += "]";

	return tmpString;
}

int Racetrack::getTime() const
{
	return time;
}

void Racetrack::addCarToGarage(Car* newCar)
{
	carsInGarage.push_back(newCar);
}

void Racetrack::moveCarsToTrack()
{
	int garageSize = carsInGarage.size();
	carsInTrack.clear();
	if(garageSize <= maxCars)
	{
		for(int i=0; i < garageSize;i++)
			carsInTrack.push_back(carsInGarage[i]);
		
		carsInGarage.clear();
	}
	else
	{
		for(int i=0; i < maxCars;i++)
		{
			carsInTrack.push_back(carsInGarage.front());
			carsInGarage.erase(carsInGarage.begin());
		}
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

void Racetrack::carsMovement()
{
	int trackSize = carsInTrack.size();

	++time;
	
	for(int i = 0; i<trackSize;i++)
	{
		if(carsInTrack[i]->getPosition() < trackLength)
			carsInTrack[i]->move(1);
		/*TODO
		 * else
		 *	resets car;
		 */
	}
}

bool Racetrack::printCarsInGarage()
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

bool Racetrack::printCarsInTrack()
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
