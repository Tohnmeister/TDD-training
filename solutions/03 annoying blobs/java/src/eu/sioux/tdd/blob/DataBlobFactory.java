package eu.sioux.tdd.blob;

public class DataBlobFactory {
    public DataBlob createDataBlob() {
        System.out.println("Creating Blob");
        DataBlob theBlob = new DataBlob();
        for (int i = 0; i < 20; i++) {
            theBlob.addData(i);
        }
        return theBlob;
    }
}
