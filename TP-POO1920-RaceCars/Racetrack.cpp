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
		int sizeGarage = static_cast<Car*>(carsInGarage.size());
		int sizeInRace = static_cast<Car*>(carsInTrack.size());
		int sizeInRT = sizeGarage + sizeInRace;

		cout << "O número de carros na Racetrack é " << sizeInRT;

		return sizeInRT;
	}

	int Racetrack::getnMaxCars() const
	{
		int maxCars = 0;
		int sizeInRT = getnCars;
		if (maxCars <= sizeInRT) {

			cout << "O número de carros não ultrapassa o limite (" <<  sizeInRT << "/" << maxCars << ")"
		}

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


	int Racetrack::garageToTrack()
	{
		int times = 0;
		auto it = std::next(carsInGarage(), getnCars()), times++;
		std::move(carsInGarage<Car*>.begin(), it, std::back_inserter(carsInTrack<Car*>));
		carsInGarage<Car*>.erase(carsInGarage.begin(), it);
		cout << "Foram " << times << "carros para a track";
		return times;
	}

	int Racetrack::trackToGarage()
	{
		int times = 0;
		auto it = std::next(carsInTrack<Car*>(), getnCars()), times++;
		std::move(carsInTrack<Car*>.begin(), it, std::back_inserter(carsInGarage<Car*>));
		carsInTrack<Car*>.erase(carsInTrack.begin(), it);
		cout << "Foram " << times << "carros para a track";
		return times;
	}

	
	int Racetrack::moveRaceTrack() {

		std::vector<int> Racetrack::getinRace()
		{
			return std::vector<string> inRace;
			/*if(returned == car called){
				cout << "Não pode mover o carro porque ele está neste momento a correr";
			}

			else{
				//Mover o carro
			}
			*/
		}

	}
