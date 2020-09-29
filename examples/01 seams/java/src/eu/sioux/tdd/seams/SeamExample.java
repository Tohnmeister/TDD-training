package eu.sioux.tdd.seams;

public class SeamExample {
    private TemperatureSensor temperatureSensor;

    public SeamExample() {
        temperatureSensor = new TemperatureSensor();
        temperatureSensor.init();
    }

    public boolean isAllowedOutside() {
        if (temperatureSensor.readTemperature() >= 38.0) {
            return false;
        } else {
            return true;
        }
    }
}
