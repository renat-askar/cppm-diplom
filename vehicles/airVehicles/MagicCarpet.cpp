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
	if(race->getDistance() < 1000)   return 1;
	if(race->getDistance() < 5000)   return 1 - 0.03;
	if(race->getDistance() < 10000)  return 1 - 0.1;
	if(race->getDistance() >= 10000) return 1 - 0.05;
}

double MagicCarpet::getResult(Race* race)
{
	return (race->getDistance() * getDistanceFactor(race)) / speed;
}
