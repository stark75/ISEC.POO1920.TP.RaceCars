#pragma once
#include "Racetrack.h"

class Race
{
	Racetrack* location;
	std::vector<Car*> top3;

public:
	Race(Racetrack* newLocation);
	~Race() = default;

	//bool assignParticipants(vector pilots);
	//void top3Calc();
};

