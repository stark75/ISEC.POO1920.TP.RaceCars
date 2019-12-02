#include "Championship.h"
#include "View.h"

Championship::Championship(Racetrack* location, std::vector<Car* > newParticipants):participants(newParticipants),race(0)
{
	int vectorSize = newParticipants.size();
	
	for (int i = 0; i < vectorSize; i++)
	{
		location->addCarToGarage(newParticipants[i]);
	}

	races.push_back(location);
	
}

void Championship::startRace()
{
	races[race]->moveCarsToTrack();
	//charge
}

void Championship::passOneSecond()
{
	races[race]->carsMovement();
	View::printRace(races[race]);
}
