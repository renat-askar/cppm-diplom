#include "Race.hpp"

void Race::setDistance(int distance)
{
	this->distance = distance;
}

int Race::getDistance() const
{
	return distance;
}

Vehicle* Race::getVehicleAt(size_t index) const
{
	return registeredVehicles[index];
}

size_t Race::getCountRegisteredVehicles() const
{
	return countRegisteredVehicles;
}
