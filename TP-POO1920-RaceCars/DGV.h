#pragma once
#include <vector>
#include "Car.h"

class DGV
{	
	std::vector<Car*> carNames;
	std::vector<Pilot*> pilotNames;
public:
	DGV();
	~DGV();

	bool addCar(const Car newCar);
	bool addPilot(const Pilot newPilot);
};