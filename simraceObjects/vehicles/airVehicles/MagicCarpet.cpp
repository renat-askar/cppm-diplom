#include "MagicCarpet.hpp"

#include "AirRace.hpp"

static constexpr int initSpeed{10};

MagicCarpet::MagicCarpet(): AirVehicle{initSpeed}{}

AirVehicle::View MagicCarpet::getView() const
{
	return View::MagicCarpet;
}

double MagicCarpet::getDistanceFactor(Race* race) const
{
	double distanceFactor{1.0};
	if(race->getDistance() < 1000)   return 1.0;
	if(race->getDistance() < 5000)   return 1.0 - 0.03;
	if(race->getDistance() < 10000)  return 1.0 - 0.1;
	if(race->getDistance() >= 10000) return 1.0 - 0.05;
	return distanceFactor;
}

double MagicCarpet::getReducedDistance(Race* race) const
{
	return race->getDistance() * getDistanceFactor(race);
}

double MagicCarpet::getResultRaceTime(Race* race)
{
	return getReducedDistance(race) / speed;
}
