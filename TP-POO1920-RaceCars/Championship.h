#pragma once
#include <vector>
#include "Racetrack.h"

class Championship
{
	std::vector<Car*>        participants;
	std::vector<std::string> leaderBoard;
	std::vector<Racetrack*>  raceLocations;
	int                      race;
	bool                     areCarsInTrack;
	
public:
	Championship(Racetrack* location, std::vector<Car* > newParticipants);
	Championship(std::vector<Racetrack*> locations, std::vector<Car* > newParticipants);
	~Championship() = default;

	bool getAreCarsInTrack();
	Racetrack* getCurrentRace();
	
	bool nextRace();
	void startRace();

	void passOneSecond();
	void chargeAllCars();

	bool printCarsInGarage();
	bool printCarsInTrack();
};
