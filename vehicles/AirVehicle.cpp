#include "AirVehicle.hpp"

AirVehicle::AirVehicle(int initSpeed): Vehicle{initSpeed}{}

Vehicle::Type AirVehicle::getType() const
{
	return Air;
}
