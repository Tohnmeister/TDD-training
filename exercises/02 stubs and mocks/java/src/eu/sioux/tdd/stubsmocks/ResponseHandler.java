package eu.sioux.tdd.stubsmocks;

public interface ResponseHandler {
    void receive(String message);

    String getName();
}

