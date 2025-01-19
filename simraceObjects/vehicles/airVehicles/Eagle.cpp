#include "Eagle.hpp"

#include "AirRace.hpp"

static constexpr int initSpeed{8};

Eagle::Eagle(): AirVehicle{initSpeed}{}

AirVehicle::View Eagle::getView() const
{
	return View::Eagle;
}

double Eagle::getDistanceFactor(Race* race) const
{
	return 1 - 0.06;
}

double Eagle::getReducedDistance(Race* race) const
{
	return race->getDistance() * getDistanceFactor(race);
}

double Eagle::getResultRaceTime(Race* race)
{
	return getReducedDistance(race) / speed;
}
