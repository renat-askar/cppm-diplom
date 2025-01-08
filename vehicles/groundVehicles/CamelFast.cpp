#include "CamelFast.hpp"

static constexpr int initSpeed{40};
static constexpr int initDrivingTimeBeforeRest{10};
static constexpr double initRestDuration{5};

CamelFast::CamelFast(): GroundVehicle{initSpeed, initDrivingTimeBeforeRest, initRestDuration}{}

GroundVehicle::View CamelFast::getView() const
{
	return View::CamelFast;
}

double CamelFast::getTimeRest(Race* race)
{
	if (getCountOfRest(race) == 0) return 0;
	if (getCountOfRest(race) == 1) return 5;
	if (getCountOfRest(race) == 2) return 5 + 6.5;
	return ((getCountOfRest(race) - 2) * 8) + 5 + 6.5;
}

double CamelFast::getResultRaceTime(Race* race)
{
	return getRaceTime(race) + getTimeRest(race);
}
