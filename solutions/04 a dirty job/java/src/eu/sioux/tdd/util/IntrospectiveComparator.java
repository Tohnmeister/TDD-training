package eu.sioux.tdd.util;

import java.io.Serializable;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Comparator;
import java.util.Vector;

/**
 * Comparator for sorting and searching an Object List. It in fact compares a
 * set of given attributes in sequence until either 1) any single comparison
 * returns a non-zero result (and that result is then returned), or 2) the
 * ComparatorChain is exhausted (and zero is returned). This type of sorting is
 * very similar to multi-column sorting in SQL, and this class allows emulation
 * of that kind of behaviour when sorting a List.
 */
public class IntrospectiveComparator implements Comparator<Object>, Serializable {
    private static final long serialVersionUID = 1L;

    private Vector<String> getterMethods;

    public IntrospectiveComparator() {
        this.getterMethods = new Vector<>();
    }

    public IntrospectiveComparator(final String[] getterSortSequence) {
        this.getterMethods = new Vector<>();

        if (getterSortSequence != null) {
            for (int i = 0; i < getterSortSequence.length; i++) {
                this.getterMethods.add(getterSortSequence[i]);
            }
        }
    }

    /**
     * {@inheritDoc}
     */
    public int compare(final Object left, final Object right) {
        int result = 0;

        for (String getterMethod : this.getterMethods) {
            result = compareGetterResult(getterMethod, left, right);
            if (result != 0) {
                break;
            }
        }

        return result;
    }

    /**
     * Compares only ONE attribute
     *
     * @see compare
     */
    public static int compareGetterResult(final String getterMethod, final Object left, final Object right) {

        Object leftResult = invokeGetter(left, getterMethod);
        Object rightResult = invokeGetter(right, getterMethod);

        if ((leftResult instanceof Comparable<?>) && (rightResult instanceof Comparable<?>)) {
            if ((leftResult != null) && (rightResult != null)) {
                return ((Comparable) leftResult).compareTo(rightResult);
            } else if (leftResult == null) {
                return -1;
            } else {
                return 1;
            }
        }

        String leftString = (leftResult != null) ? leftResult.toString() : "";
        String rightString = (rightResult != null) ? rightResult.toString() : "";

        return leftString.compareTo(rightString);
    }

    /**
     * Invokes a "getter" (i.e., a method that returns an Object) on an object
     *
     * @param object     object to invoke getter on
     * @param getterName method name to invoke
     * @return (getter) method result
     */
    public static Object invokeGetter(final Object object, final String getterName) {
        final Method[] methods = object.getClass().getDeclaredMethods();
        for (int i = 0; i < methods.length; ++i) {
            if (getterName.equals(methods[i].getName())) {
                try {
                    return methods[i].invoke(object);
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
