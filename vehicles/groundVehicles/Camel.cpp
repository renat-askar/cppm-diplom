#include "Camel.hpp"

#include "GroundRace.hpp"

Camel::Camel(): GroundVehicle{10, 30, 5}{}

GroundVehicle::View Camel::getView() const
{
	return View::Camel;
}

double Camel::getTimeRest(Race* race)
{
	if (getCountOfRest(race) == 0) return 0;
	if (getCountOfRest(race) == 1) return 5;
	return ((getCountOfRest(race) - 1) * 8) + 5;
}

double Camel::getResult(Race* race)
{
	return getTime(race) + getTimeRest(race);
}