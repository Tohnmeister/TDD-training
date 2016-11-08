package eu.sioux.tdd.blob;

import org.mockito.*;

public class DataAdder {
    public void doSomeAdding() {
        DataBlob.getBlob().addData(newData);
        newData += 10;
    }

    private int newData = 0;
}
