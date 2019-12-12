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

bool UI::timePassCommand(int n)
{
	if (simulator.checkIfItsPossibleToStartARace())
	{
		for (int i = 0; i < n; i++)
		{
			simulator.passOneSecond();
		}
		return true;
	}
	return false;
}

void UI::raceCommand()
{
		simulator.startRace();	
}

void UI::startChampionship(const std::string racetracks)
{
	//Include iss and check multiple racetracks

	//check if string begins with a "-" to identify one or multiple racetracks

	int numberOfRacetracks = 0; //Count how many Racetracks are
	
	
	int verifier = simulator.checkIfItsPossibleToStartAChampionship(racetracks);

	if (verifier == 1)
	{
		if (simulator.addChampionship(racetracks))
		{
			View::printMessage("Campeonato Criado", View::SuccessTypeMessage);
			switchMode();
		}
		else
		{
			View::printMessage("Erro ao criar o Campeonato", View::ErrorTypeMessage);
		}
	}
	else
	{
		if (verifier == 0)
			View::printMessage("Campeonato Invalido: Numero de Carros Invalido", View::ErrorTypeMessage);
		else if (verifier == -1)
			View::printMessage("Campeonato Invalido: Autodromo Invalido", View::ErrorTypeMessage);
		else if (verifier == -2)
			View::printMessage("Campeonato Invalido: Autodromo e Numero de Carros Invalidos", View::ErrorTypeMessage);
		else
			View::printMessage("Campeonato Invalido: Erro Desconhecido", View::ErrorTypeMessage);

	}
}

void UI::run(const int argc, char* argv[])
{
	View::printTitle();

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
			
		if(Utils::tolower(command) == "sair" || Utils::tolower(command) == "exit")
		{
			View::printMessage("Exiting!", View::WarningTypeMessage);
			return;
		}

		if (mode == MenuMode::CONFIG)
		{

			if (command == "lista" || command == "list")
			{
				View::printModelsInfoCommand(simulator);
				validCommand = true;
			}

			if (command == "ajuda" || command == "help")
			{
				View::helpCommand();
				validCommand = true;
			}

			if (command == "campeonato" || command == "championship")
			{
				if(simulator.getChampionship()!=nullptr)
				{
					switchMode();
					View::printMessage("Modo Campeonato reativado.", View::SuccessTypeMessage);
					validCommand=true;
				}
			}
			
			if (command == "loadACP") //DEBUG COMMAND
			{
				loadRacetrack("racetracks.txt");
				loadCars("cars.txt");
				loadPilots("pilots.txt");
				validCommand = true;
			}
			
			if(Utils::argumentCount(command)==2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;
				if (argument == "carregaA")
				{
					separator >> argument;

					loadRacetrack(argument);

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

					loadPilots(argument);
					
					validCommand = true;
				}

				if (argument == "deldgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Delete DGV not implemented", View::WarningTypeMessage);
					//TODO
					validCommand = true;
				}

				if (argument == "loaddgv") //TODO Meta2
				{
					//separator >> argument;
					View::printMessage("Load DGV not implemented", View::WarningTypeMessage);
					//TODO
					validCommand = true;
				}

				if (argument == "saidocarro")
				{
					separator >> argument;
					
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

							while (separator >> argument)
							{
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
				}

				
				if(argument == "apaga")
				{
					separator >> argument;

					if(argument == "a")
					{
						std::string tmpName = "";
						bool firstTime = true;
						while (separator >> argument)
						{
							if (firstTime)
								firstTime = false;
							else
								tmpName += " ";
							tmpName += argument;
						}

						simulator.removeRacetrack(tmpName);

						validCommand = true;
						
					}

					if(argument == "c")
					{
						separator >> argument;

						if(argument.size()==1)
						{
							simulator.removeCar(argument[0]);
							validCommand = true;
						}
						
					}

					if (argument == "p")
					{
						std::string tmpName = "";
						bool firstTime = true;
						while (separator >> argument)
						{
							if (firstTime)
								firstTime = false;
							else
								tmpName += " ";
							tmpName += argument;
						}

						simulator.removePilot(tmpName);

						validCommand = true;

					}

				}

			}

			if(Utils::argumentCount(command)>=4)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if(argument == "cria")
				{
					separator >> argument;

					if(argument == "a") //autodromo
					{
						separator >> argument;

						if(Utils::isNumber(argument))
						{
							int tmpMaxCars = std::stoi(argument);

							separator >> argument;

							if (Utils::isNumber(argument))
							{
								int tmpLength = std::stoi(argument);

								std::string tmpString="";

								bool firstTime = true;

								while (separator >> argument)
								{
									if (firstTime)
										firstTime = false;
									else
										tmpString += " ";

									tmpString += argument;

								}


								simulator.addRacetrack(tmpMaxCars, tmpLength, tmpString);
								validCommand = true;
								
							}
						}
					}

					if(argument == "c") //carro
					{
						separator >> argument;

						if(Utils::isNumber(argument))
						{
							int tmpMaxSpeed= std::stoi(argument);
							
							separator >> argument;

							if(Utils::isNumber(argument))
							{
								int tmpEnergy = std::stoi(argument);

								separator >> argument;

								
								if (Utils::isNumber(argument))
								{
									int tmpMaxEnergy = std::stoi(argument);

									separator >> argument;

									std::string tmpBrand = argument;

									if (Utils::argumentCount(command) >= 7)
									{
										std::string tmpString = "";

										bool firstTime = true;

										while (separator >> argument)
										{
											if (firstTime)
												firstTime = false;
											else
												tmpString += " ";

											tmpString += argument;

										}

										simulator.addCar(tmpEnergy, tmpMaxEnergy, tmpMaxSpeed, tmpBrand, tmpString);
									}
									else
									{
										simulator.addCar(tmpEnergy,tmpMaxEnergy, tmpMaxSpeed, tmpBrand);
									}
									validCommand = true;
								}
							}
						}
					}

					if(argument == "p") //piloto
					{
						separator >> argument;

						if(argument == "rapido" || argument == "crazy" || argument == "surpresa" || argument == "generico"/*remover para a próxima meta*/)
						{
							std::string tmpType = argument;
							std::string tmpString = "";

							bool firstTime = true;

							while (separator >> argument)
							{
								if (firstTime)
									firstTime = false;
								else
									tmpString += " ";

								tmpString += argument;

							}

							//TODO Create a new method
							simulator.addPilot(tmpType,tmpString);
							validCommand = true;
						}
						
					}

				}
			}

			if(Utils::argumentCount(command)>=2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "campeonato")
				{
					std::string tmpString = "";

					bool isFirstTime = true;

					while(separator >> argument)
					{
						if (isFirstTime)
							isFirstTime = false;
						else
							tmpString += " ";
						tmpString += argument;
					}

					startChampionship(tmpString);
					
					validCommand = true;
				}
			}
		}

		if (mode == MenuMode::CHAMPIONSHIP)
		{
			if (command == "voltar")
			{
				View::printMessage("Menu mode switched to Config Mode", View::SuccessTypeMessage);
				switchMode();

				validCommand = true;
			}

			if (command == "carregatudo") //TODO
			{
				View::printMessage("Carrega Tudo not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if (command == "corrida")
			{
				raceCommand();

				validCommand = true;
			}

			if (command == "listacarros") //TODO
			{
				View::printMessage("Lista de Carros not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if (command == "log") //TODO
			{
				View::printMessage("log not implemented", View::WarningTypeMessage);

				validCommand = true;
			}

			if(Utils::argumentCount(command) == 2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "acidente") //TODO
				{
					View::printMessage("acidente not implemented", View::WarningTypeMessage);
					validCommand = true;
				}

				if (argument == "destroi") //TODO
				{
					View::printMessage("destroi not implemented", View::WarningTypeMessage);
					validCommand = true;
				}

				if (argument == "passatempo")
				{
					separator >> argument;

					if(Utils::isNumber(argument))
					{
						int time = std::stoi(argument);

						//DO A PRINT MESSAGE IN CASE OF FAILURE OR SUCESS
						timePassCommand(time);
						
						validCommand = true;
					}
				}
				
			}

			if(Utils::argumentCount(command)==3)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "carregabat") //TODO
				{
					View::printMessage("carregabat not implemented", View::WarningTypeMessage);
					validCommand = true;
				}
			}

			if(Utils::argumentCount(command)>=2) //TODO
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
		
		View::printCommandLineMessage();
		std::getline(std::cin, command);
	}
}

bool UI::loadRacetrack(const std::string filename)
{
	std::ifstream racetrackFile;
	std::string buffer;

	racetrackFile.open(filename);

	if (racetrackFile.is_open())
	{
		while (std::getline(racetrackFile, buffer))
		{
			if (Utils::argumentCount(buffer) >= 3)
			{
				std::istringstream separator(buffer);
				std::string storedValue;

				separator >> storedValue;

				//Max Carros
				if (!Utils::isNumber(storedValue))
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					racetrackFile.close();
					return false;
				}

				int maxCars = std::stoi(storedValue);

				separator >> storedValue;

				//Length da Racetrack
				if (!Utils::isNumber(storedValue))
				{
					View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
					racetrackFile.close();
					return false;
				}

				int trackLength = std::stoi(storedValue);

				//Nome da Racetrack

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

				simulator.addRacetrack(maxCars, trackLength, tmpName);
							   
			}
		}

		racetrackFile.close();
		View::printMessage("Ficheiro carregado.", View::SuccessTypeMessage);
		return true;
	}
	View::printMessage("Ficheiro Invalido.", View::ErrorTypeMessage);
	return false;
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

				//Check Max Energy

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
					bool firstTime = true;
					while (separator >> storedValue)
					{
						if (firstTime)
							firstTime = false;
						else
							tmpModel += " ";
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

bool UI::loadPilots(const std::string filename)
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