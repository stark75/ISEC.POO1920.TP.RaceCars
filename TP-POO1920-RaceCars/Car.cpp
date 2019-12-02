#include "Car.h"
#include <iostream>

char Car::nextID = 'a';

Car::Car(int e, int mE, int mS, std::string b, std::string m)
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
	position(0),
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

Car::Car(const Car& src)
	:brand(src.brand),
	model(src.model),
	id(src.id),
	maxEnergy(src.maxEnergy),
	maxSpeed(src.maxSpeed),
	speed(src.speed),
	energy(src.energy),
	movement(src.movement),
	accelerationPedal(src.accelerationPedal),
	brakePedal(src.brakePedal),
	time(src.time),
	position(src.position),
	emergencySignal(src.emergencySignal),
	isDamaged(src.isDamaged),
	driver(src.driver)
{
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

int Car::getPosition() const
{
	return position;
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

void Car::setPosition(int newPos)
{
	position = newPos;
}

bool Car::attach(Pilot* newDriver)
{
	if (driver == nullptr)
	{
		driver = newDriver;
		return true;
	}
	return false;
}

bool Car::detach()
{
	if(driver!=nullptr)
	{
		driver = nullptr;
		return true;
	}
	return false;
}


std::string Car::getAsString() const
{
	std::string tmpString;

	tmpString += "[Carro ";
	tmpString += getID();
	tmpString += " | ";
	tmpString += getBrand();
	tmpString += " ";
	tmpString += getModel();
	tmpString += " | Condutor: ";
	if (driver != nullptr)
	{
		std::string tmpDriver = driver->getName();
		tmpString += tmpDriver;
	}
	else
	{
		tmpString += "Nenhum";
	}
	tmpString += "]";
	
	return tmpString;
}

bool Car::pressAccelerate(int times)
{
	if(/*driver!=nullptr &&*/ energy>0 && brakePedal==0 && speed < maxSpeed)
	{
		accelerationPedal+=times;
		return true;
	}
	return false;
}

bool Car::pressBrake(int times)
{
	if(/*driver!=nullptr &&*/ accelerationPedal==0)
	{
		brakePedal+=times;
		return true;
	}
	return false;
}

bool Car::energyCharge(int n)
{
	if(energy < maxEnergy)
	{
		energy += n;
		if (energy >= maxEnergy)
			energy = maxEnergy;
		return true;
	}

	if (energy >= maxEnergy)
		energy = maxEnergy;
	return false;
}

bool Car::energyFullCharge()
{
	if(energy==maxEnergy)
		return false;
	energy = maxEnergy;
	return true;
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

void Car::move(int n)
{
	position += n;
}


//Equality Operators

//Car to Car
bool operator==(Car const& lhs, Car const& rhs)
{
	return lhs.brand == rhs.brand
		&& lhs.model == rhs.model
		&& lhs.id == rhs.id
		&& lhs.maxEnergy == rhs.maxEnergy
		&& lhs.maxSpeed == rhs.maxSpeed
		&& lhs.speed == rhs.speed
		&& lhs.energy == rhs.energy
		&& lhs.movement == rhs.movement
		&& lhs.accelerationPedal == rhs.accelerationPedal
		&& lhs.brakePedal == rhs.brakePedal
		&& lhs.time == rhs.time
		&& lhs.position == rhs.position
		&& lhs.emergencySignal == rhs.emergencySignal
		&& lhs.isDamaged == rhs.isDamaged
		&& lhs.driver == rhs.driver;
}

bool operator!=(Car const& lhs, Car const& rhs)
{
	return !(lhs == rhs);
}

bool Car::operator<(const Car& other) const
{
	return position < other.position;
}

bool Car::operator>(const Car& other) const
{
	return position > other.position;
}

bool Car::operator<=(const Car& other) const
{
	return position <= other.position;
}

bool Car::operator>=(const Car& other) const
{
	return position >= other.position;
}



//Pointer Car to Car
bool operator==(Car* const& lhs, Car const& rhs)
{
	return lhs->getBrand() == rhs.getBrand()
		&& lhs->getModel() == rhs.getModel()
		&& lhs->getID() == rhs.getID()
		&& lhs->getMaxEnergy() == rhs.getMaxEnergy()
		&& lhs->getMaxSpeed() == rhs.getMaxSpeed()
		&& lhs->getSpeed() == rhs.getSpeed()
		&& lhs->getEnergy() == rhs.getEnergy()
		&& lhs->getMovement() == rhs.getMovement()
		&& lhs->getAccelerationPedal() == rhs.getAccelerationPedal()
		&& lhs->getBrakePedal() == rhs.getBrakePedal()
		&& lhs->getTime() == rhs.getTime()
		&& lhs->getPosition() == rhs.getPosition()
		&& lhs->getEmergencySignal() == rhs.getEmergencySignal()
		&& lhs->getDamage() == rhs.getDamage()
		&& lhs->getDriver() == rhs.getDriver();
}

bool operator!=(Car* const& lhs, Car const& rhs)
{
	return !(lhs == rhs);
}

//Car to Pointer Car
bool operator==(Car const& lhs, Car* const& rhs)
{
	return rhs == lhs;
}

bool operator!=(Car const& lhs, Car* const& rhs)
{
	return !(lhs == rhs);
}



std::ostream& operator<<(std::ostream& os, const Car& c)
{
	os << c.getAsString();
	return os;
}
