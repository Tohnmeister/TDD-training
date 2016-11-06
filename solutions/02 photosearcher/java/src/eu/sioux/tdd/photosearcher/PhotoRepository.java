package eu.sioux.tdd.photosearcher;

import java.util.List;

public interface PhotoRepository {
    List<Photo> getPhotos();
    void deletePhotos(List<Integer> ids);
}
