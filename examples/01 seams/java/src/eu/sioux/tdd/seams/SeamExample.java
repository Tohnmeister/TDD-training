package eu.sioux.tdd.seams;

public class SeamExample {






    public void nonSeamExample() {
        Helper.doSomething();
    }































    public void seamExample(Helper helper) {
        helper.doSomething();
    }

}
