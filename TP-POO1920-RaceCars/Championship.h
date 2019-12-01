#pragma once
#include <vector>
#include "DGV.h"
#include "Racetrack.h"

class Championship
{
	int maxNumberOfParticipants;
	std::vector<Car*> participants;
	std::vector<std::string> leaderBoard;
	std::vector<Racetrack*> races;

public:
	Championship();
	~Championship();

	void addRace();
};
