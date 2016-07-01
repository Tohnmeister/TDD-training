package eu.sioux.tdd.myfirst;

import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.List;

public class MyDateMatcher {
    private final List<Date> myDates;

    public MyDateMatcher(List<Date> dates) {
        myDates = dates;
    }

    public List<Date> DatesAreMatching(MyFuzzyDate fuzzyDate) {
        List<Date> matches = new ArrayList<>();
        matches.clear();

        Iterator<Date> it = myDates.iterator();

        while (it.hasNext()) {
            Date date = (Date) it.next();
            if (fuzzyDate.contains(date)) {
                matches.add(date);
            }
        }

        return matches;
    }
}