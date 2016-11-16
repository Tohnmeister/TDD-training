package eu.sioux.tdd.blob;

public class BlobViewer {

    /**
     * @param args
     */
    public static void main(String[] args) {
        DataBlob dataBlob = new DataBlobFactory().createDataBlob();
        DataDisplayer view = new DataDisplayer(dataBlob);
        DataAdder model = new DataAdder(dataBlob);

        for (int j = 0; j < 30; j++) {
            if ((j % 3) == 0) {
                model.doSomeAdding();
            }

            view.tick();
        }

    }

}
