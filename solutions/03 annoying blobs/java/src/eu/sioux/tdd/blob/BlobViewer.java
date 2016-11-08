package eu.sioux.tdd.blob;

public class BlobViewer {

    /**
     * @param args
     */
    public static void main(String[] args) {
        DataDisplayer view = new DataDisplayer();
        DataAdder model = new DataAdder();

        for (int j = 0; j < 30; j++) {
            if ((j % 3) == 0) {
                model.doSomeAdding();
            }

            view.tick();
        }

    }

}
