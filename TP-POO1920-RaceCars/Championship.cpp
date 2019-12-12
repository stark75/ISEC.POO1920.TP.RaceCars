#include "Championship.h"
#include "View.h"

Championship::Championship(Racetrack* location, std::vector<Car* > newParticipants) :participants(newParticipants), race(0), areCarsInTrack(false)
{
	int vectorSize = newParticipants.size();
	
	for (int i = 0; i < vectorSize; i++)
	{
		location->addCarToGarage(newParticipants[i]);
	}

	races.push_back(location);
	
}

Championship::Championship(std::vector<Racetrack*> locations, std::vector<Car*> newParticipants)
	:participants(newParticipants), race(0), areCarsInTrack(false), time(0)
{
	int lVectorSize = locations.size();

	for(int i=0; i < lVectorSize; i++)
	{
		races.push_back(locations[i]);
	}

	int pVectorSize = newParticipants.size();

	for (int i = 0; i < pVectorSize; i++)
		races[0]->addCarToGarage(newParticipants[i]);

}

bool Championship::getAreCarsInTrack()
{
	return areCarsInTrack;
}

bool Championship::nextRace()
{
	int maxRaces = races.size();
	if(race < (maxRaces-1))
	{
		++race;
		return true;
	}
	return false;
}

void Championship::startRace()
{
	time = 0;
	races[race]->moveCarsToTrack();
	areCarsInTrack = true;
	//charge
}

void Championship::passOneSecond()
{
	races[race]->carsMovement();
	View::printRace(races[race]);
}
