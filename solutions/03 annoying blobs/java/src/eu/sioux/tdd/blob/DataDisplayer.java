package eu.sioux.tdd.blob;

public class DataDisplayer {
    public void tick() {
        int value = DataBlob.getBlob().getDataAtPos(position);
        System.out.println("Data @" + position + "=" + value);
        position++;
    }

    private int position = 0;
}
