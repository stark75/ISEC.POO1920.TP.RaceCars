#pragma once
#include <vector>
#include "Car.h"

static std::vector<Car*> sortCars(std::vector<Car*> carList);

class DGV
{	
	std::vector<Car*> carNames;
	std::vector<Pilot*> pilotNames;
public:
	DGV();
	~DGV();

	bool addCar(const Car newCar);
	bool addPilot(const Pilot newPilot);

	static bool sortFunc(Car* lhs, Car* rhs);

	void printPosition();
	void sortCarsByPosition();
};