#include "MagicCarpet.hpp"

#include "AirRace.hpp"

MagicCarpet::MagicCarpet(): AirVehicle{10}{}

AirVehicle::View MagicCarpet::getView() const
{
	return View::MagicCarpet;
}

double MagicCarpet::getResult(Race* race)
{
	if(race->getDistance() < 1000)   return (race->getDistance() * (1 - 0.0)) / 10;
	if(race->getDistance() < 5000)   return (race->getDistance() * (1 - 0.03)) / 10;
	if(race->getDistance() < 10000)  return (race->getDistance() * (1 - 0.1)) / 10;
	if(race->getDistance() >= 10000) return (race->getDistance() * (1 - 0.05)) / 10;
}
