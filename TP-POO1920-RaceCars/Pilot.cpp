#include "Pilot.h"
#include "Car.h"

std::vector<std::string> Pilot::pilotNames;

Pilot::Pilot(std::string newName)
:current(nullptr), stopOrder(false)
{
	if(pilotNames.empty())
	{
		name = newName;
		pilotNames.push_back(name);
	}
	else
	{
		for(int i = 0; i < static_cast<int>(pilotNames.size()); i++)
		{
			if(pilotNames[i] == newName)
			{
				newName += "1";
			}
		}

		name = newName;
		pilotNames.push_back(name);
	}
}

std::string Pilot::getName() const
{
	return name;
}

Car* Pilot::getCurrentCar() const
{
	return current;
}

bool Pilot::getStopOrder() const
{
	return stopOrder;
}

std::string Pilot::getAsString() const
{
	std::string tmpString;

	tmpString += "[Pilot ";
	tmpString += getName();
	tmpString += " | Carro: ";
	if(current != nullptr)
	{
		tmpString += "(";
		std::string carID = std::string(1,current->getID());
		tmpString += carID;
		tmpString += ") - ";
		tmpString += current->getBrand();
		tmpString += " ";
		tmpString += current->getModel();
	}
	else
	{
		tmpString += "Nenhum";
	}
	tmpString += "]";

	return tmpString;
}

std::string Pilot::getTypeAsString() const
{
	return "generico";
}

void Pilot::setLog(const std::string& newMessage)
{
	tmpLog = newMessage;
}

void Pilot::setStop(const bool& condition)
{
	stopOrder = condition;
}

std::string Pilot::returnLog()
{
	std::string log = tmpLog;
	
	tmpLog.clear();
	return log;
}

bool Pilot::attach(Car* newCar)
{
	if(current==nullptr)
	{
		current = newCar;
		return true;
	}
	return false;
}

bool Pilot::detach()
{
	if(current!=nullptr)
	{
		current = nullptr;
		reset();
		return true;
	}
	return false;
}

bool operator==(const Pilot& lhs, const Pilot& rhs)
{
	return lhs.name == rhs.name;
}

bool operator!=(const Pilot& lhs, const Pilot& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Pilot& p)
{
	os << p.getAsString();
	return os;
}