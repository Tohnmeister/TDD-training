package eu.sioux.tdd.blob;

import org.junit.Test;

import static org.junit.Assert.*;

public class DataBlobFactoryTest {
    @Test
    public void shouldCreateDataBlob() {
        DataBlob dataBlob = new DataBlobFactory().createDataBlob();
        assertNotNull(dataBlob);
    }

    @Test
    public void shouldCreateDataBlobWithInitialContents() {
        DataBlob dataBlob = new DataBlobFactory().createDataBlob();
        assertNotNull(dataBlob);
    }

}