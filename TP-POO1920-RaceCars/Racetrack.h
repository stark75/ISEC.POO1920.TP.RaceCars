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
	std::vector<std::string>        killList;
	std::vector<std::string>        tmpLog;
	
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
	int                             getTime() const;
	std::string                     getAsString() const;
	Car*                            getCarById(char wantedID);

	void                            addCarToGarage(Car* newCar);	
	void                            moveCarsToTrack();
	void                            moveCarsToGarage();
	void                            resetCars();
	void                            resetRacetrack();
	bool                            chargeCar(char wantedID, int n);
	void                            chargeAllCars();
	bool                            carsMovement();
	bool                            removeCarFromTrack(char wantedID);
	bool                            removeCarFromGarage(char wantedID);
	void                            removeStalledCars();
	bool                            detach(char wantedID);
	bool                            accident(char wantedID);
	bool                            stop(std::string wantedName);

	void                            updateLog(std::string newMessage);
	std::vector<std::string>        returnLog();
	std::vector<std::string>        returnKillList();
	
	bool                            printCarsInGarage() const;
	bool                            printCarsInTrack() const;
	bool                            printRaceResults();

	bool                            checkCarsInTrack();
	bool                            checkEndOfRace();
	bool                            copyGarage(std::vector<Car*> src);

	static bool                     sortCarByPosMethod(Car* lhs, Car* rhs);
	static bool                     sortRaceMethod(RaceResults& lhs, RaceResults& rhs);
	static bool                     sortCarByIDMethod(Car* lhs, Car* rhs);
	void                            sortRaceResults();
	void                            sortCarsByPosition();
	void                            sortCarsByID();
	int                             getPosition(Car* c);
	Car*                            getCarInPosition(int pos);
};
