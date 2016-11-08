package eu.sioux.tdd.util;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

/**
 * Collection utilities.
 */
public class CollectionUtil {
    /**
     * Returns all objects of a given type in a given collection. Alternatively,
     * use Apache Commons collections framework.
     *
     * @param <T>    The type to match against.
     * @param source The collection searched for candidates.
     * @param type   The {@link Class} representation of <code>T</code>.
     * @return An array with all elements of type <code>T</code> contained in
     * <code>source</code>. Contains as many references to a single
     * object as present in the <code>source</code> collection.
     */
    @SuppressWarnings("unchecked")
    public static <T> T[] getObjectsByType(final Collection<? super T> source, final Class<T> type) {
        List<T> result = new ArrayList<>(source.size());
        for (Object o : source) {
            if (type.isInstance(o)) {
                result.add((T) o);
            }
        }
        return result.toArray((T[]) Array.newInstance(type, result.size()));
    }

    /**
     * Removes any duplicate entries from a given list.
     *
     * @param list The given list.
     */
    public static void removeDuplicates(final List<Object> list) {
        for (int i = 0; i < list.size(); i++) {
            Object current = list.get(i);
            list.set(i, null);
            while (list.contains(current)) {
                list.remove(current);
            }
            list.set(i, current);
        }
    }

    /**
     * Does a SQL-like SELECT on a table, matching the getter results as
     * specified in matchMask from key.
     *
     * @param table           collection to search
     * @param sortMask        list of getters that define the sort sequence of the table
     * @param matchMask       list of getters that should match in this SELECT query
     * @param key             key to match
     * @param allowDuplicates allow duplicates in the query result or not
     * @return query result as an Object List
     */
    public static List<Object> select(final List<?> table, final String[] sortMask, final String[] matchMask, final Object key, final boolean allowDuplicates) {
        Vector<Object> result = new Vector<>();

        // For sorting, use all sortMask
        IntrospectiveComparator registrySorter = new IntrospectiveComparator(sortMask);

        // for searching, use matchMask
        IntrospectiveComparator registryFinder = new IntrospectiveComparator(matchMask);

        // sort using the above sequence
        Collections.sort(table, registrySorter);

        // find one of the elements matching key

        if (!table.isEmpty()) {
            int foundIndex = Collections.binarySearch(table, key, registryFinder);
            if (foundIndex >= 0) {
                // Found one!
                int index = foundIndex;
                Object foundElement = null;
                int compareResult = 0;

                // found element can be any element in a set, iterate backwards
                // from foundIndex
                // and insert at beginning of result list as long as elements
                // match find result
                while ((index >= 0) && (compareResult == 0)) {
                    foundElement = table.get(index);
                    compareResult = registryFinder.compare(foundElement, key);
                    if (compareResult == 0) {
                        // if duplicates are not allowed, only add object if it
                        // didn't exist in the result set yet
                        if (allowDuplicates || (!result.contains(foundElement))) {
                            result.insertElementAt(foundElement, 0);
                        }
                    }
                    index--;
                }

                // ...and iterate forwards from the same point and add at end of
                // result list
                index = foundIndex + 1;
                compareResult = 0;
                while ((index < table.size()) && (compareResult == 0)) {
                    foundElement = table.get(index);
                    compareResult = registryFinder.compare(foundElement, key);
                    if (compareResult == 0) {
                        // if duplicates are not allowed, only add object if it
                        // didn't exist in the result set yet
                        if (allowDuplicates || (!result.contains(foundElement))) {
                            result.add(foundElement);
                        }
                    }
                    index++;
                }
            }
        }

        return result;
    }


}
