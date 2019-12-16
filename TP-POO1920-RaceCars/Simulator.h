#pragma once
#include <iostream>
#include <vector>
#include "DGV.h"
#include "Racetrack.h"
#include "Championship.h"

class Simulator
{
	DGV currentDGV;
	std::vector<Racetrack*> racetracks;
	Championship* championship;
	
public:

	Simulator();
	~Simulator();

	DGV* getDGV();
	Championship* getChampionship();
	Racetrack* getCurrentRace();

	bool attach(char carID, std::string pilotName);
	bool detach(char carID);
	
	bool addCar(int e, int mE, int mS, std::string b, std::string m = "Base");
	bool addPilot(std::string type, std::string newName);
	bool addRacetrack(int maxCars, int length, std::string newName);
	bool addChampionship(std::string racetrack);
	bool addChampionship(std::vector<std::string> racetrackList);
	bool removeCar(char wantedID);
	bool removePilot(std::string wantedName);
	bool removeRacetrack(std::string wantedName);
	int  checkIfItsPossibleToStartAChampionship(std::string tmpString);

	
	void chargeAllCars();
	void startRace();
	void passOneSecond();

	bool printRacetracks();
	
	Racetrack* getRacetrackByName(std::string wantedName);
	bool checkIfItsPossibleToStartARace();
};

	