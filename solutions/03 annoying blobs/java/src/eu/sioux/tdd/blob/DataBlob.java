package eu.sioux.tdd.blob;

import java.util.ArrayList;
import java.util.List;

public class DataBlob {
    public void addData(int i) {
        data.add(i);
    }

    public int getDataAtPos(int p) {
        return data.get(p).intValue();
    }

    DataBlob() {
        data = new ArrayList<>();
    }

    private static DataBlob theBlob = null;
    private List<Integer> data;

    public boolean isEmpty() {
        return data.isEmpty();
    }
}
