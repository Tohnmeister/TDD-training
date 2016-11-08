#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "LeapYear.h"

TEST(LeapYearTest, 1isNotALeapYear)
{
	EXPECT_FALSE(LeapYear::isLeapYear(1));
}

TEST(LeapYearTest, every4thYearIsALeapYear)
{
	EXPECT_TRUE(LeapYear::isLeapYear(4));
	EXPECT_TRUE(LeapYear::isLeapYear(8));
}

TEST(LeapYearTest, every100thYearIsNotALeapYear)
{
	EXPECT_FALSE(LeapYear::isLeapYear(100));
	EXPECT_FALSE(LeapYear::isLeapYear(200));
}

TEST(LeapYearTest, every400thYearIsALeapYear)
{
	EXPECT_TRUE(LeapYear::isLeapYear(400));
	EXPECT_TRUE(LeapYear::isLeapYear(800));
}