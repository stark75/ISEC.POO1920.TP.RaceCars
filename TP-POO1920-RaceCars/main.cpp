#include <iostream>
#include "Car.h"
#include "Simulator.h"
#include "UI.h"
#include "View.h"

int main(const int argc, char* argv[])
{
	Car a(2, 3, 1, "Ferrari", "Enzo");

	std::cout << a << std::endl;

	/*Simulator on;
	UI ui(on);
	ui.run(argc, argv);*/

	return 0;
}
