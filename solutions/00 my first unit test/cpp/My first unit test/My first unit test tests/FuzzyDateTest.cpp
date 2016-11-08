#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FuzzyDate.h"
#include "MyDateMatcher.h"
#include "date.h"

using namespace std;
using namespace date;

class FuzzyDateTest : public ::testing::Test
{
};

TEST_F(FuzzyDateTest, uses1970AsDefaultDate)
{
	// given

	// when
	FuzzyDate fuzzyDate;

	// then
	EXPECT_EQ(year{ 1970 } / 1 / 1, fuzzyDate.getFuzzyStart());
	EXPECT_EQ(year{ 1970 } / 1 / 1, fuzzyDate.getFuzzyEnd());
}

TEST_F(FuzzyDateTest, uses1970AsDefaultDateIfNotNowProvided)
{
	// given

	// when
	FuzzyDate fuzzyDate("somerandomotherstring");

	// then
	EXPECT_EQ(year{ 1970 } / 1 / 1, fuzzyDate.getFuzzyStart());
	EXPECT_EQ(year{ 1970 } / 1 / 1, fuzzyDate.getFuzzyEnd());
}

TEST_F(FuzzyDateTest, usesNowAsDateWhenNowProvidedAsString)
{
	// given
	
	// when
	FuzzyDate fuzzyDate("now");

	// then
	auto now = year_month_day{ floor<days>(chrono::system_clock::now()) };
	EXPECT_EQ(now, fuzzyDate.getFuzzyStart()) << "If there is only one day difference, it might be because the test was run around midnight.";
	EXPECT_EQ(now, fuzzyDate.getFuzzyEnd()) << "If there is only one day difference, it might be because the test was run around midnight.";
}

TEST_F(FuzzyDateTest, canBeConstructedForASpecificQuarter)
{
	// given

	// when
	FuzzyDate fuzzyDate(Quarters::Q2, 2017);

	// then
	EXPECT_EQ(year{ 2017 } / 4 / 1, fuzzyDate.getFuzzyStart());
	EXPECT_EQ(year{ 2017 } / 6 / 30, fuzzyDate.getFuzzyEnd());
}

TEST_F(FuzzyDateTest, canBeConstructedForAYearType)
{
	// given

	// when
	FuzzyDate mid1999(YearType::HALFWAY, 1999);
	FuzzyDate beginning2016(YearType::START, 2016);
	FuzzyDate end1981(YearType::END, 1981);

	// then
	EXPECT_EQ(year{ 1999 } / 5 / 1, mid1999.getFuzzyStart());
	EXPECT_EQ(year{ 1999 } / 8 / 31, mid1999.getFuzzyEnd());

	EXPECT_EQ(year{ 2016 } / 1 / 1, beginning2016.getFuzzyStart());
	EXPECT_EQ(year{ 2016 } / 4 / 30, beginning2016.getFuzzyEnd());

	EXPECT_EQ(year{ 1981 } / 9 / 1, end1981.getFuzzyStart());
	EXPECT_EQ(year{ 1981 } / 12 / 31, end1981.getFuzzyEnd());
}

TEST_F(FuzzyDateTest, rangeTakesLeapYearIntoAccount)
{
	// given

	// when
	FuzzyDate leapYearDate(Quarters::Q1, 2004);
	FuzzyDate nonLeapYearDate(Quarters::Q1, 2100);

	// then
	EXPECT_EQ(days{ 90 }, leapYearDate.getFuzzyRange());
	EXPECT_EQ(days{ 89 }, nonLeapYearDate.getFuzzyRange());
}

TEST_F(FuzzyDateTest, containsDates)
{
	// given

	// when
	FuzzyDate fuzzyDate(Quarters::Q2, 2007);

	// then
	EXPECT_FALSE(fuzzyDate.contains(year{ 2007 } / 3 / 31));
	EXPECT_TRUE(fuzzyDate.contains(year{ 2007 } / 4 / 1));
	EXPECT_TRUE(fuzzyDate.contains(year{ 2007 } / 4 / 2));

	EXPECT_TRUE(fuzzyDate.contains(year{ 2007 } / 6 / 29));
	EXPECT_TRUE(fuzzyDate.contains(year{ 2007 } / 6 / 30));
	EXPECT_FALSE(fuzzyDate.contains(year{ 2007 } / 7 / 1));
}

TEST_F(FuzzyDateTest, exampleTest)
{
	EXPECT_EQ(1, 1); // Expect that the 2nd value matches the 1st (expected) value.
	ASSERT_EQ(1, 1); // Same as expect, but it stops the test run if not equal.

	EXPECT_NE(1, 2); // Expect that two values are not equal.
	ASSERT_NE(1, 2); // Same, but stops the test run if equal.

	EXPECT_TRUE(1 == 1); // Expect that some condition is true.
	ASSERT_TRUE(1 == 1); // Same, but stops the test run if condition is not met.

	EXPECT_FALSE(1 == 2); // Expect that some condition is false.
	ASSERT_FALSE(1 == 2); // Same, but stops the test run if condition is met.
}