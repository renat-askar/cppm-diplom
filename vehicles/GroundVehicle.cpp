#include "GroundVehicle.hpp"

#include "Race.hpp"

#include <cmath>

GroundVehicle::GroundVehicle(int initSpeed, int initDrivingTimeBeforeRest, double initRestDuration):
	Vehicle{initSpeed}, drivingTimeBeforeRest{initDrivingTimeBeforeRest}, restDuration{initRestDuration}{}

Vehicle::Type GroundVehicle::getType() const
{
	return Ground;
}

void GroundVehicle::setRestDuration(double restDuration)
{
	this->restDuration = restDuration;
}

double GroundVehicle::getRaceTime(Race* race) const
{
	return static_cast<double>(race->getDistance()) / speed;
}

int GroundVehicle::getCountOfRest(Race* race) const
{
	if(std::trunc(getRaceTime(race)) == getRaceTime(race) && static_cast<int>(getRaceTime(race)) % drivingTimeBeforeRest == 0)
		return getRaceTime(race) / drivingTimeBeforeRest - 1;
	return getRaceTime(race) / drivingTimeBeforeRest;
}
