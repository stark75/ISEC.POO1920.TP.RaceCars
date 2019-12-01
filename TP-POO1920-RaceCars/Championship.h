#pragma once
#include <vector>
#include "Racetrack.h"

class Championship
{
	std::vector<Car*>        participants;
	std::vector<std::string> leaderBoard;
	std::vector<Racetrack*>  races;

public:
	Championship(Racetrack* location, std::vector<Car* > newParticipants);
	//Championship(std::vector<Racetrack*> locations, std::vector<Car* > newParticipants);
	~Championship();

	void addParticipants(Car* newCar);
};
