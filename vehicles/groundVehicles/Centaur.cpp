#include "Centaur.hpp"

#include "GroundRace.hpp"

Centaur::Centaur(): GroundVehicle{15, 8, 2}{}

GroundVehicle::View Centaur::getView() const
{
	return View::Centaur;
}

double Centaur::getTimeRest(Race* race)
{
	return getCountOfRest(race) * restDuration;
}

double Centaur::getResult(Race* race)
{
	return getTime(race) + getTimeRest(race);
}
