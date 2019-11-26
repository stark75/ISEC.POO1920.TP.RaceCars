#include "View.h"
#include <iostream>

void View::printTitle()
{
	std::cout << "________                  _________" << std::endl;
	std::cout << "___  __ \\_____ _____________  ____/_____ _______________" << std::endl;
	std::cout << "__  /_/ /  __ `/  ___/  _ \\  /    _  __ `/_  ___/_  ___/" << std::endl;
	std::cout << "_  _, _// /_/ // /__ /  __/ /___  / /_/ /_  /   _(__  )" << std::endl;
	std::cout << "/_/ |_| \\__,_/ \\___/ \\___/\\____/  \\__,_/ /_/    /____/\n" << std::endl;
	
	std::cout << " _.-.___\\__         _.-.___\\__         _.-.___\\__" << std::endl;
	std::cout << "|  _      _`-.     |  _      _`-.     |  _      _`-." << std::endl;
	std::cout << "'-(_)----(_)--`    '-(_)----(_)--`    '-(_)----(_)--`" << std::endl;
	
	
}

void View::printMessage(std::string message, MessageType type)
{
	std::string output;
	
	if (type == ErrorType)
	{
		output = "[ERROR]: ";
		output += message;
	}

	if (type == WarningType)
	{
		output = "[WARNING]: ";
		output += message;
	}

	if (type == SuccessType)
	{
		output = "[SUCCESS]: ";
		output += message;
	}

	if (type == NullType)
	{
		output = message;
	}

	std::cout << output << std::endl;
	
}
