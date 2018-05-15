package eu.sioux.tdd.photosearcher;

import java.util.Optional;

public class PhotoDeleter {
    private final PhotoRepository photoRepository;

    public PhotoDeleter(PhotoRepository photoRepository) {
        this.photoRepository = photoRepository;
    }

    public void deletePhotos(FuzzyDate date) {
        // Use test-driven development to implement this method
        throw new UnsupportedOperationException();
    }

    public void deletePhotos(Optional<FuzzyDate> fuzzyDate, Optional<Color> color, Optional<ContentType> contentType) {
        // Use test-driven development to implement this method
        throw new UnsupportedOperationException();
    }

}