#pragma once
#include <string>

class View
{
	
public:

	
	static const int ErrorTypeMessage = 0;
	static const int WarningTypeMessage = 1;
	static const int SuccessTypeMessage = 2;
	static const int NullTypeMessage = 3;
	
	View() = delete;
	
	static void printTitle();

	static void printMessage(std::string message = "No message.", int type = NullTypeMessage);
	static void printCommandLineMessage();
	static void helpCommand();
};

