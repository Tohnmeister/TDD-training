#include "PhotoDeleter.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include "FuzzyDate.h"
#include "Color.h"
#include "IPhotoRepository.h"
#include "IPhoto.h"

using namespace std;

PhotoDeleter::PhotoDeleter(IPhotoRepository* photoRepository) :
	_photoRepository(photoRepository)
{
}

PhotoDeleter::~PhotoDeleter()
{
}

void PhotoDeleter::deletePhotos(const FuzzyDate& fuzzyDate)
{
	auto photos = _photoRepository->getPhotos();
	vector<IPhoto*> matchingPhotos;
	std::copy_if(
		photos.begin(),
		photos.end(),
		back_inserter(matchingPhotos),
		[fuzzyDate](IPhoto* photo) { return fuzzyDate.contains(photo->getDate()); });

	vector<int> matchingIds;
	std::transform(
		matchingPhotos.begin(),
		matchingPhotos.end(),
		back_inserter(matchingIds),
		[](IPhoto* photo) { return photo->getId(); });

	_photoRepository->deletePhotos(matchingIds);
}

void PhotoDeleter::deletePhotos(const FuzzyDate & fuzzyDate, const Color & color, ContentType contentType)
{
}
