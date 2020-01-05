#pragma once
#include "Pilot.h"
class SurprisePilot :
	public Pilot
{
public:
	SurprisePilot(const std::string& newName);
	SurprisePilot(const SurprisePilot& src) = default;
	SurprisePilot(const Pilot& src);

	std::string getAsString() const override;
	std::string getTypeAsString() const override;
};

