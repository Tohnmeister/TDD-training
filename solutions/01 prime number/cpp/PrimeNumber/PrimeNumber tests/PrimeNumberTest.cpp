#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PrimeNumber.h"

TEST(PrimeNumberTest, 1IsNotAPrimeNumber)
{
	EXPECT_FALSE(PrimeNumber::isPrimeNumber(1));
}

TEST(PrimeNumberTest, 2IsAPrimeNumber)
{
	EXPECT_TRUE(PrimeNumber::isPrimeNumber(2));
}

TEST(PrimeNumberTest, 3IsAPrimeNumber)
{
	EXPECT_TRUE(PrimeNumber::isPrimeNumber(3));
}

TEST(PrimeNumberTest, 4IsNotAPrimeNumber)
{
	EXPECT_FALSE(PrimeNumber::isPrimeNumber(4));
}

TEST(PrimeNumberTest, 15485863IsAPrimeNumber)
{
	EXPECT_TRUE(PrimeNumber::isPrimeNumber(15485863));
}