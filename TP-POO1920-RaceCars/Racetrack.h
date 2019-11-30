#include <string>
#include <vector>
#include "Pilot.h"
#include "Car.h"


class Racetrack {

	//Caracteristicas garagem
	
	const int		    nMaxCars;
	std::vector<Car*>	garage;
	std::vector<Car*>	carsInTrack;
	std::vector<Car*>   carsInGarage;

	//Variáveis
	bool				isCarMax;

	int pCar;
	int pPlace;
};

public:
	Racetrack(std::string n, const int nmax, int ncars, int npil);

	//Getters
	std::string		  getgarage()           const;
	int				  getnMaxcars()         const;
	int				  getnCars();
	bool			  getisCarMax()         const;
	int			      getpCar();
	int				  getpPlace();

	std::vector<int>  getinRace();

	int				  trackToGarage();
	int	       	      garageToTrack();
	int				  moveRaceTrack();


};