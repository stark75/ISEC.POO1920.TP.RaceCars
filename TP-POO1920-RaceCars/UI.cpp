#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "UI.h"
#include "View.h"
#include "Utils.h"

UI::UI() = default;

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
		View::clearScreen();
		for (int i = 0; i < n; i++)
		{
			simulator.passOneSecond();
			View::printRace(simulator);

			if(simulator.checkEndOfRace())
			{
				if(!simulator.nextRace())
				{
					View::printStandings(simulator);
					View::printMessage("Campeonato Terminado.", View::WarningTypeMessage);
					simulator.clearChampionship();
					switchMode();
				}
				break;
			}
		}
		return true;
	}
	View::printMessage("Nao ha carros na pista.", View::ErrorTypeMessage);
	return false;
}

void UI::raceCommand()
{
	if (simulator.startRace())
		View::printMessage("Corrida Iniciada.", View::SuccessTypeMessage);
	else
		View::printMessage("Corrida nao iniciada.", View::ErrorTypeMessage);
}

void UI::startChampionship(const std::string racetracks)
{
	if (racetracks[0] == '-')
	{
		std::istringstream separator(racetracks);

		std::string argument;

		std::string tmpString;

		std::vector<std::string> racetracksNameList;

		bool firstRacetrack = true;
		
		while (separator >> argument)
		{
			if (argument[0] == '-')
			{
				if (!firstRacetrack)
				{
					if (!tmpString.empty())
						racetracksNameList.push_back(tmpString);
					else
					{
						View::printMessage("Autodromo Invalido.", View::ErrorTypeMessage);
						return;
					}
					tmpString = "";
				}
				else
					firstRacetrack = false;
				argument.erase(argument.begin());
			}
			else
				tmpString += " ";

			tmpString += argument;
		}

		if(!tmpString.empty())
		{
			racetracksNameList.push_back(tmpString);
		}
		else
		{
			View::printMessage("Autodromo Invalido.", View::ErrorTypeMessage);
			return;
		}

		int vectorSize = static_cast<int>(racetracksNameList.size());

		for(int i=0; i<vectorSize;i++)
		{
			int verifier = simulator.checkIfItsPossibleToStartAChampionship(racetracksNameList[i]);

			if (verifier != 1)
			{
				if (verifier == 0)
					View::printMessage("Campeonato Invalido: Numero de Carros Invalido.", View::ErrorTypeMessage);
				else if (verifier == -1)
					View::printMessage("Campeonato Invalido: Autodromo Invalido.", View::ErrorTypeMessage);
				else if (verifier == -2)
					View::printMessage("Campeonato Invalido: Autodromo e Numero de Carros Invalidos.", View::ErrorTypeMessage);
				else
					View::printMessage("Campeonato Invalido: Erro Desconhecido.", View::ErrorTypeMessage);

				return;
			}
		}

		if (simulator.addChampionship(racetracksNameList))
		{
			simulator.chargeAllCars();
			View::printMessage("Campeonato Criado", View::SuccessTypeMessage);
			switchMode();
		}
		else
			View::printMessage("Erro ao criar o Campeonato", View::ErrorTypeMessage);
		
	}
	else
	{

		int verifier = simulator.checkIfItsPossibleToStartAChampionship(racetracks);

		if (verifier == 1)
		{
			if (simulator.addChampionship(racetracks))
			{
				View::printMessage("Campeonato Criado", View::SuccessTypeMessage);
				switchMode();
			}
			else
				View::printMessage("Erro ao criar o Campeonato", View::ErrorTypeMessage);
		}
		else
		{
			if (verifier == 0)
				View::printMessage("Campeonato Invalido: Numero de Carros Invalido.", View::ErrorTypeMessage);
			else if (verifier == -1)
				View::printMessage("Campeonato Invalido: Autodromo Invalido.", View::ErrorTypeMessage);
			else if (verifier == -2)
				View::printMessage("Campeonato Invalido: Autodromo e Numero de Carros Invalidos.", View::ErrorTypeMessage);
			else
				View::printMessage("Campeonato Invalido: Erro Desconhecido.", View::ErrorTypeMessage);

		}
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
			
		if (Utils::tolower(command) == "sair" || Utils::tolower(command) == "exit")
		{
			View::printMessage("Exiting!", View::WarningTypeMessage);
			exit(0);
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
			
			if (command == "loadACP") //DEBUG COMMAND
			{
				loadRacetrack("racetracks.txt");
				loadCars("cars.txt");
				loadPilots("pilots.txt");
				validCommand = true;
			}
			
			if (Utils::argumentCount(command) == 2)
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

				if (argument == "deldgv")
				{
					separator >> argument;

					if (simulator.deleteDGV(argument))
						View::printMessage("DGV apagado.", View::SuccessTypeMessage);
					else
						View::printMessage("DGV nao apagado.", View::ErrorTypeMessage);
					
					
					validCommand = true;
				}

				if (argument == "loaddgv")
				{
					separator >> argument;

					if (simulator.loadDGV(argument))
						View::printMessage("DGV Carregado.", View::SuccessTypeMessage);
					else
						View::printMessage("DGV nao Carregado.", View::ErrorTypeMessage);
					
					validCommand = true;
				}

				if (argument == "saidocarro")
				{
					separator >> argument;

					if (static_cast<int>(argument.size()) == 1)
					{
						char tmpChar = argument[0];

						if (simulator.detach(tmpChar))
							View::printMessage("Piloto removido.", View::SuccessTypeMessage);
						else
							View::printMessage("Piloto nao removido.", View::ErrorTypeMessage);

						validCommand = true;
					}
				}

				if (argument == "savedgv")
				{
					separator >> argument;

					if (simulator.addDGV(argument))
						View::printMessage("DGV guardado.", View::SuccessTypeMessage);
					else
						View::printMessage("Nome ja existente.", View::ErrorTypeMessage);
					
					validCommand = true;
				}

			}

			if (Utils::argumentCount(command) >= 3)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "entranocarro")
				{
					separator >> argument;

					if (!Utils::isNumber(argument))
					{
						if (static_cast<int>(argument.size()) == 1)
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

							if (simulator.attach(tmpChar, tmpString))
								View::printMessage("Piloto entrou no carro.", View::SuccessTypeMessage);
							else
								View::printMessage("Piloto impossibilitado de entrar no carro.", View::ErrorTypeMessage);

							validCommand = true;
						}
					}
				}

				if (argument == "apaga")
				{
					separator >> argument;

					if (argument == "a")
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

						if (simulator.removeRacetrack(tmpName))
							View::printMessage("Autodromo Removido.", View::SuccessTypeMessage);
						else
							View::printMessage("Autodromo nao removido", View::ErrorTypeMessage);

						validCommand = true;

					}

					if (argument == "c")
					{
						separator >> argument;

						if (static_cast<int>(argument.size()) == 1)
						{
							if (simulator.removeCar(argument[0]))
								View::printMessage("Carro Removido.", View::SuccessTypeMessage);
							else
								View::printMessage("Carro nao removido.", View::ErrorTypeMessage);
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

						if (simulator.removePilot(tmpName))
							View::printMessage("Piloto Removido.", View::SuccessTypeMessage);
						else
							View::printMessage("Piloto nao Removido.", View::ErrorTypeMessage);

						validCommand = true;
					}

				}

			}

			if (Utils::argumentCount(command) >= 4)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "cria")
				{
					separator >> argument;

					if (argument == "a") //autodromo
					{
						separator >> argument;

						if (Utils::isNumber(argument))
						{
							int tmpMaxCars = std::stoi(argument);

							separator >> argument;

							if (Utils::isNumber(argument))
							{
								int tmpLength = std::stoi(argument);

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

								if (tmpString[0] != '-')
								{
									if (simulator.addRacetrack(tmpMaxCars, tmpLength, tmpString))
									{
										View::printMessage("Autodromo gerado.", View::SuccessTypeMessage);
									}
									else
									{
										View::printMessage("Parametros do Autodromo Invalidos.", View::ErrorTypeMessage);
									}
									validCommand = true;
								}
								else
								{
									View::printMessage("Nome de Autodromo invalido.", View::ErrorTypeMessage);
								}

							}
						}

					}

					if (argument == "c") //carro
					{
						separator >> argument;

						if (Utils::isNumber(argument))
						{
							int tmpMaxSpeed = std::stoi(argument);

							separator >> argument;

							if (Utils::isNumber(argument))
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

										if (simulator.addCar(tmpEnergy, tmpMaxEnergy, tmpMaxSpeed, tmpBrand, tmpString))
											View::printMessage("Carro gerado.", View::SuccessTypeMessage);
										else
											View::printMessage("Parametros Errados.", View::ErrorTypeMessage);
									}
									else
									{
										if (simulator.addCar(tmpEnergy, tmpMaxEnergy, tmpMaxSpeed, tmpBrand))
											View::printMessage("Carro gerado.", View::SuccessTypeMessage);
										else
											View::printMessage("Parametros Errados.", View::ErrorTypeMessage);
									}
									validCommand = true;
								}
							}
						}
					}

					if (argument == "p") //piloto
					{
						separator >> argument;

						if (argument == "rapido" || argument == "crazy" || argument == "surpresa")
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

							if (simulator.addPilot(tmpType, tmpString))
								View::printMessage("Piloto gerado.", View::SuccessTypeMessage);
							else
								View::printMessage("Parametros errados.", View::ErrorTypeMessage);
							validCommand = true;
						}

					}

				}

			}

			if (Utils::argumentCount(command) >= 2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "campeonato")
				{
					std::string tmpString = "";

					bool isFirstTime = true;

					while (separator >> argument)
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
			if (command == "carregatudo")
			{
				simulator.chargeAllCars();
				View::printMessage("Todos os carros foram carregados.", View::SuccessTypeMessage);
				validCommand = true;
			}

			if (command == "corrida")
			{
				raceCommand();
				validCommand = true;
			}

			if (command == "listacarros")
			{
				View::printCarsOnChampionship(simulator);
				validCommand = true;
			}

			if (command == "log")
			{
				View::printLog(simulator);
				validCommand = true;
			}

			if(Utils::argumentCount(command) == 2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "acidente")
				{
					separator >> argument;
					if (static_cast<int>(argument.size()) == 1)
					{
						if (simulator.accident(argument[0]))
							View::printMessage("Acidente Ocorrido.", View::SuccessTypeMessage);
						else
							View::printMessage("Acidente nao Ocorrido.", View::ErrorTypeMessage);
						validCommand = true;
					}
				}

				if (argument == "destroi")
				{
					separator >> argument;

					if (static_cast<int>(argument.size()) == 1)
					{
						if (simulator.destroyCar(argument[0]))
							View::printMessage("Carro Destruido.", View::SuccessTypeMessage);
						else
							View::printMessage("Carro nao Destruido.", View::ErrorTypeMessage);
						validCommand = true;
					}
				}

				if (argument == "passatempo")
				{
					separator >> argument;

					if(Utils::isNumber(argument))
					{
						int time = std::stoi(argument);

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

				if (argument == "carregabat")
				{
					separator >> argument;

					if(static_cast<int>(argument.size()) == 1)
					{
						if(Utils::isAlpha(argument[0]))
						{
							char tmpChar = argument[0];

							separator >> argument;

							if(Utils::isNumber(argument))
							{
								int tmpInt = std::stoi(argument);

								if (simulator.chargeCar(tmpChar, tmpInt))
									View::printMessage("Carro carregado.", View::SuccessTypeMessage);
								else
									View::printMessage("Carro nao carregado.", View::ErrorTypeMessage);

								validCommand = true;
							}
						}
					}
				}
			}

			if(Utils::argumentCount(command)>=2)
			{
				std::istringstream separator(command);
				std::string argument;
				separator >> argument;

				if (argument == "stop")
				{
					std::string tmpString = "";

					bool isFirstTime = true;

					while (separator >> argument)
					{
						if (isFirstTime)
							isFirstTime = false;
						else
							tmpString += " ";
						tmpString += argument;
					}

					if (simulator.stopPilot(tmpString))
						View::printMessage("O Piloto recebeu a ordem de parar.", View::SuccessTypeMessage);
					else
						View::printMessage("Nao houve ordem para parar.", View::ErrorTypeMessage);
					
					validCommand = true;
				}
			}
		}

		if(!validCommand)
			View::printMessage("Comando Invalido.", View::ErrorTypeMessage);
		
		View::printCommandLineMessage();
		std::getline(std::cin, command);
	}
}

bool UI::loadRacetrack(const std::string filename)
{
	std::ifstream racetrackFile;
	std::string buffer;
	int invalidRacetracks = 0;

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
				bool valid = true;
				while (separator >> storedValue)
				{
					if (firstTime)
					{
						if (storedValue[0] == '-')
						{
							invalidRacetracks++;
							valid = false;
							break;
						}

						firstTime = false;
					}
					else
						tmpName += " ";
					tmpName += storedValue;
				}

				if (valid)
					if (!simulator.addRacetrack(maxCars, trackLength, tmpName))
						invalidRacetracks++;

			}
		}

		racetrackFile.close();
		if (invalidRacetracks == 0)
		{
			View::printMessage("Ficheiro carregado na totalidade.", View::SuccessTypeMessage);
		}
		else
		{
			View::printInvalidRacetracks(invalidRacetracks);
		}
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

				if(storedValue == "crazy" || storedValue == "rapido" || storedValue == "surpresa")
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