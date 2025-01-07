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

double Broom::getResult(Race* race)
{
	return (race->getDistance() * getDistanceFactor(race)) / speed;
}
