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
	const double maxEnergy;
	const int maxSpeed;

	//Car Stats
	Pilot* driver;
	double energy;
	int speed;
	int time;
	bool movement;
	bool emergencySignal;
		
public:
	Car(int mE, int mS, int e, std::string b, std::string m = "Base");
	~Car();

	//Getters
	char getNextID() const;
	std::string getBrand() const;
	std::string getModel() const;
	char getID() const;
	double getMaxEnergy() const;
	int getMaxSpeed() const;
	Pilot* getDriver() const;
	double getEnergy() const;
	int getSpeed() const;
	int getTime() const;
	bool getMovement() const;
	bool getEmergencySignal() const;
	std::string getAsString() const;

	//TODO: Car's actions
	bool accelerate(int times = 1);
	bool brake(int times = 1);
	bool energyCharge(int n);
	bool energyConsumption();

};

std::ostream& operator<<(std::ostream& os, const Car& c);