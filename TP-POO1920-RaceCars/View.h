#pragma once
#include <string>
#include "Simulator.h"

class View
{
	
public:
	
	static const int ErrorTypeMessage = 0;
	static const int WarningTypeMessage = 1;
	static const int SuccessTypeMessage = 2;
	static const int NullTypeMessage = 3;
	
	View() = delete;

	static void clearScreen();
	static void printTitle();
	static void printMessage(const std::string& message = "No message.", int type = NullTypeMessage);
	static void printCommandLineMessage();
	static void helpCommand();
	static void printLog(Simulator &s);
	static void printModelsInfoCommand(Simulator& s);
	static void printCarsOnChampionship(Simulator& s);
	static void printRace(Simulator& s);
	static void printStandings(Simulator& s);
	static void printInvalidRacetracks(int invalidRacetracks);
};

