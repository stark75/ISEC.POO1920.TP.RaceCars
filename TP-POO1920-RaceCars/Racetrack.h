#include <string>
#include <vector>
#include "Pilot.h"
#include "Car.h"


class Racetrack {

	//Caracteristicas RaceTrack
	
	std::vector<Car*>	raceTrack;
	std::vector<Car*>	carsInTrack;
	std::vector<Car*>   carsInGarage;
	const int		    nMaxCars;
	int					rTLength const;

	//Variáveis
	bool				isCarMax;

};

public:
	Racetrack(std::string n, const int nmax, int ncars, int npil);

	//Getters
	std::string		  getraceTrack()        const;
	int				  getnMaxcars()         const;
	int				  getrTLength();	    const;

	int				  getnCars();
	bool			  getisCarMax()         const;
	int				  getcarsInTrack();
	int				  getcarsInGarage();

	int				  trackToGarage();
	int	       	      garageToTrack();
	int				  moveRaceTrack();

};