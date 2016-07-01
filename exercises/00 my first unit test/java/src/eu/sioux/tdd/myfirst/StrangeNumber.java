package eu.sioux.tdd.myfirst;

public class StrangeNumber {
    private double value = 0.0;

    public double getDouble() {
        return this.value;
    }

    public void setDouble(double value) {
        this.value = value;
    }

    public void add(double i) {
        this.value += i;
    }

    public void subtract(double i) {
        this.value -= i;
    }

    public void divide(double i) {
        this.value /= i;
    }

    public void multiple(double i) {
        this.value *= i;
    }
}
