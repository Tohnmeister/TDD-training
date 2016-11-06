package eu.sioux.tdd.photosearcher;

import java.util.Date;

public interface Photo {
    int getId();
    Date getDate();
    Color getColor();
    ContentType getContentType();
}
