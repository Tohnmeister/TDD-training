using System;
using System.Collections.Generic;

namespace PhotoSearcher
{
    public class PhotoDeleter
    {
        private IPhotoRepository _photoRepository;

        public PhotoDeleter(IPhotoRepository photoRepository)
        {
            _photoRepository = photoRepository;
        }

        public void DeletePhotos(FuzzyDate fuzzyDate)
        {
            // Use test-driven development to implement this method
            throw new NotImplementedException();
        }

        public void DeletePhotos(FuzzyDate fuzzyDate, Color color, ContentType? contentType)
        {
            // Use test-driven development to implement this method
            throw new NotImplementedException();
        }

    }
}
