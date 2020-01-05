#pragma once
#include "DGV.h"

class StoredDGV
{
	DGV storedDGV;
	std::string name;

public:
	StoredDGV(DGV dgvToStore, std::string newName);
	~StoredDGV() = default;

	DGV         getDGV();
	std::string getName();
	void        setDGV(DGV newDGV);
	
};

