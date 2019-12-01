#include <iostream>
#include <vector>
#include "Racetrack.h"

std::vector<std::string> Racetrack::raceTrackNames;

Racetrack::Racetrack(int newMaxCars, int newLength, std::string newName): maxCars(newMaxCars), trackLength(newLength)
{
	if (raceTrackNames.empty())
	{
		name = newName;
		raceTrackNames.push_back(name);
	}
	else
	{
		for (int i = 0; i < static_cast<int>(raceTrackNames.size()); i++)
		{
			if (raceTrackNames[i] == newName)
			{
				newName += 1;
			}
		}

		name = newName;
		raceTrackNames.push_back(name);
	}
}

std::string Racetrack::getRaceTrack() const
{
	return raceTrack;
}


int Racetrack::getnMaxCars() const
{
	int maxCars = 0;
	int sizeInRT = getnCars;
	if (maxCars <= sizeInRT) {
		std::cout << "O número de carros não ultrapassa o limite (" << sizeInRT << "/" << maxCars << ")"
	}

	return maxCars;
}


int Racetrack::getTrackLength() {
	return trackLength;
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
	if (nCars == maxCars)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int Racetrack::getcarsInTrack()
{
	return carsInTrack;
}


int Racetrack::getcarsInGarage()
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
