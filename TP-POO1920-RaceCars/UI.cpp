#include "UI.h"
#include <iostream>
#include <windows.h>

UI::UI()
{
}

UI::UI(Simulator s)
	:simulator(s)
{
}

void UI::switchMode()
{
	if (mode == CONFIG)
		mode = CHAMPIONSHIP;
	else
		mode = CONFIG;
}

std::string UI::validateArgv(const int argc, char* argv[])
{
	std::string command;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (i != 1) command += " ";
			command += argv[i];
		}
		Sleep(1000);
		std::cout << command << std::endl;

		if (argc > 3)
		{
			std::cout << "Comando Invalido." << std::endl;
			std::cout << "Introduza um comando: ";
			getline(std::cin, command);
		}
	}
	else
	{
		getline(std::cin, command);
	}

	return command;
}


void UI::run(const int argc, char* argv[])
{
}
