using System.Collections.Generic;

namespace PhotoSearcher
{
    public interface IPhotoProvider
    {
        IList<IPhoto> GetPhotos();
    }
}