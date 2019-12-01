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
	std::string		  getRaceTrack()        const;
	int				  getMaxCars()          const;
	int				  getTrackLength() 	    const;

	int				  getnCars();
	bool			  getisCarMax()         const;
	int				  getcarsInTrack();
	int				  getcarsInGarage();

	int				  trackToGarage();
	int	       	      garageToTrack();
	int				  moveRaceTrack();

};