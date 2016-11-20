#ifndef IPHOTOREPOSITORY_H
#define IPHOTOREPOSITORY_H

#include <vector>

struct IPhoto;

struct IPhotoRepository
{
	virtual ~IPhotoRepository() = 0;

	virtual std::vector<IPhoto*> getPhotos() const = 0;
	virtual void deletePhotos(const std::vector<int>& ids) = 0;

};

#endif
