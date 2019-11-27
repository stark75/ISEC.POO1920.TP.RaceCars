#include <windows.h>
#include <iostream>
#include <sstream>
#include "UI.h"
#include "View.h"
#include "Utils.h"

UI::UI()
{
}

UI::UI(Simulator s)
	:simulator(s)
{
}

void UI::switchMode()
{
	if (mode == MenuMode::CONFIG)
		mode = MenuMode::CHAMPIONSHIP;
	else
		mode = MenuMode::CONFIG;
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
			View::printMessage("Commando Errado.", View::ErrorTypeMessage);
			View::printCommandLineMessage();
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
	//TODO PRINTS

	View::printCommandLineMessage();
	
	std::string command = validateArgv(argc, argv);
	
	for(;;)
	{
		if (command.empty())
		{
			View::printCommandLineMessage();

			std::getline(std::cin, command);
		}
			
		if(Utils::tolower(command) == "exit" || Utils::tolower(command) == "sair")
		{
			View::printMessage("Exiting!", View::WarningTypeMessage);
			return;
		}

		if (mode == MenuMode::CONFIG)
		{

			if(command == "lista")
			{
				//View::list(simulator);
				View::printMessage("Lista Not implemented", View::WarningTypeMessage);
			}

			if(Utils::argumentCount(command)==2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;
				if (argument == "carregaA")
				{
					//separator >> argument;
					View::printMessage("Carrega Autodromo not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}

				if (argument == "carregaC")
				{
					//separator >> argument;
					View::printMessage("Carrega Carro not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}

				if (argument == "carregaP")
				{
					//separator >> argument;
					View::printMessage("Carrega Piloto not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}

				if (argument == "deldgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Delete DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}

				if (argument == "loaddgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Load DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}

				if (argument == "saidocarro")
				{
					//separator >> argument;
					View::printMessage("Sair do carro not implemented", View::WarningTypeMessage);
					//TODO
					//tirar do carro
				}

				if (argument == "savedgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Save DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
				}
				
			}

			if(Utils::argumentCount(command)>=3)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if(argument == "apaga")
				{
					View::printMessage("apaga not implemented", View::WarningTypeMessage);
				}

				if(argument == "entranocarro")
				{
					View::printMessage("entra no carro not implemented", View::WarningTypeMessage);
				}
			}

			if(Utils::argumentCount(command)>=4)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if(argument == "cria")
				{
					View::printMessage("criar objetos not implemented", View::WarningTypeMessage);
				}
			}

			if(Utils::argumentCount(command)>=2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if(argument == "campeonato")
				{
					View::printMessage("Campeonato not implemented.\nMenu Mode has been switched to Championship Mode", View::WarningTypeMessage);
					switchMode();
				}
			}
		}

		if(mode == MenuMode::CHAMPIONSHIP)
		{
			if(command == "voltar")
			{
				View::printMessage("Menu mode switched to Config Mode", View::SuccessTypeMessage);
			}
		}

		View::printMessage("Comando Inválido", View::ErrorTypeMessage); //TODO create a check var
		View::printCommandLineMessage();
		std::getline(std::cin, command);
	}
}
