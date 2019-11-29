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
				newName += 1;
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

	tmpString += "[Pilot -";
	tmpString += getName();
	tmpString += "]";

	return tmpString;
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