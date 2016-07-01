package eu.sioux.tdd.util;


public class LetterNumericUtil {
    public static void main(String[] args) {
        System.out.println(numberFromLetters("B"));
        System.out.println(numberFromLetters("ZC"));
        System.out.println(numberFromLetters("QZC"));
        System.out.println(numberFromLetters("-QZC"));

        System.out.println(lettersFromNumber(11468, 1));
        System.out.println(lettersFromNumber(-11468, 1));
    }


    public static String lettersFromNumber(final int number, final int minimalNumberOfCharacters) {
        // ZC  =   652
        // 652 / 26   =    25 %  2  ->  2 = C
        //  25 / 26   =     0 % 25  -> 25 = Z

        // QZC = 11468
        // 11468 / 26 =   441 %  2  ->  2 = C
        //   441 / 26 =    16 % 25  -> 25 = Z
        //    16 / 26 =     0 % 16  -> 16 = Q 

        StringBuilder alphaNumeric = new StringBuilder();
        String sign = "";

        int intermediate = Math.abs(number);

        if (number < 0) {
            sign = "-";
        }

        while (intermediate > 0) {
            int result = intermediate / 26;
            int rest = intermediate % 26;

            // prepend character
            alphaNumeric.insert(0, letterFromNumber(rest));

            // next time, use result as intermediate
            intermediate = result;
        }

        while (alphaNumeric.length() < minimalNumberOfCharacters) {
            alphaNumeric.insert(0, "A");
        }

        alphaNumeric.insert(0, sign);

        return alphaNumeric.toString();
    }

    public static int numberFromLetters(final String alphaNumeric) {
        int number = 0;
        int sign = 1;

        if (alphaNumeric != null) {
            int alphaLength = alphaNumeric.length();

            String workingString = null;
            int workingLength = 0;

            if (alphaLength > 0 && alphaNumeric.charAt(0) == '-') {
                sign = -1;
                workingString = alphaNumeric.substring(1);
                workingLength = alphaLength - 1;
            } else {
                workingString = alphaNumeric;
                workingLength = alphaLength;
            }


            for (int i = workingLength - 1; i >= 0; i--) {
                char letter = workingString.charAt(i);

                int tempNumber = numberFromLetter(String.valueOf(letter));
                if (tempNumber != -1) {
                    int factor = (int) Math.pow(26, (workingLength - i - 1));
                    number += factor * tempNumber;
                } else {
                    throw new NumberFormatException("Illegal character '" + letter + "'");
                }
            }
        }

        return sign * number;
    }

    private static String letterFromNumber(final int number) {
        String letter = null;

        if (0 <= number && number < 26) {
            // in the '36' radix number range we start at 'A', the 10th number
            int index = number + 10;
            letter = Integer.toString(index, 36).toUpperCase();
        }

        return letter;
    }

    private static int numberFromLetter(final String letter) {
        int number = -1;

        if (letter != null && letter.length() == 1 && Character.isLetter(letter.charAt(0))) {
            // in the '36' radix number range we start at 'A', the 10th number
            number = Integer.parseInt(letter, 36) - 10;
        }

        return number;
    }

}
