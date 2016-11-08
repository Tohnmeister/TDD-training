#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DataBlob.h"

class DataBlobTest : public ::testing::Test
{
};

TEST_F(DataBlobTest, testDataInitiallyEmpty)
{
	DataBlob& blob = DataBlob::getBlob();
	EXPECT_TRUE(blob.isEmpty());
}