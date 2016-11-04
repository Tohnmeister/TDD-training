#include "FuzzyDate.h"

using namespace std;
using namespace date;

FuzzyDate::FuzzyDate() :
	startDate(year{1970} / 1 / 1),
	endDate(year{ 1970 } / 1 / 1)
{
}

FuzzyDate::FuzzyDate(const string& str) :
	FuzzyDate()
{
	if (str == "now")
	{
		auto today = year_month_day{ floor<days>(chrono::system_clock::now()) };
		startDate = today;
		endDate = today;
	}
}

FuzzyDate::FuzzyDate(Quarters quart, int year) :
	FuzzyDate()
{
	switch (quart)
	{
	case Quarters::Q1:
		startDate = ::year{ year } / 1 / 1;
		endDate = ::year{ year } / 3 / 31;
		break;
	case Quarters::Q2:
		startDate = ::year{ year } / 4 / 1;
		endDate = ::year{ year } / 6 / 30;
		break;
	case Quarters::Q3:
		startDate = ::year{ year } / 7 / 1;
		endDate = ::year{ year } / 9 / 30;
		break;
	case Quarters::Q4:
		startDate = ::year{ year } / 10 / 1;
		endDate = ::year{ year } / 12 / 31;
		break;
	}
}

FuzzyDate::FuzzyDate(YearType type, int year) :
	FuzzyDate()
{
	switch (type)
	{
	case YearType::START:
		startDate = ::year{ year } / 1 / 1;
		endDate = ::year{ year }/ 3 / 31;
		break;
	case YearType::HALFWAY:
		startDate = ::year{ year } / 5 / 1;
		endDate = ::year{ year } / 8 / 31;
		break;
	case YearType::END:
		startDate = ::year{ year } / 9 / 1;
		endDate = ::year{ year } / 12 / 31;
		break;
	}
}


FuzzyDate::~FuzzyDate()
{
}

const date::year_month_day & FuzzyDate::getFuzzyStart() const
{
	return startDate;
}

const date::year_month_day & FuzzyDate::getFuzzyEnd() const
{
	return endDate;
}

date::days FuzzyDate::getFuzzyRange() const
{
	return sys_days(endDate) - sys_days(startDate);
}

bool FuzzyDate::contains(const date::year_month_day & lookupDate) const
{
	return lookupDate >= startDate && lookupDate <= endDate;
}
