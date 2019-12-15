#include "Championship.h"
#include "View.h"

Championship::Championship(Racetrack* location, std::vector<Car* > newParticipants) :participants(newParticipants), race(0), areCarsInTrack(false)
{
	int vectorSize = newParticipants.size();
	
	for (int i = 0; i < vectorSize; i++)
	{
		location->addCarToGarage(newParticipants[i]);
	}

	raceLocations.push_back(location);
	
}

Championship::Championship(std::vector<Racetrack*> locations, std::vector<Car*> newParticipants)
	:participants(newParticipants), race(0), areCarsInTrack(false)
{
	int lVectorSize = locations.size();

	for(int i=0; i < lVectorSize; i++)
	{
		raceLocations.push_back(locations[i]);
	}

	int pVectorSize = newParticipants.size();

	for (int i = 0; i < pVectorSize; i++)
		raceLocations[0]->addCarToGarage(newParticipants[i]);

}

bool Championship::getAreCarsInTrack()
{
	return areCarsInTrack;
}

Racetrack* Championship::getCurrentRace()
{
	return raceLocations[race];
}

bool Championship::nextRace()
{
	int maxRaces = raceLocations.size();
	if(race < (maxRaces-1))
	{
		++race;
		return true;
	}
	return false;
}

void Championship::startRace()
{
	raceLocations[race]->moveCarsToTrack();
	areCarsInTrack = true;
	chargeAllCars();
}

void Championship::passOneSecond()
{
	raceLocations[race]->carsMovement();
}

void Championship::chargeAllCars()
{
	raceLocations[race]->chargeAllCars();
}

bool Championship::printCarsInGarage()
{
	return raceLocations[race]->printCarsInGarage();
}

bool Championship::printCarsInTrack()
{
	return raceLocations[race]->printCarsInTrack();
}
