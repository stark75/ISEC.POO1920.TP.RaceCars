#include "Car.h"

char Car::nextID = 'a';

Car::Car(int mE, int mS, int e, std::string b, std::string m)
	:brand(b), model(m), maxEnergy(mE), maxSpeed(mS), speed(0), time(0)
{
	if (e > maxEnergy)
		energy = maxEnergy;
	else
	{
		if (e < 0)
			energy = 0;
		else
			energy = e;
	}

	driver = nullptr;
	id = nextID;
	
	if (nextID == 'z' || nextID == '?')
	{
		nextID = '?';
	}
	else
	{
		++nextID;
	}
}

Car::~Car()
{
}

char Car::getNextID() const
{
	return nextID;
}

std::string Car::getBrand() const
{
	return brand;
}

std::string Car::getModel() const
{
	return model;
}

char Car::getID() const
{
	return id;
}

int Car::getMaxEnergy() const
{
	return maxEnergy;
}

int Car::getMaxSpeed() const
{
	return maxSpeed;
}

Pilot* Car::getDriver() const
{
	return driver;
}

int Car::getEnergy() const
{
	return energy;
}

int Car::getSpeed() const
{
	return speed;
}

int Car::getTime() const
{
	return time;
}


std::string Car::getAsString() const
{
	std::string tmpString;

	tmpString += "[";
	tmpString += getID();
	tmpString += " - ";
	tmpString += getBrand();
	tmpString += " ";
	tmpString += getModel();
	tmpString += "]";

	
	return tmpString;
}


std::ostream& operator<<(std::ostream& os, const Car& c)
{
	os << c.getAsString();
	return os;
}
