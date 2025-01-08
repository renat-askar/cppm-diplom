#include "Centaur.hpp"

#include "GroundRace.hpp"

static constexpr int initSpeed{15};
static constexpr int initDrivingTimeBeforeRest{8};
static constexpr double initRestDuration{2};

Centaur::Centaur(): GroundVehicle{initSpeed, initDrivingTimeBeforeRest, initRestDuration}{}

GroundVehicle::View Centaur::getView() const
{
	return View::Centaur;
}

double Centaur::getTimeRest(Race* race)
{
	return getCountOfRest(race) * restDuration;
}

double Centaur::getResultRaceTime(Race* race)
{
	return getRaceTime(race) + getTimeRest(race);
}
