package eu.sioux.tdd.blob;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.Assert.assertEquals;

public class BlobViewerTest {
    private PrintStream originalOut;
    private ByteArrayOutputStream byteArrayOutputStream;
    private PrintStream out;

    @Before
    public void setUp() {
        byteArrayOutputStream = new ByteArrayOutputStream();
        originalOut = System.out;
        out = new PrintStream(byteArrayOutputStream);
        System.setOut(out);
    }

    @After
    public void tearDown() {
        System.setOut(originalOut);
        out.close();
    }

    @Test
    public void main() throws Exception {
        BlobViewer.main(new String[0]);

        assertEquals(
                "Creating Blob\r\n" +
                "Data @0=0\r\n" +
                "Data @1=1\r\n" +
                "Data @2=2\r\n" +
                "Data @3=3\r\n" +
                "Data @4=4\r\n" +
                "Data @5=5\r\n" +
                "Data @6=6\r\n" +
                "Data @7=7\r\n" +
                "Data @8=8\r\n" +
                "Data @9=9\r\n" +
                "Data @10=10\r\n" +
                "Data @11=11\r\n" +
                "Data @12=12\r\n" +
                "Data @13=13\r\n" +
                "Data @14=14\r\n" +
                "Data @15=15\r\n" +
                "Data @16=16\r\n" +
                "Data @17=17\r\n" +
                "Data @18=18\r\n" +
                "Data @19=19\r\n" +
                "Data @20=0\r\n" +
                "Data @21=10\r\n" +
                "Data @22=20\r\n" +
                "Data @23=30\r\n" +
                "Data @24=40\r\n" +
                "Data @25=50\r\n" +
                "Data @26=60\r\n" +
                "Data @27=70\r\n" +
                "Data @28=80\r\n" +
                "Data @29=90\r\n", byteArrayOutputStream.toString());
    }

}