#include "FastPilot.h"
#include "Car.h"

FastPilot::FastPilot(const std::string& newName) : Pilot(newName)
{
}

FastPilot::FastPilot(const Pilot& src) : Pilot(src)
{
}

std::string FastPilot::getAsString() const
{
	std::string tmpString;

	tmpString += "[Fast Pilot ";
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

std::string FastPilot::getTypeAsString() const
{
	return "rapido";
}
