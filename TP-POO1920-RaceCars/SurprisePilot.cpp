#include "SurprisePilot.h"
#include "Car.h"
#include "Racetrack.h"

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

bool SurprisePilot::movement(Racetrack* r)
{
	Car* c = getCurrentCar();

	int pos = r->getPosition(c);
	int maxCars = r->getCarsInTrack().size();

	double trackLength = r->getTrackLength();
	double distanceElapsed = c->getPosition();
	double ratioDistance = distanceElapsed / trackLength;
	
	if (pos > maxCars)
		pos = maxCars;

	if(!getStopOrder())
	{
		if (pos == 1 && ratioDistance >= 0.7 && ratioDistance < 0.9)
		{
			if(c->getAccelerationPedal()>0)
				c->resetPedals();
			c->pressBrake(-10);
		}
		else
		{
			if(c->getBrakePedal()>0)
				c->resetPedals();
			c->pressAccelerate(4);
		}
	}
	else
	{
		c->resetPedals();
		if (c->getSpeed() > 0)
			c->pressBrake();
	}
	return true;
}

void SurprisePilot::reset()
{
	setStop(false);
	setLog("");
}
