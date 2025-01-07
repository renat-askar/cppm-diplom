#include "Broom.hpp"

#include "AirRace.hpp"

Broom::Broom(): AirVehicle{20}{}

AirVehicle::View Broom::getView() const
{
	return View::Broom;
}

double Broom::getResult(Race* race)
{
	return (race->getDistance() * (1 - 0.01 * static_cast<int>(race->getDistance() / 1000))) / 20;
}
