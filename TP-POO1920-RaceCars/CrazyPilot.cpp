#include "CrazyPilot.h"
#include "Car.h"
#include "Racetrack.h"
#include <cstdlib>
#include <ctime>

CrazyPilot::CrazyPilot(const std::string& newName) : Pilot(newName), secondToStart(0), tmpPos(0)
{
}

CrazyPilot::CrazyPilot(const Pilot& src) : Pilot(src), secondToStart(0), tmpPos(0)
{
}

void CrazyPilot::generateSecondToStart(int raceTime)
{
	std::srand(static_cast<unsigned>(time(0)));

	secondToStart = (rand() % 5) + 1;

	std::string tmpString = "No segundo ";
	tmpString += std::to_string(raceTime);
	tmpString += ", o piloto crazy ";
	tmpString += getName();
	tmpString += " gerou o numero ";
	tmpString += std::to_string(secondToStart);
	tmpString += " para iniciar o movimento.";

	setLog(tmpString);
}

bool CrazyPilot::generateAccident(int raceTime)
{
	std::srand(static_cast<unsigned>(time(0)));

	int num = (rand() % 100) + 1;

	std::string tmpString = "No segundo ";
	tmpString += std::to_string(raceTime);
	tmpString += ", o piloto crazy ";
	tmpString += getName();
	tmpString += " gerou o numero ";
	tmpString += std::to_string(num);
	tmpString += " para gerar um acidente. ";

	if(num == 1 || num == 21 || num == 41 || num == 61 || num == 81)
	{
		tmpString += "Ocorreu um acidente.";
		setLog(tmpString);
		return true;
	}
	tmpString += "Nao ocorreu nenhum acidente.";
	setLog(tmpString);
	return false;
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

bool CrazyPilot::movement(Racetrack* r)
{
	int tmpTime = r->getTime();
	if (tmpTime == 1)
	{
		generateSecondToStart(tmpTime);
		r->updateLog(returnLog());
	}
		
	if (tmpTime >= secondToStart)
	{
		Car* c = getCurrentCar();
		int pos = r->getPosition(c);
		bool lostPosition = false;
		
		int maxCars = r->getCarsInTrack().size();

		if (pos > maxCars)
			pos = maxCars;

		if (tmpPos != 0)
			if (tmpPos > pos)
				lostPosition = true;
		tmpPos = pos;

		if (!getStopOrder())
		{
			if (pos == 1)
			{
				c->resetPedals();
			}

			if (pos > 1 && pos < maxCars)
			{
				if (lostPosition)
				{
					if (!c->pressAccelerate(2))
						c->pressBrake(-2);
				}
				else
				{
					if (!c->pressAccelerate())
						c->pressBrake();
				}
			}

			if (pos == maxCars)
			{
				if (!c->pressBrake())
					c->pressAccelerate(-1);
			}
		}
		else
		{
			c->resetPedals();
			if (c->getSpeed() > 0)
				c->pressBrake();
		}

		if(c->getEnergy() == 0)
		{
			c->turnOnEmergencySignal();
		}

		if(generateAccident(tmpTime))
		{
			r->updateLog(returnLog());
			if(pos < maxCars)
			{
				Car* other = r->getCarInPosition(pos+1);
				r->accident(other->getID());
			}
			r->accident(c->getID());
			return false;
		}
		r->updateLog(returnLog());
		
	}
	
	return true;
}

void CrazyPilot::reset()
{
	secondToStart = 0;
	tmpPos = 0;
	setStop(false);
	setLog("");
}
