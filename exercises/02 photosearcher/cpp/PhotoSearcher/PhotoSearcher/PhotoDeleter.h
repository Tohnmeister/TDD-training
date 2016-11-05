#ifndef PHOTODELETER_H
#define PHOTODELETER_H

#include <memory>
#include "ContentType.h"

class IPhotoRepository;
class FuzzyDate;
class Color;

class PhotoDeleter
{
public:
	PhotoDeleter(std::shared_ptr<IPhotoRepository> photoRepository);
	virtual ~PhotoDeleter();

	void deletePhotos(const FuzzyDate& fuzzyDate);
	void deletePhotos(const FuzzyDate& fuzzyDate, const Color& color, ContentType contentType);

private:
	std::shared_ptr<IPhotoRepository> _photoRepository;

};

#endif