#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class CruiseControlTest : public ::testing::Test
{
};

TEST_F(CruiseControlTest, exampleTest)
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