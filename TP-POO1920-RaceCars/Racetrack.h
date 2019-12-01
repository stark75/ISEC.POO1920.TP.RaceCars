#pragma once
#include <string>
#include <vector>
#include "Car.h"


class Racetrack {

	//Caracteristicas RaceTrack

	static std::vector<std::string> raceTrackNames;

	const int           maxCars;
	const int           trackLength;
	std::string         name;

	std::vector<Car*>	carsInTrack;
	std::vector<Car*>   carsInGarage;

	//Variáveis
	bool				isCarMax;

public:
	Racetrack(int newMaxCars, int newLength, std::string newName);
	~Racetrack() = default;

	//Getters

	int getMaxCars() const;

	int getTrackLength() const;

	std::string getName() const;

	std::vector<Car*> getCarsInTrack() const;

	std::vector<Car*> getCarsInGarage() const;

	bool getIsCarMax() const;

	std::string getAsString() const;

	int				  trackToGarage();
	int	       	      garageToTrack();
	int				  moveRaceTrack();

};