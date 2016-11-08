#ifndef MYDATEMATCHER_H
#define MYDATEMATCHER_H

#include <vector>
#include "date.h"

class FuzzyDate;

class MyDateMatcher
{
public:
	MyDateMatcher(const std::vector<date::year_month_day>& dates);
	virtual ~MyDateMatcher();

	std::vector<date::year_month_day> FindMatchingDates(const FuzzyDate& fuzzyDate) const;

private:
	std::vector<date::year_month_day> _myDates;

};

#endif