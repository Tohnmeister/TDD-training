#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IHardware.h"
#include "CruiseControl.h"

using ::testing::Return;
using ::testing::Exactly;

class HardwareMock : public IHardware
{
public:
	MOCK_METHOD1(accelerate, void(bool));
	MOCK_CONST_METHOD0(getCurrentSpeed, int());

	MOCK_CONST_METHOD0(isBreakPressed, bool());
	MOCK_CONST_METHOD0(isClutchPressed, bool());

	MOCK_CONST_METHOD0(isCruiseControlOn, bool());
	MOCK_METHOD0(disableCruiseControl, void());
	MOCK_CONST_METHOD0(getCruiseControlSpeed, int());
};

class CruiseControlTest : public ::testing::Test
{
public:
	CruiseControlTest() :
		_hardwareMock(),
		_cruiseControl(_hardwareMock)
	{
	}

	HardwareMock _hardwareMock;
	CruiseControl _cruiseControl;
	

};

TEST_F(CruiseControlTest, acceleratesIfCruiseControlIsEnabledAndSpeedBelowTargetSpeed)
{
	ON_CALL(_hardwareMock, isCruiseControlOn()).WillByDefault(Return(true));
	ON_CALL(_hardwareMock, getCruiseControlSpeed()).WillByDefault(Return(50));
	ON_CALL(_hardwareMock, getCurrentSpeed()).WillByDefault(Return(40));

	EXPECT_CALL(_hardwareMock, accelerate(true)).Times(Exactly(1));
	_cruiseControl.tick();
}

TEST_F(CruiseControlTest, stopsAcceleratingIfSpeedMatchesCruiseControlSpeed)
{
	ON_CALL(_hardwareMock, isCruiseControlOn()).WillByDefault(Return(true));
	ON_CALL(_hardwareMock, getCruiseControlSpeed()).WillByDefault(Return(50));
	ON_CALL(_hardwareMock, getCurrentSpeed()).WillByDefault(Return(50));

	EXPECT_CALL(_hardwareMock, accelerate(false)).Times(Exactly(1));
	_cruiseControl.tick();
}

TEST_F(CruiseControlTest, disablesCruiseControlIfBreakPressed)
{
	ON_CALL(_hardwareMock, isBreakPressed()).WillByDefault(Return(true));

	EXPECT_CALL(_hardwareMock, disableCruiseControl()).Times(Exactly(1));
	_cruiseControl.tick();
}

TEST_F(CruiseControlTest, disablesCruiseControlIfClutchPressed)
{
	ON_CALL(_hardwareMock, isClutchPressed()).WillByDefault(Return(true));

	EXPECT_CALL(_hardwareMock, disableCruiseControl()).Times(Exactly(1));
	_cruiseControl.tick();
}

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