#include "Vehicle.hpp"

#include "Race.hpp"

Vehicle::Vehicle(int initSpeed): speed{initSpeed}{}

int Vehicle::getTime(Race* race) const
{
	return race->getDistance() / speed;
}
