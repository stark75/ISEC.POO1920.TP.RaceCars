#pragma once
#include "Simulator.h"
#include <string>

class UI
{
	Simulator simulator;

	enum Menu
	{
		CONFIG,
		CHAMPIONSHIP
	};

	Menu mode;

public:
	UI(Simulator s);
	~UI() = default;

	void switchMode();

	void run(const int argc = 0, char* argv[] = nullptr);

	int commandLine(std::string command);
	std::string validateArgv(const int argc, char* argv[]);
	
	
};

