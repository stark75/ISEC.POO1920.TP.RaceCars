#pragma once
#include "Pilot.h"

class CrazyPilot :
	public Pilot
{
public:
	CrazyPilot(const std::string& newName);
	CrazyPilot(const CrazyPilot& src) = default;
	CrazyPilot(const Pilot& src);

	std::string getAsString()     const override;
	std::string getTypeAsString() const override;
};

