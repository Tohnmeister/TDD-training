#include "PhotoDeleter.h"
#include "FuzzyDate.h"
#include "Color.h"

PhotoDeleter::PhotoDeleter(std::shared_ptr<IPhotoRepository> photoRepository) :
	_photoRepository(photoRepository)
{
}

PhotoDeleter::~PhotoDeleter()
{
}

void PhotoDeleter::deletePhotos(const FuzzyDate & fuzzyDate)
{
}

void PhotoDeleter::deletePhotos(const FuzzyDate & fuzzyDate, const Color & color, ContentType contentType)
{
}
