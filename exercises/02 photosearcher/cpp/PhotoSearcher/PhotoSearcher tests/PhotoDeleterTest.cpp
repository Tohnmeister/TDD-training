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

class PhotoMock : public IPhoto
{
public:
	MOCK_CONST_METHOD0(getId, int());
	MOCK_CONST_METHOD0(getDate, const year_month_day&());
	MOCK_CONST_METHOD0(getColor, const Color&());
	MOCK_CONST_METHOD0(getContentType, ContentType());
};

class PhotoDeleterTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		
	}

private:

};

void initializePhotoMock(const PhotoMock& mock, int id, const year_month_day& date, const Color& color, ContentType contentType)
{
	ON_CALL(mock, getId()).WillByDefault(Return(id));
	ON_CALL(mock, getDate()).WillByDefault(ReturnRef(date));
	ON_CALL(mock, getColor()).WillByDefault(ReturnRef(color));
	ON_CALL(mock, getContentType()).WillByDefault(Return(contentType));
}

TEST_F(PhotoDeleterTest, deletePhotosShouldDeletePhotosMatchingFuzzyDate)
{
	NiceMock<PhotoRepositoryMock> photoRepository;
	PhotoDeleter photoDeleter(&photoRepository);
	FuzzyDate fuzzyDate(Quarters::Q1, 2017);
	Color black(0, 0, 0);
	Color white(255, 255, 255);
	NiceMock<PhotoMock> photo1;
	initializePhotoMock(photo1, 1, year{ 2017 } / 4 / 1, white, ContentType::CARS);
	NiceMock<PhotoMock> photo2;
	initializePhotoMock(photo2, 2, year{ 2016 } / 3 / 1, white, ContentType::CARS);
	NiceMock<PhotoMock> photo3;
	initializePhotoMock(photo3, 3, year{ 2017 } / 3 / 1, white, ContentType::CARS);

	vector<IPhoto*> allPhotos{ &photo1, &photo2, &photo3 };
	ON_CALL(photoRepository, getPhotos()).WillByDefault(Return(allPhotos));

	vector<int> expectedDeletedIds{ 3 };
	EXPECT_CALL(photoRepository, deletePhotos(expectedDeletedIds)).Times(Exactly(1));

	photoDeleter.deletePhotos(fuzzyDate);
}

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