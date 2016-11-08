package eu.sioux.tdd.cruisecontrol;

public class Hardware {
    private static Hardware instance = null;

    private Hardware() {
    }

    public static Hardware getInstance() {
        if (instance == null) {
            instance = new Hardware();
        }

        return instance;
    }

    public void accelerate(boolean accelerate) {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public int getCurrentSpeed() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public boolean isBreakPressed() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public boolean isClutchPressed() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public boolean isCruiseControlOn() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public void disableCruiseControl() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }

    public int getCruiseControlSpeed() {
        // Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
        throw new RuntimeException("No connection to real car");
    }
}
