#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringCalculator.h"

using namespace std;

class StringCalculatorTest : public ::testing::Test
{
};

TEST_F(StringCalculatorTest, anEmptStringReturnsZero)
{
	EXPECT_EQ(0, StringCalculator::calculate(""));
}

TEST_F(StringCalculatorTest, aSingleNumberReturnsTheValue)
{
	EXPECT_EQ(1, StringCalculator::calculate("1"));
}

TEST_F(StringCalculatorTest, twoNumbersCommaDelimitedReturnsTheSum)
{
	EXPECT_EQ(3, StringCalculator::calculate("1,2"));
}

TEST_F(StringCalculatorTest, twoNumbersNewlineDelimitedReturnsTheSum)
{
	EXPECT_EQ(3, StringCalculator::calculate("1\n2"));
}

TEST_F(StringCalculatorTest, threeNumbersDelimitedEitherWayReturnsTheSum)
{
	EXPECT_EQ(6, StringCalculator::calculate("1,2\n3"));
}

TEST_F(StringCalculatorTest, negativeNumbersThrowAnException)
{
	EXPECT_THROW(StringCalculator::calculate("-1"), exception);
}

TEST_F(StringCalculatorTest, numbersGreaterThan1000AreIgnored)
{
	EXPECT_EQ(1003, StringCalculator::calculate("1000,1001\n3"));
}

TEST_F(StringCalculatorTest, aSingleCharDelimiterCanBeDefinedOnTheFirstLine)
{
	EXPECT_EQ(3, StringCalculator::calculate("//#1#2"));
}

TEST_F(StringCalculatorTest, aMultiCharDelimiterCanBeDefinedOnTheFirstLine)
{
	EXPECT_EQ(3, StringCalculator::calculate("//[###]1###2"));
}

TEST_F(StringCalculatorTest, manySingleOrMultiCharDelimitersCanBeDefined)
{
	EXPECT_EQ(6, StringCalculator::calculate("//[###][##]1###2##3"));
}

//- Many single or multi - char delimiters can be defined, e.g. "//[###][$$]" for '###' and '$$' as the delimiter

void throwException()
{
	throw std::exception();
}

TEST_F(StringCalculatorTest, exampleTest)
{
	EXPECT_EQ(1, 1); // Expect that the 2nd value matches the 1st (expected) value.
	EXPECT_NE(1, 2); // Expect that two values are not equal.
	EXPECT_TRUE(1 == 1); // Expect that some condition is true.
	EXPECT_FALSE(1 == 2); // Expect that some condition is false.
	EXPECT_THROW(throwException(), std::exception); // Expect that a statement throws an exception.

	// All of these methods also have an ASSERT variant, which stops the test runner if the condition is not satisfied.
}