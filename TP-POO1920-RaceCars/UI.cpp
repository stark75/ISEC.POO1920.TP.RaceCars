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

	/*
	 * run() will run the commandline, and receive the user's inputs and validates it.
	 * the commands are divided according to the active mode (Configuration Mode and Championship Mode).
	 * That means that if you try to use a command, that maybe valid in one mode, but not on the other one.
	 * The only common command is "exit" or "sair" and it's the only command that's not case sensitive.
	 */

	View::printCommandLineMessage();
	
	std::string command = validateArgv(argc, argv);
	

	
	for(;;)
	{
		if (command.empty())
		{
			View::printCommandLineMessage();

			std::getline(std::cin, command);
		}

		bool validCommand = false;
			
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
				validCommand = true;
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

					validCommand = true;
				}

				if (argument == "carregaC")
				{
					//separator >> argument;
					View::printMessage("Carrega Carro not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator

					validCommand = true;
					
				}

				if (argument == "carregaP")
				{
					//separator >> argument;
					View::printMessage("Carrega Piloto not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
					
					validCommand = true;
				}

				if (argument == "deldgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Delete DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
					
					validCommand = true;
				}

				if (argument == "loaddgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Load DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator
					
					validCommand = true;
				}

				if (argument == "saidocarro")
				{
					//separator >> argument;
					View::printMessage("Sair do carro not implemented", View::WarningTypeMessage);
					//TODO
					//tirar do carro
					
					validCommand = true;
				}

				if (argument == "savedgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Save DGV not implemented", View::WarningTypeMessage);
					//TODO
					//Ler Ficheiro
					//Gerar vetor de autodromos no Simulator

					validCommand = true;
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

					validCommand = true;
				}

				if(argument == "entranocarro")
				{
					View::printMessage("entra no carro not implemented", View::WarningTypeMessage);

					validCommand = true;
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

					validCommand = true;
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

					validCommand = true;
				}
			}
		}

		if(mode == MenuMode::CHAMPIONSHIP)
		{
			if (command == "voltar")
			{
				View::printMessage("Menu mode switched to Config Mode", View::SuccessTypeMessage);
				switchMode();

				validCommand = true;
			}

			if (command == "carregatudo")
			{
				View::printMessage("Carrega Tudo not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if (command == "corrida")
			{
				View::printMessage("Corrida not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if (command == "listacarros")
			{
				View::printMessage("Lista de Carros not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if (command == "log")
			{
				View::printMessage("log not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if(Utils::argumentCount(command) == 2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "acidente")
				{
					View::printMessage("acidente not implemented", View::WarningTypeMessage);
					validCommand = true;
				}

				if (argument == "destroi")
				{
					View::printMessage("destroi not implemented", View::WarningTypeMessage);
					validCommand = true;
				}

				if (argument == "passatempo")
				{
					View::printMessage("passatempo not implemented", View::WarningTypeMessage);
					validCommand = true;
				}
				
			}

			if(Utils::argumentCount(command)==3)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "carregabat")
				{
					View::printMessage("carregabat not implemented", View::WarningTypeMessage);
					validCommand = true;
				}
			}

			if(Utils::argumentCount(command)>=2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "stop")
				{
					View::printMessage("stop not implemented", View::WarningTypeMessage);
					validCommand = true;
				}
			}
		}

		if(!validCommand)
			View::printMessage("Comando Invalido", View::ErrorTypeMessage);
		else
		{
			//TODO
		}
		
		View::printCommandLineMessage();
		std::getline(std::cin, command);
	}
}

bool UI::loadCars(std::string filename)
{
	
	return false;
}

bool UI::loadPilots(std::string filename)
{
	return false;
}
