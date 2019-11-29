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

	bool addCar(int e, int mE, std::string b, std::string m = "Base");
	bool addPilot(std::string newName);
};

	