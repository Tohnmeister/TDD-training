package eu.sioux.tdd.util;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class IntrospectionUtils {

    public static Object getPrivateField(final Object o, final String fieldName) {
        // Check we have valid arguments...
        //Assert.assertNotNull(o);
        //Assert.assertNotNull(fieldName);

        // Go and find the private field...
        final Field[] fields = o.getClass().getDeclaredFields();
        for (int i = 0; i < fields.length; ++i) {
            if (fieldName.equals(fields[i].getName())) {
                try {
                    fields[i].setAccessible(true);
                    return fields[i].get(o);
                } catch (IllegalAccessException ex) {
                    //Assert.fail ("IllegalAccessException accessing " + fieldName);
                }
            }
        }
        //Assert.fail ("Field '" + fieldName +"' not found");
        return null;
    }

    public static Object invokePrivateMethod(final Object o, final String methodName, final Object[] params) {
        // Check we have valid arguments...
        //Assert.assertNotNull(o);
        //Assert.assertNotNull(methodName);
        //Assert.assertNotNull(params);

        // Go and find the private method...
        final Method[] methods = o.getClass().getDeclaredMethods();
        for (int i = 0; i < methods.length; ++i) {
            if (methodName.equals(methods[i].getName())) {
                try {
                    methods[i].setAccessible(true);
                    return methods[i].invoke(o, params);
                } catch (IllegalAccessException ex) {
                    //Assert.fail ("IllegalAccessException accessing " + methodName);
                } catch (InvocationTargetException ite) {
                    //Assert.fail ("InvocationTargetException accessing " + methodName);
                }
            }
        }
        //Assert.fail ("Method '" + methodName +"' not found");
        return null;
    }

    public static Object invokePublicGetter(final Object o, final String getterName) {
        final Method[] methods = o.getClass().getDeclaredMethods();
        for (int i = 0; i < methods.length; ++i) {
            if (getterName.equals(methods[i].getName())) {
                try {
                    return methods[i].invoke(o);
                } catch (IllegalAccessException ex) {
                    // break from loop and return null
                    break;
                } catch (InvocationTargetException ite) {
                    // break from loop and return null
                    break;
                }
            }
        }

        return null;
    }

}
