#include "BootsATV.hpp"

#include "GroundRace.hpp"

static constexpr int initSpeed{6};
static constexpr int initDrivingTimeBeforeRest{60};
static constexpr double initRestDuration{10};

BootsATV::BootsATV(): GroundVehicle{initSpeed, initDrivingTimeBeforeRest, initRestDuration}{}

GroundVehicle::View BootsATV::getView() const
{
	return View::BootsATV;
}

double BootsATV::getTimeRest(Race* race)
{
	if (getCountOfRest(race) == 0) return 0;
	if (getCountOfRest(race) == 1) return 10;
	return ((getCountOfRest(race) - 1) * 5) + 10;
}

double BootsATV::getResultRaceTime(Race* race)
{
	return getRaceTime(race) + getTimeRest(race);
}
