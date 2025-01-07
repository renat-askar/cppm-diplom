#include "AirVehicle.hpp"

AirVehicle::AirVehicle(int setSpeed): Vehicle{setSpeed}{}

Vehicle::Type AirVehicle::getType() const
{
	return Air;
}
