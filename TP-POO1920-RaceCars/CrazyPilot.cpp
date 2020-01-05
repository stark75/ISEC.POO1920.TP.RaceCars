#include "CrazyPilot.h"
#include "Car.h"

CrazyPilot::CrazyPilot(const std::string& newName) : Pilot(newName)
{
}

CrazyPilot::CrazyPilot(const Pilot& src) : Pilot(src)
{
}

std::string CrazyPilot::getAsString() const
{
	std::string tmpString;

	tmpString += "[Crazy Pilot ";
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

std::string CrazyPilot::getTypeAsString() const
{
	return "crazy";
}
