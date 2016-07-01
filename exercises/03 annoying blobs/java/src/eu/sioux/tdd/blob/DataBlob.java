package eu.sioux.tdd.blob;

import java.util.ArrayList;
import java.util.List;

public class DataBlob {
    public static DataBlob getBlob() {
        return createOrReturnBlob();
    }

    public void addData(int i) {
        data.add(i);
    }

    public int getDataAtPos(int p) {
        return data.get(p).intValue();
    }

    private static DataBlob createOrReturnBlob() {
        if (theBlob == null) {
            System.out.println("Creating Blob");
            theBlob = new DataBlob();
            for (int i = 0; i < 20; i++) {
                theBlob.addData(i);
            }
        }

        return theBlob;
    }

    private DataBlob() {
        data = new ArrayList<>();
    }

    private static DataBlob theBlob = null;
    private List<Integer> data;

    public boolean isEmpty() {
        return data.isEmpty();
    }
}
