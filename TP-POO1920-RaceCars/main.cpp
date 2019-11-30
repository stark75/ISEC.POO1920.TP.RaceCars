#include "Simulator.h"
#include "UI.h"

int main(const int argc, char* argv[])
{
	/*DGV dgv;

	Car a(2, 3, 2, "Ferrari", "Enzo");
	Car b(2, 3456, 234, "Joao", "Joaquim");
	Car c(2, 3456, 230, "O Couto", "e Gay");

	a.setPosition(12);
	b.setPosition(23);
	c.setPosition(1);
	
	dgv.addCar(a);
	dgv.addCar(b);
	dgv.addCar(c);

	dgv.printCars();
	std::cout << std::endl;
	dgv.sortCarsByPosition();
	std::cout << std::endl;
	dgv.printCars();*/
	

	UI ui;
	ui.run(argc, argv);

	return 0;
}
