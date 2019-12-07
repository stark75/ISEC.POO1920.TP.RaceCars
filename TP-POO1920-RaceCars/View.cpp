#include "View.h"
#include <iostream>
#include "Consola/Consola.h"

void View::printTitle()
{
	Consola::setTextColor(Consola::VERDE);
	std::cout << "________                  _________" << std::endl;
	std::cout << "___  __ \\_____ _____________  ____/_____ _______________" << std::endl;
	std::cout << "__  /_/ /  __ `/  ___/  _ \\  /    _  __ `/_  ___/_  ___/" << std::endl;
	std::cout << "_  _, _// /_/ // /__ /  __/ /___  / /_/ /_  /   _(__  )" << std::endl;
	std::cout << "/_/ |_| \\__,_/ \\___/ \\___/\\____/  \\__,_/ /_/    /____/\n" << std::endl;
	
	std::cout << " _.-.___\\__         _.-.___\\__         _.-.___\\__" << std::endl;
	std::cout << "|  _      _`-.     |  _      _`-.     |  _      _`-." << std::endl;
	std::cout << "'-(_)----(_)--`    '-(_)----(_)--`    '-(_)----(_)--`" << std::endl;
	
	
}

void View::printMessage(std::string message, int type)
{
	if (type == ErrorTypeMessage)
	{
		Consola::setTextColor(Consola::VERMELHO_CLARO);
		std::cout << "[ERROR]: ";
		Consola::setTextColor(Consola::VERDE);
	}

	if (type == WarningTypeMessage)
	{
		Consola::setTextColor(Consola::AMARELO);
		std::cout << "[WARNING]: ";
		Consola::setTextColor(Consola::VERDE);
	}

	if (type == SuccessTypeMessage)
	{
		Consola::setTextColor(Consola::VERDE_CLARO);
		std::cout << "[SUCCESS]: ";
		Consola::setTextColor(Consola::VERDE);
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

void View::printModelsInfoCommand(Simulator& s)
{
	s.getDGV()->printCars();
	s.getDGV()->printPilots();
	s.printRacetracks();
}

void View::printRace(Racetrack* r)
{
	Consola::clrscr();
	int length = r->getTrackLength();
	std::vector<Car* > raceCars = r->getCarsInTrack();
	int raceSize = raceCars.size();

	if (raceSize == 0)
		return;

	
	for (int i=0; i<raceSize;i++)
	{
		Consola::gotoxy(25, 3 + i);
		std::cout << "Finish Line" << std::endl;
		Consola::gotoxy(4, 3+i);
		char tmpChar = raceCars[i]->getID();
		int  tmpPos = raceCars[i]->getPosition();

		int num = (tmpPos *20) / length + 1;

		if (i % 2 == 0)
		{
			Consola::setTextColor(Consola::AZUL_CLARO);
		}

		int checker;

		if (num > length)
			checker = length;
		else
			checker = num;
		
		for(int y = 0; y < checker; y++)
		{
			std::cout << tmpChar;
		}
		std::cout << std::endl;

			
		
		Consola::setTextColor(Consola::VERDE);
		
	}
	Sleep(500);
}
