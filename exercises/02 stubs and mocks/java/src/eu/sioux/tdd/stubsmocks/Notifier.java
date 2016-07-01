package eu.sioux.tdd.stubsmocks;

import java.util.ArrayList;
import java.util.List;

public class Notifier {
    private List<ResponseHandler> responseHandlers = new ArrayList<>();

    public void add(ResponseHandler subscriber) {
        responseHandlers.add(subscriber);
    }

    public void publish(String message) {
        for (ResponseHandler responseHandler : responseHandlers) {
            System.out.println("Notifying " + responseHandler.getName() + " with message: " + message);
            responseHandler.receive(message);
        }
    }
}
