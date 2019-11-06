#pragma once
#include <string>
#include "Pilot.h"

class Car
{
	//Car ID
	static char nextID;
	std::string brand;
	std::string model;
	char id;

	//Car Specs
	const int maxEnergy;
	const int maxSpeed;

	//Car Stats
	Pilot* driver;
	int energy;
	int speed;
	int time;
	
		
public:
	Car(int mE, int mS, int e, std::string b, std::string m = "Base");
	~Car();

	char getNextID() const;
	std::string getBrand() const;
	std::string getModel() const;
	char getID() const;
	int getMaxEnergy() const;
	int getMaxSpeed() const;
	Pilot* getDriver() const;
	int getEnergy() const;
	int getSpeed() const;
	int getTime() const;
	
	std::string getAsString() const;
};

std::ostream& operator<<(std::ostream& os, const Car& c);