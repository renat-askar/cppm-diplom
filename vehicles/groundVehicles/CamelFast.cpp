#include "CamelFast.hpp"

CamelFast::CamelFast(): GroundVehicle{40, 10, 5}{}

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

double CamelFast::getResult(Race* race)
{
	return getTime(race) + getTimeRest(race);
}
