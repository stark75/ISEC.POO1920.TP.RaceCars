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
	int speed;
	double energy;

	bool movement;
	int accelerationPedal;
	int brakePedal;

	int time;
	bool emergencySignal;
	bool isDamaged;
	Pilot* driver;
	
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
	int getAccelerationPedal() const;
	int getBrakePedal() const;
	bool getEmergencySignal() const;
	bool getDamage() const;
	
	std::string getAsString() const;

	//TODO: Car's actions
	bool pressAccelerate(int times = 1);
	bool pressBrake(int times = 1);
	bool energyCharge(int n);
	bool energyConsumption();

};

std::ostream& operator<<(std::ostream& os, const Car& c);