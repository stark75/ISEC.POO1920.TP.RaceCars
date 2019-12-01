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
				newName += "1";
			}
		}

		name = newName;
		raceTrackNames.push_back(name);
	}
}

int Racetrack::getMaxCars() const
{
	return maxCars;
}

int Racetrack::getTrackLength() const
{
	return trackLength;
}

std::string Racetrack::getName() const
{
	return name;
}

std::vector<Car*> Racetrack::getCarsInTrack() const
{
	return carsInTrack;
}

std::vector<Car*> Racetrack::getCarsInGarage() const
{
	return carsInGarage;
}

bool Racetrack::getIsCarMax() const
{
	return isCarMax;
}

std::string Racetrack::getAsString() const
{
	std::string tmpString;

	tmpString += "[Autodromo: ";
	tmpString += getName();
	tmpString += " | ";
	tmpString += std::to_string(getTrackLength());
	tmpString += "m | ";
	tmpString += std::to_string(getMaxCars());
	tmpString += "]";

	return tmpString;
}

/*
int Racetrack::trackToGarage()
{
	int times = 0;
	auto it = std::next(carsInTrack<Car*>(), getnCars()), times++;
	std::move(carsInTrack<Car*>.begin(), it, std::back_inserter(carsInGarage<Car*>));
	carsInTrack<Car*>.erase(carsInTrack.begin(), it);
	std::cout << "Foram " << times << "carros para a garagem";
	return times;
}


int Racetrack::garageToTrack()
{
	int times = 0;
	auto it = std::next(carsInGarage(), getnCars()), times++;
	std::move(carsInGarage.begin(), it, std::back_inserter(carsInTrack<Car*>));
	carsInGarage.erase(carsInGarage.begin(), it);
	std::cout << "Foram " << times << "carros para a track";
	return times;
}


int Racetrack::moveRaceTrack() {

	std::vector<int> Racetrack::getinRace()
	{
		//return std::vector<string> inRace;
		/*if(returned == car called){
			cout << "Não pode mover o carro porque ele está neste momento a correr";
		}

		else{
			//Mover o carro
		}
		
	}

}*/
