#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DataAdder.h"

class DataAdderTest : public ::testing::Test
{
};

TEST_F(DataAdderTest, testData)
{
	DataAdder myDataAdder;
	myDataAdder.doSomeAdding();
}