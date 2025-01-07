#include "GroundVehicle.hpp"

#include "Race.hpp"

#include <cmath>

GroundVehicle::GroundVehicle(int setSpeed, int setDrivingTimeBeforeRest, double setRestDuration):
	Vehicle{setSpeed}, drivingTimeBeforeRest{setDrivingTimeBeforeRest}, restDuration{setRestDuration}{}

Vehicle::Type GroundVehicle::getType() const
{
	return Ground;
}

void GroundVehicle::setRestDuration(double restDuration)
{
	this->restDuration = restDuration;
}

double GroundVehicle::getTime(Race* race) const
{
	return static_cast<double>(race->getDistance()) / speed;
}

int GroundVehicle::getCountOfRest(Race* race) const
{
	if(std::trunc(getTime(race)) == getTime(race) && static_cast<int>(getTime(race)) % drivingTimeBeforeRest == 0)
		return getTime(race) / drivingTimeBeforeRest - 1;
	return getTime(race) / drivingTimeBeforeRest;
}
