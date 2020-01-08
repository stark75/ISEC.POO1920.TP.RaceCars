#pragma once
#include <vector>
#include "Racetrack.h"
#include "StandingsElement.h"

class Championship
{		
	std::vector<StandingsElement> standings;
	std::vector<Racetrack*>       raceLocations;
	int                           currentRace;
	
public:
	Championship(Racetrack* location, std::vector<Car* > newParticipants);
	Championship(std::vector<Racetrack*> locations, std::vector<Car* > newParticipants);
	~Championship();

	bool        areCarsInTrack()    const;
	int         getCurrentRaceNumber() const;
	Racetrack*  getCurrentRacetrack()  const;

	bool        passOneSecond();
	bool        checkEndOfRace();

	void        chargeAllCars();

	bool        nextRace();  /*NEEDS REVAMP*/
	bool        startRace(); /*NEEDS REVAMP*/

	bool        accident(char wantedID);
	bool        removeCarFromChampionship(char wantedID);
	bool        chargeCar(char wantedID, int n);
	bool        stop(std::string wantedName);

	std::vector<std::string> returnLog();
	
	void        updateStandings();
		
	//View Methods
	bool        printCarsInGarage();
	bool        printCarsInTrack();
	void        printStandings();

	//Sort Vectors
	void        sortCarsByPosition();
	static bool sortFunc(StandingsElement& lhs, StandingsElement& rhs);
	void        sortStandings();
};
