#include "LeapYear.h"



bool LeapYear::isLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

LeapYear::LeapYear()
{
}


LeapYear::~LeapYear()
{
}
