#include "View.h"
#include <iostream>
#include "Consola/Consola.h"
#include "Utils.h"

void View::printTitle()
{
	Consola::setTextColor(Consola::VERDE);
	std::cout << "________                  _________" << std::endl;
	std::cout << "___  __ \\_____ _____________  ____/_____ _______________" << std::endl;
	std::cout << "__  /_/ /  __ `/  ___/  _ \\  /    _  __ `/_  ___/_  ___/" << std::endl;
	std::cout << "_  _, _// /_/ // /__ /  __/ /___  / /_/ /_  /   _(__  )" << std::endl;
	std::cout << "/_/ |_| \\__,_/ \\___/ \\___/\\____/  \\__,_/ /_/    /____/\n" << std::endl;
	
	std::cout << R"( _.-.___\__         _.-.___\__         _.-.___\__)" << std::endl;
	std::cout << "|  _      _`-.     |  _      _`-.     |  _      _`-." << std::endl;
	std::cout << "'-(_)----(_)--`    '-(_)----(_)--`    '-(_)----(_)--`" << std::endl;
}

void View::printMessage(const std::string& message, const int type)
{
	if (type == ErrorTypeMessage)
	{
		Consola::setTextColor(Consola::VERMELHO_CLARO);
		std::cout << "[ERROR]";
		Consola::setTextColor(Consola::VERDE);
		std::cout << ": ";
	}

	if (type == WarningTypeMessage)
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "[WARNING]";
		Consola::setTextColor(Consola::VERDE);
		std::cout << ": ";
	}

	if (type == SuccessTypeMessage)
	{
		Consola::setTextColor(Consola::BRANCO);
		std::cout << "[SUCCESS]";
		Consola::setTextColor(Consola::VERDE);
		std::cout << ": ";
	}

	std::cout << message << std::endl;
	
}

void View::printCommandLineMessage()
{
	std::cout << "Introduza um comando: ";
}

void View::helpCommand()
{
	std::cout << "Lista de comandos do modo 1:" << std::endl;
	std::cout << "carregaP <nomeFicheiro>" << std::endl;
	std::cout << "carregaC <nomeFicheiro>" << std::endl;
	std::cout << "carregaA <nomeFicheiro>" << std::endl;
	std::cout << "cria <letraTipo> <dados do objeto>";
	std::cout << "          Letras: p - piloto; c - carro; a - autodromo" << std::endl;
	std::cout << "apaga <letraTipo> identificador" << std::endl;
	std::cout << "entranocarro <letraCarro> <nomePiloto> " << std::endl;
	std::cout << "saidocarro <letraCarro>" << std::endl;
	std::cout << "lista" << std::endl;
	std::cout << "campeonato" << std::endl;
	std::cout << "sair" << std::endl;
}

void View::printLog(Simulator& s)
{
	std::vector<std::string> log = s.getLog();

	if (log.empty())
		printMessage("Log Vazio.", WarningTypeMessage);
	else
	{
		int logSize = log.size();
		for (int i = 0; i < logSize; i++)
			std::cout << log[i] << std::endl;
	}
	
}

void View::printModelsInfoCommand(Simulator& s)
{
	Consola::setTextColor(Consola::AZUL_CLARO);
	std::cout << "\nLista de Carros" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	if(!s.getDGV()->printCars())
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "Nao existem carros." << std::endl;
		Consola::setTextColor(Consola::VERDE);
	}

	Consola::setTextColor(Consola::AZUL_CLARO);
	std::cout << "\nLista de Pilotos" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	if (!s.getDGV()->printPilots())
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "Nao existem pilotos." << std::endl;
		Consola::setTextColor(Consola::VERDE);
	}

	Consola::setTextColor(Consola::AZUL_CLARO);
	std::cout << "\nLista de Autodromos" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	if(!s.printRacetracks())
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "Nao existem autodromos." << std::endl;
		Consola::setTextColor(Consola::VERDE);
	}

	std::cout << std::endl;
}

void View::printCarsOnChampionship(Simulator& s)
{
	Championship* c = s.getChampionship();

	Consola::setTextColor(Consola::BRANCO);
	std::cout << "------Tabela classificativa:--------" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	c->printStandings();

	std::cout << std::endl;
	
	Consola::setTextColor(Consola::CYAN);

	Racetrack* r = c->getCurrentRacetrack();
	
	std::cout << "Corrida no" << c->getCurrentRaceNumber() + 1 << " no Autodromo " << r->getName() << std::endl;
	
	Consola::setTextColor(Consola::BRANCO);
	std::cout << "--------Carros na garagem-----------" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	if (!c->printCarsInGarage())
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "Garagem Vazia" << std::endl;
	}
	Consola::setTextColor(Consola::BRANCO);
	std::cout << "---------Carros na pista------------" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	if (!c->printCarsInTrack())
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "Pista Vazia" << std::endl;
		Consola::setTextColor(Consola::VERDE);
	}
}

void View::printRace(Simulator& s)
{
	Racetrack* r = s.getCurrentRace();

	int length = r->getTrackLength();
	std::vector<Car* > raceCars = r->getCarsInTrack();
	int raceSize = raceCars.size();
	int raceTime = r->getTime();
	std::string location = r->getName();

	if (raceSize == 0)
	{
		if (r != nullptr)
			r->printRaceResults();
		return;
	}

	Consola::clrscr();
	
	//Print Track Name
	Consola::gotoxy(4, 2);
	Consola::setTextColor(Consola::AZUL_CLARO);
	std::cout << "Track: ";
	Consola::setTextColor(Consola::BRANCO);
	std::cout << location << std::endl;


	//Print Time Elapsed
	Consola::gotoxy(4, 3);
	Consola::setTextColor(Consola::AZUL_CLARO);
	std::cout << "Time Elapsed: ";
	Consola::setTextColor(Consola::BRANCO);
	std::cout << Utils::getTimeAsString(raceTime) << std::endl;

	Consola::gotoxy(3, 5);
	std::cout << "-----------------------" << std::endl;
	
	for (int i = 0; i < raceSize; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				Consola::gotoxy(25, 6 + i * 2);
				Consola::setTextColor(Consola::BRANCO);
				std::cout << "Finish Line" << std::endl;
				Consola::setTextColor(Consola::VERDE);

				char tmpChar = raceCars[i]->getID();
				int  tmpPos = raceCars[i]->getPosition();

				Consola::gotoxy(4, 6 + i * 2);
				int num = (tmpPos * 20) / length + 1;

				if (i % 2 == 0)
				{
					Consola::setTextColor(Consola::AZUL_CLARO);
				}

				int checker;

				if (num > length)
					checker = length;
				else
					checker = num;

				for (int y = 0; y < checker; y++)
				{
					std::cout << tmpChar;
				}
				std::cout << std::endl;
			}

			if (j == 1)
			{
				Consola::setTextColor(Consola::BRANCO);
				Consola::gotoxy(3, 7 + i * 2);
				std::cout << "-----------------------" << std::endl;
				Consola::setTextColor(Consola::VERDE);
			}
		}
	}

	std::cout << std::endl;
	
	Sleep(50);

	Consola::setTextColor(Consola::VERDE);

}

void View::printStandings(Simulator& s)
{
	Championship* c = s.getChampionship();
	Consola::setTextColor(Consola::BRANCO);
	std::cout << "         Tabela classificativa" << std::endl;
	Consola::setTextColor(Consola::VERDE);
	c->printStandings();
}

void View::printInvalidRacetracks(int invalidRacetracks)
{
	std::string message = "Ficheiro Carregado. Numero de Autodromos Invalidos: ";
	message += std::to_string(invalidRacetracks);
	printMessage(message, WarningTypeMessage);
}
