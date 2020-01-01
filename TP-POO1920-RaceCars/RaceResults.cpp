#include "RaceResults.h"
#include "Utils.h"

RaceResults::RaceResults(Car* c, int fT): competitor(c), finishTime(fT)
{
}

Car* RaceResults::getCompetitor() const
{
	return competitor;
}

int RaceResults::getFinishTime() const
{
	return finishTime;
}

std::string RaceResults::getAsString() const
{
	if (competitor == nullptr)
		return "No car in this Element.";

	Pilot* tmpPilot = competitor->getDriver();

	std::string str;

	if (tmpPilot != nullptr)
	{
		str += tmpPilot->getName();
		str += " | ";
	}

	str += competitor->getBrand();
	str += " ";
	str += competitor->getModel();
	str += " | Time:";
	str += Utils::getTimeAsString(finishTime);

	return str;
}

bool operator==(RaceResults const& lhs, RaceResults const& rhs)
{
	return lhs.finishTime == rhs.finishTime;
}

bool operator!=(RaceResults const& lhs, RaceResults const& rhs)
{
	return !(lhs == rhs);
}

bool RaceResults::operator<(const RaceResults& other) const
{
	return this->finishTime < other.finishTime;
}

bool RaceResults::operator>(const RaceResults& other) const
{
	return this->finishTime > other.finishTime;
}

bool RaceResults::operator<=(const RaceResults& other) const
{
	return this->finishTime <= other.finishTime;
}

bool RaceResults::operator>=(const RaceResults& other) const
{
	return this->finishTime >= other.finishTime;
}

bool operator==(RaceResults const& lhs, Car* rhs)
{
	return lhs.getCompetitor() == rhs;
}

bool operator!=(RaceResults const& lhs, Car* rhs)
{
	return !(lhs == rhs);
}

bool operator==(Car* lhs, RaceResults const& rhs)
{
	return rhs == lhs;
}

bool operator!=(Car* lhs, RaceResults const& rhs)
{
	return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os, const RaceResults& sE)
{
	os << sE.getAsString();
	return os;
}
