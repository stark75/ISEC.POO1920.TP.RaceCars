#include "Car.h"
#include <iostream>

char Car::nextID = 'a';

Car::Car(int mE, int mS, int e, std::string b, std::string m)
	:brand(b),
	model(m),
	id(nextID),
	maxEnergy(mE),
	maxSpeed(mS),
	speed(0),
	movement(false),
	accelerationPedal(0),
	brakePedal(0),
	time(0),
	emergencySignal(false),
	isDamaged(false),
	driver(nullptr)
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

	if (nextID == 'z' || nextID == '?')
		nextID = '?';
	else
		++nextID;
}

Car::~Car()
{
	std::cout << "Car crashed..." << std::endl;
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

double Car::getMaxEnergy() const
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

double Car::getEnergy() const
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

bool Car::getMovement() const
{
	return movement;
}

int Car::getAccelerationPedal() const
{
	return accelerationPedal;
}

int Car::getBrakePedal() const
{
	return brakePedal;
}

bool Car::getEmergencySignal() const
{
	return emergencySignal;
}

bool Car::getDamage() const
{
	return isDamaged;
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

bool Car::accelerate(int times)
{
	if(driver!=nullptr && energy>0 && brakePedal==0)
	{
		accelerationPedal+=times;
		return true;
	}
	return false;
}

bool Car::brake(int times)
{
	if(driver!=nullptr && accelerationPedal==0)
	{
		brakePedal+=times;
		return true;
	}
	return false;
}

bool Car::energyCharge(int n)
{
	return false;
}

bool Car::energyConsumption()
{
	if (energy <= 0)
	{
		energy = 0;
		return false;
	}
	energy -= speed * 0.1;
	if (energy < 0) energy = 0;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Car& c)
{
	os << c.getAsString();
	return os;
}
