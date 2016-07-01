/**
 *
 */
package eu.sioux.tdd.util;

/**
 * @author Tjakko Kleinhuis
 */
public class StringParseUtil {
    public static String cleanupStringFrom(String stringToCleanup, String charsToRemove) {
        return filterString(stringToCleanup, charsToRemove, false);
    }

    public static String filterString(String stringToFilter, String charsToKeep) {
        return filterString(stringToFilter, charsToKeep, true);
    }

    private static String filterString(String stringToFilter, String charsToFilter, boolean positive) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < stringToFilter.length(); i++) {
            char filterChar = stringToFilter.charAt(i);

            conditionalAppend(result, charsToFilter, filterChar, positive);
        }

        return result.toString();
    }

    private static void conditionalAppend(StringBuilder result, String charsToFilter, char filterChar, boolean positive) {
        if (positive) {
            if (charsToFilter.indexOf(filterChar) >= 0) {
                // >=0 means char in filter set

                // only put characters NOT in charsToRemove in new string
                result.append(filterChar);
            }
        } else {
            if (charsToFilter.indexOf(filterChar) < 0) {
                // -1 is returned by indexOf if no occurrence;

                // only put characters NOT in charsToRemove in new string
                result.append(filterChar);
            }
        }
    }

}
