#include "Vehicle.hpp"

#include "Race.hpp"

Vehicle::Vehicle(int setSpeed): speed{setSpeed}{}

int Vehicle::getTime(Race* race) const
{
	return race->getDistance() / speed;
}
