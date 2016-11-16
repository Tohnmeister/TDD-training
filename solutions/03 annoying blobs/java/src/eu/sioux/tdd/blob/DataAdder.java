package eu.sioux.tdd.blob;

public class DataAdder {
    private DataBlob dataBlob;
    private int newData = 0;

    public DataAdder(DataBlob dataBlob) {
        this.dataBlob = dataBlob;
    }

    public void doSomeAdding() {
        dataBlob.addData(newData);
        newData += 10;
    }

}
