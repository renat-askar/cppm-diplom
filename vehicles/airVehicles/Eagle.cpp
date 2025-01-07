#include "Eagle.hpp"

#include "AirRace.hpp"

Eagle::Eagle(): AirVehicle{8}{}

AirVehicle::View Eagle::getView() const
{
	return View::Eagle;
}

double Eagle::getResult(Race* race)
{
	return (race->getDistance() * (1 - 0.06)) / 8;
}
