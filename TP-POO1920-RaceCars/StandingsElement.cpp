#include "StandingsElement.h"

StandingsElement::StandingsElement(Car* c): competitor(c), score(0)
{
}

Car* StandingsElement::getCompetitor() const
{
	return competitor;
}

int StandingsElement::getScore() const
{
	return score;
}

std::string StandingsElement::getAsString() const
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
	str += " | Score:";
	str += std::to_string(score);
	
	return str;
}

void StandingsElement::increaseScore(int value)
{
	score += value;
}

bool operator==(StandingsElement const& lhs, StandingsElement const& rhs)
{
	return lhs.score == rhs.score;
}

bool operator!=(StandingsElement const& lhs, StandingsElement const& rhs)
{
	return !(lhs == rhs);
}

bool StandingsElement::operator<(const StandingsElement& other) const
{
	return this->score < other.score;
}

bool StandingsElement::operator>(const StandingsElement& other) const
{
	return this->score > other.score;
}

bool StandingsElement::operator<=(const StandingsElement& other) const
{
	return this->score <= other.score;
}

bool StandingsElement::operator>=(const StandingsElement& other) const
{
	return this->score >= other.score;
}

bool operator==(StandingsElement const& lhs, Car* rhs)
{
	return lhs.getCompetitor() == rhs;
}

bool operator!=(StandingsElement const& lhs, Car* rhs)
{
	return !(lhs == rhs);
}

bool operator==(Car* lhs, StandingsElement const& rhs)
{
	return rhs == lhs;
}

bool operator!=(Car* lhs, StandingsElement const& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const StandingsElement& sE)
{
	os << sE.getAsString();
	return os;
}
