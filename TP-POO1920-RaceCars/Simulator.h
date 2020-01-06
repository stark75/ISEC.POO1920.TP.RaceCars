#pragma once
#include <vector>
#include "DGV.h"
#include "Racetrack.h"
#include "Championship.h"
#include "StoredDGV.h"

class Simulator
{
	DGV currentDGV;
	std::vector<Racetrack*> racetracks;
	Championship* championship;
	std::vector<std::string> log;
	std::vector<StoredDGV> dgvStorage;
	
public:

	Simulator();
	~Simulator();

	DGV* getDGV();
	Championship* getChampionship();
	Racetrack* getCurrentRace();
	std::vector<std::string> getLog();

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
	bool destroyCar(char wantedID);
	bool accident(char wantedID);
	bool chargeCar(char wantedID, int n);
	int  checkIfItsPossibleToStartAChampionship(std::string tmpString);
	void clearChampionship();
	void addMessageToLog(std::string newMessage);
	void addMessagesToLog();
	void clearKillList();
	
	void chargeAllCars();
	bool startRace();
	bool nextRace();
	bool passOneSecond();
	void updateStandings();
	bool checkEndOfRace();

	bool printRacetracks();
	
	Racetrack* getRacetrackByName(std::string wantedName);
	bool checkIfItsPossibleToStartARace();
	bool addDGV(const std::string& cs);
	bool deleteDGV(const std::string& cs);
	bool loadDGV(const std::string& cs);
};

	