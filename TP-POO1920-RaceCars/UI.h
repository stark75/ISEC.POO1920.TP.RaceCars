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
	UI(Simulator s);
	~UI() = default;

	void switchMode();

	std::string validateArgv(const int argc, char* argv[]);
	void run(const int argc = 0, char* argv[] = nullptr);

	//int commandLine(std::string command);
	
	
	
};

