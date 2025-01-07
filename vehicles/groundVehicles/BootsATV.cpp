#include "BootsATV.hpp"

#include "GroundRace.hpp"

BootsATV::BootsATV(): GroundVehicle{6, 60, 10}{}

GroundVehicle::View BootsATV::getView() const
{
	return View::BootsATV;
}

double BootsATV::getTimeRest(Race* race)
{
	if (getCountOfRest(race) == 0) return 0;
	if (getCountOfRest(race) == 1) return 10;
	return ((getCountOfRest(race) - 1) * 5) + 10;
}

double BootsATV::getResult(Race* race)
{
	return getTime(race) + getTimeRest(race);
}
