#include "StoredDGV.h"

StoredDGV::StoredDGV(DGV dgvToStore, std::string newName): storedDGV(dgvToStore), name(newName){}

DGV StoredDGV::getDGV()
{
	return storedDGV;
}

std::string StoredDGV::getName()
{
	return name;
}

void StoredDGV::setDGV(DGV newDGV)
{
	storedDGV = newDGV;
}
