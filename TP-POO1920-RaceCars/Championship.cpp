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

bool Championship::getAreCarsInTrack()
{
	return areCarsInTrack;
}

void Championship::startRace()
{
	races[race]->moveCarsToTrack();
	areCarsInTrack = true;
	//charge
}

void Championship::passOneSecond()
{
	races[race]->carsMovement();
	View::printRace(races[race]);
}
