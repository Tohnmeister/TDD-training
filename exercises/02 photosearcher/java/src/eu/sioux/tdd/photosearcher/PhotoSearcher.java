package eu.sioux.tdd.photosearcher;

import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class PhotoSearcher {
    private final PhotoProvider provider;

    public PhotoSearcher(PhotoProvider provider) {
        this.provider = provider;
    }

    public List<Photo> searchPhotos(FuzzyDate date) {
        // Use test-driven development to implement this method
        throw new NotImplementedException();
    }

    public List<Photo> searchPhotos(Optional<FuzzyDate> fuzzyDate, Optional<Color> color, Optional<ContentType> contentType) {
        // Use test-driven development to implement this method
        throw new NotImplementedException();
    }

}