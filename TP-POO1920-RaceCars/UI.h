#pragma once
#include "Simulator.h"
#include <string>

class UI
{
	Simulator simulator;

	enum class MenuMode
	{
		CONFIG,
		CHAMPIONSHIP
	};

	MenuMode mode = MenuMode::CONFIG;

public:
	UI();
	~UI() = default;

	void switchMode();

	std::string validateArgv(const int argc, char* argv[]);
	bool timePassCommand(int n);
	void raceCommand();

	void startChampionship(const std::string racetracks);
	
	bool loadCars(const std::string filename);
	bool loadPilots(const std::string filename);
	bool loadRacetrack(const std::string filename);

	void run(const int argc = 0, char* argv[] = nullptr);
};

