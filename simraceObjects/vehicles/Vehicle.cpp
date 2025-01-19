#include "Vehicle.hpp"

#include "Race.hpp"

Vehicle::Vehicle(int initSpeed): speed{initSpeed}{}

int Vehicle::getRaceTime(Race* race) const
{
	return race->getDistance() / speed;
}
