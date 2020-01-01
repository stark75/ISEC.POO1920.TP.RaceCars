#pragma once
#include <string>
#include <vector>
#include "Car.h"
#include "RaceResults.h"


class Racetrack {

	//Caracteristicas RaceTrack

	static std::vector<std::string> raceTrackNames;

	const int                       maxCars;
	const int                       trackLength;
	std::string                     name;

	std::vector<Car*>	            carsInTrack;
	std::vector<Car*>               carsInGarage;

	std::vector<RaceResults>        raceResults;
	
	//Variaveis
	bool				            isCarMax;
	int                             time;

public:
	Racetrack(int newMaxCars, int newLength, std::string newName);
	Racetrack(const Racetrack& src) = default;
	~Racetrack() = default;

	//Getters

	int                             getMaxCars() const;
	int                             getTrackLength() const;
	std::string                     getName() const;
	std::vector<Car*>               getCarsInTrack() const;
	std::vector<Car*>               getCarsInGarage() const;
	std::vector<RaceResults>        getRaceResults() const;
	bool                            getIsCarMax() const;
	std::string                     getAsString() const;
	int                             getTime() const;

	void                            addCarToGarage(Car* newCar);	
	void                            moveCarsToTrack();
	void                            moveCarsToGarage();
	void                            resetCarsPosition();
	void                            resetRacetrack();
	void                            chargeAllCars();
	bool                            carsMovement();
	
	bool                            printCarsInGarage() const;
	bool                            printCarsInTrack() const;
	bool                            printRaceResults();

	bool                            checkCarsInTrack();
	bool                            checkEndOfRace();
	bool                            copyGarage(std::vector<Car*> src);

	static bool                     sortCarMethod(Car* lhs, Car* rhs);
	static bool                     sortRaceMethod(RaceResults& lhs, RaceResults& rhs);
	void                            sortRaceResults();
	void                            sortCarsByPosition();
};
