#pragma once
#include <vector>
#include "Race.h"
#include "DGV.h"

class Championship
{
	std::vector<Car*> participants;
	std::vector<std::string> leaderBoard;
	std::vector<Race*> races;

public:
	Championship(DGV* roster, std::vector<Racetrack*> raceLocations);
	~Championship();
};