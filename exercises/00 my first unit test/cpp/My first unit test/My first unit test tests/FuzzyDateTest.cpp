#include "FuzzyDate.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class FuzzyDateTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}
};

TEST_F(FuzzyDateTest, testContains)
{
	EXPECT_TRUE(true);
}

class IFoo
{
public:
	virtual ~IFoo() = 0 {}

	virtual int getBar() const = 0;
};

class FooMock : public IFoo
{
public:
	MOCK_CONST_METHOD0(getBar, int());

};

TEST(MockTest, testMock)
{
	using ::testing::Return;
	using ::testing::Exactly;
	FooMock fooMock;
	ON_CALL(fooMock, getBar()).WillByDefault(Return(4));
	EXPECT_CALL(fooMock, getBar()).Times(Exactly(1));

	auto bar = fooMock.getBar();
	EXPECT_EQ(4, bar);
}