#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringCalculator.h"

class StringCalculatorTest : public ::testing::Test
{
};

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