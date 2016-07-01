package eu.sioux.tdd.myfirst;

import java.util.Date;

public class MyFuzzyDate {
    public Date startDate;
    public Date endDate;

    public enum Quarters {
        Q1,
        Q2,
        Q3,
        Q4
    }

    public enum YearType {
        Start,
        Halfway,
        End
    }

    public MyFuzzyDate() {
        startDate = new Date(0);
        endDate = new Date(0);
    }

    public MyFuzzyDate(String string) {
        if (string == "now") {
            startDate = new Date();
            endDate = new Date();
        }
    }

    public MyFuzzyDate(Quarters quart, int year) {
        switch (quart) {
            case Q1:
                startDate = new Date(ConvertYear(year), 0, 1);
                endDate = new Date(ConvertYear(year), 2, 31);
                break;
            case Q2:
                startDate = new Date(ConvertYear(year), 3, 1);
                endDate = new Date(ConvertYear(year), 5, 30);
                break;
            case Q3:
                startDate = new Date(ConvertYear(year), 6, 1);
                endDate = new Date(ConvertYear(year), 8, 30);
                break;
            case Q4:
                startDate = new Date(ConvertYear(year), 9, 1);
                endDate = new Date(ConvertYear(year), 11, 31);
                break;
        }
    }

    public MyFuzzyDate(YearType type, int year) {
        switch (type) {
            case Start:
                startDate = new Date(ConvertYear(year), 0, 1);
                endDate = new Date(ConvertYear(year), 2, 31);
                break;
            case Halfway:
                startDate = new Date(ConvertYear(year), 4, 1);
                endDate = new Date(ConvertYear(year), 7, 31);
                break;
            case End:
                startDate = new Date(ConvertYear(year), 8, 1);
                endDate = new Date(ConvertYear(year), 11, 31);
                break;
        }
    }

    private int ConvertYear(int year) {
        return (year - 1900);
    }

    public Date GetFuzzyStart() {
        return startDate;
    }

    public Date GetFuzzyEnd() {
        return endDate;
    }

    public Date GetFuzzyRange() {
        return new Date(endDate.getTime() - startDate.getTime());
    }

    public boolean contains(Date lookUpDate) {
        boolean startContains = startDate.before(lookUpDate) || startDate.equals(lookUpDate);
        boolean endContains = endDate.after(lookUpDate) || endDate.equals(lookUpDate);
        return (startContains && endContains);
    }
}
