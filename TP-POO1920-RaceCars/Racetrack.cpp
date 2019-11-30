#include <iostream>
#include "Racetrack.h"
#include <vector>

Racetrack::Racetrack(std::string r, int cIT, int cIG, int nMC, int rTL)
	raceTrack(r),
	carsInTrack (cIT),
	carsInGarage (CIG),
	isMaxCars(nMC),
	rTLength(rTL),
	isCarMax(false);


	std::string Racetrack::getraceTrack() const
	{
		return raceTrack;
	}


	int Racetrack::getnMaxCars() const
	{
		int maxCars = 0;
		int sizeInRT = getnCars;
		if (maxCars <= sizeInRT) {

			cout << "O número de carros não ultrapassa o limite (" << sizeInRT << "/" << maxCars << ")"
		}

		return nMaxCars;
	}


	int Racetrack::getrTLength() {
		return rTLength;
	}


	int Racetrack::getncars()
	{
		int sizeGarage = static_cast<Car*>(carsInGarage.size());
		int sizeInRace = static_cast<Car*>(carsInTrack.size());
		int sizeInRT = sizeGarage + sizeInRace;

		cout << "O número de carros na Racetrack é " << sizeInRT;

		return sizeInRT;
	}


	bool Racetrack::getisCarMax() 
	{
		if (nCars == nMaxCars)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	int RaceTrack::getcarsInTrack()
	{
		return carsInTrack;
	}


	int RaceTrack::getcarsInGarage()
	{
		return carsInGarage;
	}


	int Racetrack::trackToGarage()
	{
		int times = 0;
		auto it = std::next(carsInTrack<Car*>(), getnCars()), times++;
		std::move(carsInTrack<Car*>.begin(), it, std::back_inserter(carsInGarage<Car*>));
		carsInTrack<Car*>.erase(carsInTrack.begin(), it);
		cout << "Foram " << times << "carros para a garagem";
		return times;
	}


	int Racetrack::garageToTrack()
	{
		int times = 0;
		auto it = std::next(carsInGarage(), getnCars()), times++;
		std::move(carsInGarage.begin(), it, std::back_inserter(carsInTrack<Car*>));
		carsInGarage.erase(carsInGarage.begin(), it);
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
