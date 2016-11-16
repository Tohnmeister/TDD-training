package eu.sioux.tdd.blob;

public class DataDisplayer {
    private DataBlob dataBlob;

    public DataDisplayer(DataBlob dataBlob) {
        this.dataBlob = dataBlob;
    }

    public void tick() {
        int value = dataBlob.getDataAtPos(position);
        System.out.println("Data @" + position + "=" + value);
        position++;
    }

    private int position = 0;
}