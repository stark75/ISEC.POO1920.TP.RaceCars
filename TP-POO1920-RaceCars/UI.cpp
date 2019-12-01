#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
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
				//TODO falta print do Autodromo
				View::printInfoCommand(simulator);
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
					separator >> argument;
					
					loadCars(argument);
					
					validCommand = true;
					
				}

				if (argument == "carregaP")
				{
					separator >> argument;
					//View::printMessage("Carrega Piloto not implemented", View::WarningTypeMessage);

					loadPilots(argument);
					
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
					separator >> argument;
					//View::printMessage("Sair do carro not implemented", View::WarningTypeMessage);
					//TODO
					//tirar do carro
					
					if (argument.size() == 1)
					{
						char tmpChar = argument[0];
						simulator.detach(tmpChar);
						validCommand = true;
					}
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

				if (argument == "entranocarro")
				{
					separator >> argument;

					if (!Utils::isNumber(argument))
					{
						if (argument.size() == 1)
						{
							char tmpChar = argument[0];
							std::string tmpString = "";

							bool firstTime = true;

							while (separator >> argument) {
								if (firstTime)
									firstTime = false;
								else 
									tmpString += " ";

									tmpString += argument;
								
							}

							simulator.attach(tmpChar, tmpString);
							
							validCommand = true;
						}
					}
					//View::printMessage("entra no carro not implemented", View::WarningTypeMessage);


				}

				
				if(argument == "apaga")
				{
					View::printMessage("apaga not implemented", View::WarningTypeMessage);

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

bool UI::loadCars(const std::string filename)
{
	std::ifstream carsFile;
	std::string buffer;

	carsFile.open(filename);
	
	if(carsFile.is_open())
	{
		while (std::getline(carsFile, buffer))
		{
			if (Utils::argumentCount(buffer) >= 4)
			{
				std::istringstream separator(buffer);
				std::string storedValue;
				separator >> storedValue;

				//Check MaxSpeed

				if (!Utils::isNumber(storedValue))
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					carsFile.close();
					return false;
				}

				int tmpMaxSpeed = std::stoi(storedValue);

				//Check Energy

				separator >> storedValue;

				if (!Utils::isNumber(storedValue))
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					carsFile.close();
					return false;
				}

				int tmpEnergy = std::stoi(storedValue);

				//Check Energy

				separator >> storedValue;

				if (!Utils::isNumber(storedValue))
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					carsFile.close();
					return false;
				}

				int tmpMaxEnergy = std::stoi(storedValue);

				//Save Brand

				separator >> storedValue;

				std::string tmpBrand = storedValue;


				//Save Model
				if (Utils::argumentCount(buffer) > 4)
				{
					std::string tmpModel = "";
					while (separator >> storedValue)
					{
						tmpModel += storedValue;
					}
					simulator.addCar(tmpEnergy, tmpMaxEnergy, tmpMaxSpeed, tmpBrand, tmpModel);
				}
				else
				{
					simulator.addCar(tmpEnergy, tmpMaxEnergy, tmpMaxSpeed, tmpBrand);
				}
			}
			else
			{
				View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
				carsFile.close();
				return false;
			}
		}

		carsFile.close();
		View::printMessage("Ficheiro carregado.", View::SuccessTypeMessage);
		return true;
	}

	View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
	return false;
	
}

bool UI::loadPilots(std::string filename)
{
	std::ifstream pilotsFile;
	std::string buffer;

	pilotsFile.open(filename);

	if (pilotsFile.is_open())
	{
		while (std::getline(pilotsFile, buffer))
		{
			if (Utils::argumentCount(buffer) >= 2)
			{
				std::istringstream separator(buffer);
				std::string storedValue;
				separator >> storedValue;

				std::string tmpType = storedValue;

				if(storedValue == "generico")
				{
					std::string tmpName = "";
					bool firstTime = true;
					while (separator >> storedValue)
					{
						if (firstTime)
							firstTime = false;
						else
							tmpName += " ";
						tmpName += storedValue;
					}
					simulator.addPilot(tmpType,tmpName);
				}
				else
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					pilotsFile.close();
					return false;
				}
				
			}
			else
			{
				View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
				pilotsFile.close();
				return false;
			}
		}

		pilotsFile.close();
		View::printMessage("Ficheiro carregado.", View::SuccessTypeMessage);
		return true;
		
	}

	View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
	return false;
}