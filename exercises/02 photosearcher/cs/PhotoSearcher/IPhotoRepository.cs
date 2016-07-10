using System.Collections.Generic;

namespace PhotoSearcher
{
    public interface IPhotoRepository
    {
        IList<IPhoto> GetPhotos();
        void DeletePhotos(IList<int> ids);
    }
}