#include "DGV.h"
#include "View.h"

DGV::DGV()
{
	
}

DGV::~DGV()
{
	//todo libertar memoria dos vetores
}

bool DGV::addCar(const Car newCar)
{
	carNames.push_back(new Car(newCar));
	Car* tmpCar = carNames.back();

	
	if(tmpCar==newCar)
	{
		View::printMessage("Car copied correctly", View::SuccessTypeMessage);
		return true;
	}
	return false;
}


bool DGV::addPilot(const Pilot newPilot)
{
	return false;
}