#pragma once
#include <vector>
#include "Car.h"

class DGV
{	
	std::vector<Car*> carList;
	std::vector<Pilot*> pilotList;
public:
	DGV() = default;
	DGV(const DGV& src);
	~DGV();

	std::vector<Car*> getCarList();

	bool   addCar(const Car newCar);
	bool   addPilot(const Pilot newPilot);

	bool   removeCar(const char wantedID);
	bool   removePilot(std::string wantedName);

	bool   printCars();
	bool   printPilots();

	Car*   getCarById(char wantedID);
	Pilot* getPilotByName(std::string wantedName);
	bool   attach(char id, std::string name);
	bool   detach(char id);
	void   detachAll();

	std::vector<Car*> getCarsWithPilots();

	int getNumberOfCarsWithPilots();

	DGV& operator = (const DGV& src);
};