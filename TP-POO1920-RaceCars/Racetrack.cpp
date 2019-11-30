#include <iostream>
#include "Racetrack.h"
#include <vector>

Racetrack::Racetrack(std::string n, const int nmax, int ncars, int npil)
	garage(n),
	nMaxCars(nmax),
	nCars(ncars),
	isCarMax(false);

	std::string Racetrack::getgarage() const
	{
		return garage;
	}

	int Racetrack::getncars()
	{
		return nCars;
	}

	int Racetrack::getnMaxCars() const
	{
		return nMaxCars;
	}

	bool Racetrack::isCarMax() 
	{
		if (nCars == nMaxCars)
		{
			return true;
		}
	}
	
	int Racetrack::getpCar()
	{
		return pCars;
	}

	int Racetrack::getpPlace()
	{
		return pPlace;
	}

	std::vector<int> Racetrack::getinRace()
	{
		return std::vector<string> inRace;
	}

	int Racetrack::trackToGarage()
	{

	}

	int Racetrack::garageToTrack()
	{

	}

	int Racetrack::moveRaceTrack() {

		std::vector<int> Racetrack::getinRace()
		{
			return std::vector<string> inRace;
			/*if(returned == car called){
				cout << "Não pode mover o carro porque ele está neste momento a correr";
			}

			else{
				
			}
			*/
		}

	}
