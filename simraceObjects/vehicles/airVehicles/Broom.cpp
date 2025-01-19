#include "Broom.hpp"

#include "AirRace.hpp"

static constexpr int initSpeed{20};

Broom::Broom(): AirVehicle{initSpeed}{}

AirVehicle::View Broom::getView() const
{
	return View::Broom;
}

double Broom::getDistanceFactor(Race* race) const
{
	return 1 - (0.01 * static_cast<int>(race->getDistance() / 1000));
}

double Broom::getReducedDistance(Race* race) const
{
	return race->getDistance() * getDistanceFactor(race);
}

double Broom::getResultRaceTime(Race* race)
{
	return getReducedDistance(race) / speed;
}
