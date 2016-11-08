package eu.sioux.tdd.cruisecontrol;

public class CruiseControl {
    /**
     * The cruise control system is tick based. Every 10 ms a tick is generated and tick() is called. The tick function
     * checks the hardware and acts accordingly.
     */
    public void tick() {
        if (Hardware.getInstance().isCruiseControlOn() && Hardware.getInstance().getCurrentSpeed() < Hardware.getInstance().getCruiseControlSpeed()) {
            Hardware.getInstance().accelerate(true);
        } else {
            Hardware.getInstance().accelerate(false);
        }
    }
}