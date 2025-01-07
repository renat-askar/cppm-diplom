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

double Eagle::getResult(Race* race)
{
	return (race->getDistance() * getDistanceFactor(race)) / speed;
}
