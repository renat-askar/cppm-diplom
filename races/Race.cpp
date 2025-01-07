#include "Race.hpp"

void Race::setDistance(int distance)
{
	this->distance = distance;
}

int Race::getDistance() const
{
	return distance;
}

Vehicle* Race::getVehicleAt(size_t vehilce) const
{
	return registeredVehicles[vehilce];
}

size_t Race::getCountRegisteredVehicles() const
{
	return countRegisteredVehicles;
}
