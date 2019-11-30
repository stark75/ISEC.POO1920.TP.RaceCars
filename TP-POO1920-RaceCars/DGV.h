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

	bool addCar(const Car newCar);
	bool addPilot(const Pilot newPilot);

	void printPilots();
	void printPosition();

	//TODO apply this in Track Class
	static bool sortFunc(Car* lhs, Car* rhs);
	void sortCarsByPosition();
	
};