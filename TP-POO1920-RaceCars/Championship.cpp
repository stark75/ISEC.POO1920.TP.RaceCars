#include "Championship.h"
#include "View.h"
#include <algorithm>

Championship::Championship(Racetrack* location, std::vector<Car*> newParticipants) :currentRace(0)
{
	location->resetRacetrack();
	
	int vectorSize = newParticipants.size();
	
	for (int i = 0; i < vectorSize; i++)
	{
		standings.emplace_back(newParticipants[i]);
		location->addCarToGarage(newParticipants[i]);
	}

	raceLocations.push_back(location);
	
}

Championship::Championship(std::vector<Racetrack*> locations, std::vector<Car*> newParticipants)
	:currentRace(0)
{
	int lVectorSize = locations.size();

	for(int i=0; i < lVectorSize; i++)
	{
		locations[i]->resetRacetrack();
		raceLocations.push_back(locations[i]);
	}

	int pVectorSize = newParticipants.size();

	for (int i = 0; i < pVectorSize; i++)
	{
		standings.emplace_back(newParticipants[i]);
		raceLocations[0]->addCarToGarage(newParticipants[i]);
	}

}

Championship::~Championship()
{
	int vectorSize = raceLocations.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			raceLocations[i]->resetRacetrack();
		}
	}
}

bool Championship::areCarsInTrack() const
{
	return raceLocations[currentRace]->checkCarsInTrack();
}

int Championship::getCurrentRaceNumber() const
{
	return currentRace;
}

Racetrack* Championship::getCurrentRacetrack() const
{
	return raceLocations[currentRace];
}

bool Championship::passOneSecond()
{
	return raceLocations[currentRace]->carsMovement();
}

bool Championship::checkEndOfRace()
{
	return raceLocations[currentRace]->checkEndOfRace();
}

void Championship::chargeAllCars()
{
	raceLocations[currentRace]->chargeAllCars();
}

bool Championship::nextRace()
{	
	int maxRaces = raceLocations.size();

	std::vector<Car*> tmpGarage = raceLocations[currentRace]->getCarsInGarage();

	raceLocations[currentRace]->resetRacetrack();

	
	if (currentRace < (maxRaces - 1))
	{		
		++currentRace;

		raceLocations[currentRace]->copyGarage(tmpGarage);
		
		return true;
	}
	
	return false;
}

bool Championship::startRace()
{
	if(!areCarsInTrack())
	{
		raceLocations[currentRace]->moveCarsToTrack();
		chargeAllCars();
		return true;
	}
	return false;
}

void Championship::updateStandings()
{
	raceLocations[currentRace]->sortRaceResults();
	std::vector<RaceResults> tmpRR = raceLocations[currentRace]->getRaceResults();

	if(tmpRR.empty()) return;

	int rrVectorSize = tmpRR.size();

	if(rrVectorSize>0)
	{
		std::vector<RaceResults> firstPlace;
		std::vector<RaceResults> secondPlace;
		std::vector<RaceResults> thirdPlace;
		
		int place = 1;
		
		for (int i = 0; i < rrVectorSize; i++)
		{
			if (i > 0)
			{
				if (tmpRR[i] > tmpRR[i - 1])
					place++;
				
				if (place > 3)
					break;
			}
			
			if (place == 1)
				firstPlace.push_back(tmpRR[i]);
			
			if (place == 2)
				secondPlace.push_back(tmpRR[i]);
			
			if (place == 3)
				thirdPlace.push_back(tmpRR[i]);
		}

		bool pointsTo2ndPlace = true;
		bool pointsTo3rdPlace = true;

		int fstP = firstPlace.size();
		int sVSize = standings.size();
		
		if(fstP == 1)
		{
			for(int i = 0; i < sVSize; i++)
			{
				if(standings[i]==firstPlace[0].getCompetitor())
				{
					standings[i].increaseScore(10);
					break;
				}
			}
		}

		if(fstP == 2)
		{
			pointsTo3rdPlace = false;

			for(int y = 0; y < fstP; y++)
			{	
				for (int i = 0; i < sVSize; i++)
				{
					if (standings[i] == firstPlace[y].getCompetitor())
					{
						standings[i].increaseScore(5);
						break;
					}
				}
			}
		}

		if(fstP > 2)
		{
			pointsTo2ndPlace = false;
			pointsTo3rdPlace = false;

			for (int y = 0; y < fstP; y++)
			{
				for (int i = 0; i < sVSize; i++)
				{
					if (standings[i] == firstPlace[y].getCompetitor())
					{
						standings[i].increaseScore(2);
						break;
					}
				}
			}
		}

		if(pointsTo2ndPlace)
		{
			int sndP = secondPlace.size();
			if(sndP == 1)
			{
				for (int i = 0; i < sVSize; i++)
				{
					if (standings[i] == secondPlace[0].getCompetitor())
					{
						if (pointsTo3rdPlace)
							standings[i].increaseScore(5);
						else
							standings[i].increaseScore(2);
						break;
					}
				}
			}

			if(sndP > 1)
			{
				pointsTo3rdPlace = false;

				for (int y = 0; y < sndP; y++)
				{
					for (int i = 0; i < sVSize; i++)
					{
						if (standings[i] == secondPlace[y].getCompetitor())
						{
							if (fstP == 1)
								standings[i].increaseScore(2);
							else
								standings[i].increaseScore(1);
							break;
						}
					}
				}
				
			}
		}

		if(pointsTo3rdPlace)
		{
			int trdP = thirdPlace.size();

			if(trdP == 1)
			{
				for (int i = 0; i < sVSize; i++)
				{
					if (standings[i] == thirdPlace[0].getCompetitor())
					{
						standings[i].increaseScore(2);
						break;
					}
				}
			}

			if(trdP > 1)
			{
				for (int y = 0; y < trdP; y++)
				{
					for (int i = 0; i < sVSize; i++)
					{
						if (standings[i] == thirdPlace[y].getCompetitor())
						{
							standings[i].increaseScore(1);
							break;
						}
					}
				}
			}
		}
		
	}
	
}

bool Championship::printCarsInGarage()
{
	return raceLocations[currentRace]->printCarsInGarage();
}

bool Championship::printCarsInTrack()
{
	return raceLocations[currentRace]->printCarsInTrack();
}

void Championship::printStandings()
{
	sortStandings();
	int vectorSize = standings.size();

	if (vectorSize > 0)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			std::cout << i + 1 << "o classificado: " << standings[i] << std::endl;
		}
	}
}

void Championship::sortCarsByPosition()
{
	raceLocations[currentRace]->sortCarsByPosition();
}

bool Championship::sortFunc(StandingsElement& lhs, StandingsElement& rhs)
{
	return lhs.getScore() > rhs.getScore();
}

void Championship::sortStandings()
{
	std::vector<StandingsElement> vectorCopy = standings;

	std::sort(vectorCopy.begin(), vectorCopy.end(), sortFunc);

	standings = vectorCopy;
}
