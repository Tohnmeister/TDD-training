#include "MyDateMatcher.h"

#include <algorithm>
#include <iterator>
#include "FuzzyDate.h"

using namespace std;
using namespace date;

MyDateMatcher::MyDateMatcher(const vector<year_month_day>& dates) :
	_myDates(dates)
{
}

MyDateMatcher::~MyDateMatcher()
{
}

vector<year_month_day> MyDateMatcher::FindMatchingDates(const FuzzyDate& fuzzyDate) const
{
	vector<year_month_day> matchingDates;

	copy_if(_myDates.begin(), _myDates.end(), back_inserter(matchingDates), [fuzzyDate](const year_month_day& date) {return fuzzyDate.contains(date);});

	return matchingDates;
}
