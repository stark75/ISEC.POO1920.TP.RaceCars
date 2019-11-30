#pragma once
#include <vector>
#include "DGV.h"

class Simulator
{
	DGV currentDGV;
	//std::vector<Racetrack> racetracks;
	//Championship
	//Championship Hall of Fame
	//
public:

	Simulator();
	~Simulator() = default;

	DGV* getDGV();

	bool attach(char carID, std::string pilotName);
	bool detach(char carID);
	
	bool addCar(int e, int mE, int mS, std::string b, std::string m = "Base");
	bool addPilot(std::string type, std::string newName);
};

	