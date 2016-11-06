#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IPhotoRepository.h"
#include "IPhoto.h"
#include "PhotoDeleter.h"
#include "FuzzyDate.h"

using ::testing::_;
using ::testing::Exactly;
using ::testing::ReturnRef;
using ::testing::Return;
using ::testing::NiceMock;
using namespace date;
using namespace std;

// How to create a mock...
class PhotoRepositoryMock : public IPhotoRepository
{
public:
	MOCK_CONST_METHOD0(getPhotos, std::vector<IPhoto*>());
	MOCK_METHOD1(deletePhotos, void(const std::vector<int>&));
};

class PhotoDeleterTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		
	}

private:

};

TEST_F(PhotoDeleterTest, exampleTest)
{
	EXPECT_EQ(1, 1); // Expect that the 2nd value matches the 1st (expected) value.
	ASSERT_EQ(1, 1); // Same as expect, but it stops the test run if not equal.

	EXPECT_NE(1, 2); // Expect that two values are not equal.
	ASSERT_NE(1, 2); // Same, but stops the test run if equal.

	EXPECT_TRUE(1 == 1); // Expect that some condition is true.
	ASSERT_TRUE(1 == 1); // Same, but stops the test run if condition is not met.

	EXPECT_FALSE(1 == 2); // Expect that some condition is false.
	ASSERT_FALSE(1 == 2); // Same, but stops the test run if condition is met.

	PhotoRepositoryMock photoRepository;

	EXPECT_CALL((photoRepository), deletePhotos(_)).Times(Exactly(1));

	IPhotoRepository* pr = &photoRepository;
	pr->deletePhotos(std::vector<int>());
}