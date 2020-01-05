#include "SurprisePilot.h"
#include "Car.h"

SurprisePilot::SurprisePilot(const std::string& newName) : Pilot(newName)
{
}

SurprisePilot::SurprisePilot(const Pilot& src) : Pilot(src)
{
}

std::string SurprisePilot::getAsString() const
{
	std::string tmpString;

	tmpString += "[Surprise Pilot ";
	tmpString += getName();
	tmpString += " | Carro: ";

	Car* tmpCar = getCurrentCar();

	if (tmpCar != nullptr)
	{
		tmpString += "(";
		std::string carID = std::string(1, tmpCar->getID());
		tmpString += carID;
		tmpString += ") - ";
		tmpString += tmpCar->getBrand();
		tmpString += " ";
		tmpString += tmpCar->getModel();
	}
	else
	{
		tmpString += "Nenhum";
	}
	tmpString += "]";

	return tmpString;
}

std::string SurprisePilot::getTypeAsString() const
{
	return "surpresa";
}
