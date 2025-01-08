#include "Camel.hpp"

#include "GroundRace.hpp"

static constexpr int initSpeed{10};
static constexpr int initDrivingTimeBeforeRest{30};
static constexpr double initRestDuration{5};

Camel::Camel(): GroundVehicle{initSpeed, initDrivingTimeBeforeRest, initRestDuration}{}

GroundVehicle::View Camel::getView() const
{
	return View::Camel;
}

double Camel::getTimeRest(Race* race)
{
	if (getCountOfRest(race) == 0) return 0;
	if (getCountOfRest(race) == 1) return 5;
	return ((getCountOfRest(race) - 1) * 8) + 5;
}

double Camel::getResultRaceTime(Race* race)
{
	return getRaceTime(race) + getTimeRest(race);
}
