using System;
using System.Collections.Generic;

namespace PhotoSearcher
{
    public class PhotoSearcher
    {
        private IPhotoProvider _provider;

        public PhotoSearcher(IPhotoProvider provider)
        {
            _provider = provider;
        }

        public IList<IPhoto> SearchPhotos(FuzzyDate fuzzyDate)
        {
            // Use test-driven development to implement this method
            throw new NotImplementedException();
        }

        public IList<IPhoto> SearchPhotos(FuzzyDate fuzzyDate, Color color, ContentType? contentType)
        {
            // Use test-driven development to implement this method
            throw new NotImplementedException();
        }

    }
}
