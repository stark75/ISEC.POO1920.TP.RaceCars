#include "Pilot.h"
#include "Car.h"

std::vector<std::string> Pilot::pilotNames;

Pilot::Pilot(std::string newName)
:current(nullptr)
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

Pilot::Pilot(const Pilot& src)
	:name(src.name),
	current(src.current)
{
}

Pilot::~Pilot()
{
}

std::string Pilot::getName() const
{
	return name;
}

Car* Pilot::getCurrentCar() const
{
	return current;
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
		return true;
	}
	return false;
}

bool operator==(const Pilot& lhs, const Pilot& rhs)
{
	return lhs.name == rhs.name
		&& lhs.current == rhs.current;
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