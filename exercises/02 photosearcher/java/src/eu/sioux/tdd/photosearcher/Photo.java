package eu.sioux.tdd.photosearcher;

import java.util.Date;

public interface Photo {
    Date getDate();
    Color getColor();
    ContentType getContentType();
}
