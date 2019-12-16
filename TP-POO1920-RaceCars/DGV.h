#pragma once
#include <vector>
#include "Car.h"

static std::vector<Car*> sortCars(std::vector<Car*> carList);

class DGV
{	
	std::vector<Car*> carList;
	std::vector<Pilot*> pilotList;
public:
	DGV();
	~DGV();

	std::vector<Car*> getCarList();

	bool addCar(const Car newCar);
	bool addPilot(const Pilot newPilot);

	bool removeCar(const char wantedID);
	bool removePilot(std::string wantedName);

	bool printCars();
	bool printPilots();

	Car* getCarById(char wantedID);
	Pilot* getPilotByName(std::string wantedName);
	bool attach(char id, std::string name);
	bool detach(char id);

	std::vector<Car*> getCarsWithPilots();

	int getNumberOfCarsWithPilots();

	//TODO apply this in Track Class
	static bool sortFunc(Car* lhs, Car* rhs);
	void sortCarsByPosition();
	
};