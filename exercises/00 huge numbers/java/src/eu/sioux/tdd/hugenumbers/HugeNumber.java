package eu.sioux.tdd.hugenumbers;

import java.util.ArrayList;


public class HugeNumber {
    private ArrayList<Integer> lowerLimits = new ArrayList<>();
    private ArrayList<Integer> numbers = new ArrayList<>();
    private ArrayList<Integer> upperLimits = new ArrayList<>();

    /**
     * Constructs a composite number, least significant values specified first
     */
    public HugeNumber(int[] loLimits, int[] hiLimits, int[] values) {
        assert (loLimits.length == hiLimits.length) && (hiLimits.length == values.length);

        int size = values.length;

        for (int i = 0; i < size; i++) {
            lowerLimits.add(loLimits[i]);
            numbers.add(0);
            upperLimits.add(hiLimits[i]);
        }

        for (int j = 0; j < size; j++) {
            setValueInternal(j, values[j]);
        }
    }

    public int getValue(int index) {
        checkIndex(index);

        return numbers.get(index);
    }

    public int getLowerBound(int index) {
        checkIndex(index);

        return lowerLimits.get(index);
    }

    public int getUpperBound(int index) {
        checkIndex(index);

        return upperLimits.get(index);
    }

    public int getNormalizedValue(int index) {
        checkIndex(index);

        return numbers.get(index) - lowerLimits.get(index);
    }

    private int getRange(int index) {
        checkIndex(index);

        return upperLimits.get(index) - lowerLimits.get(index) + 1;
    }

    public int getRange() {
        int range = 1;
        for (int i = 0; i < numbers.size(); i++) {
            range = range * getRange(i);
        }

        return range;
    }

    public Long toInt() {
        long _i = 0;

        for (int si = numbers.size() - 1; si >= 0; si--) {
            long curval = getNormalizedValue(si);

            if (si > 0) {
                _i += curval * getRange(si - 1);
            } else {
                _i += curval;
            }
        }

        return Long.valueOf(_i);
    }


    public void add(int offset) {
        add(0, offset);
    }

    public void add(int index, int offset) {
        checkIndex(index);

        int temp = numbers.get(index) + offset;

        setValueInternal(index, temp);
    }

    public void setValue(int index, int newValue) {
        checkIndex(index);

        setValueInternal(index, newValue);
    }

    private void setValueInternal(int index, int newValue) {
        int loLimit = lowerLimits.get(index);
        int hiLimit = upperLimits.get(index);
        //int oldValue = numbers.get(index);

        try {
            if (newValue < loLimit) {
                setValueInternal(index, loLimit);
                int underFlowIndex = index - 1;
                checkIndex(underFlowIndex);
                int difference = loLimit - newValue;
                int newUnderflowValue = numbers.get(underFlowIndex) - difference;
                setValueInternal(underFlowIndex, newUnderflowValue);
            } else if (newValue > hiLimit) {
                setValueInternal(index, loLimit);
                int overFlowIndex = index + 1;
                checkIndex(overFlowIndex);
                int difference = newValue - hiLimit;

                int newOverflowValue = numbers.get(overFlowIndex) + difference;
                setValueInternal(overFlowIndex, newOverflowValue);
            } else {
                numbers.set(index, newValue);
            }
        } catch (IndexOutOfBoundsException iobe) {
            // under or overflow
            throw new NumberFormatException(iobe.getMessage() + " for position " + index);
        }
    }

    private void checkIndex(int index) {
        if (!((index >= 0) && (index < numbers.size()))) {
            throw new IndexOutOfBoundsException(this.getClass().getCanonicalName() + " index=" + index + " out of bounds: 0<=index<" + numbers.size());
        }
    }

    public String toString() {
        StringBuilder stringVal = new StringBuilder();
        for (int si = numbers.size() - 1; si >= 0; si--) {
            stringVal.append(numbers.get(si));
            if (si > 0) {
                stringVal.append(",");
            }
        }
        return stringVal.toString();
    }
}
