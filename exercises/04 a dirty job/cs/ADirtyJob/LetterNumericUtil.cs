using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ADirtyJob
{
    class LetterNumericUtil
    {
        static void Main(string[] args)
        {
            Console.WriteLine(NumberFromLetters("B"));
            Console.WriteLine(NumberFromLetters("ZC"));
            Console.WriteLine(NumberFromLetters("QZC"));
            Console.WriteLine(NumberFromLetters("-QZC"));

            Console.WriteLine(lettersFromNumber(11468, 1));
            Console.WriteLine(lettersFromNumber(-11468, 1));
            Console.ReadKey();
        }


        public static string lettersFromNumber(int number, int minimalNumberOfCharacters)
        {
            // ZC  =   652
            // 652 / 26   =    25 %  2  ->  2 = C
            //  25 / 26   =     0 % 25  -> 25 = Z

            // QZC = 11468
            // 11468 / 26 =   441 %  2  ->  2 = C
            //   441 / 26 =    16 % 25  -> 25 = Z
            //    16 / 26 =     0 % 16  -> 16 = Q 

            StringBuilder alphaNumeric = new StringBuilder();
            string sign = "";

            int intermediate = Math.Abs(number);

            if (number < 0)
            {
                sign = "-";
            }

            while (intermediate > 0)
            {
                int result = intermediate / 26;
                int rest = intermediate % 26;

                // prepend character
                alphaNumeric.Insert(0, LetterFromNumber(rest));

                // next time, use result as intermediate
                intermediate = result;
            }

            while (alphaNumeric.Length < minimalNumberOfCharacters)
            {
                alphaNumeric.Insert(0, "A");
            }

            alphaNumeric.Insert(0, sign);

            return alphaNumeric.ToString();
        }

        public static int NumberFromLetters(string alphaNumeric)
        {
            int number = 0;
            int sign = 1;

            if (alphaNumeric != null)
            {
                int alphaLength = alphaNumeric.Length;

                string workingString = null;
                int workingLength = 0;

                if (alphaLength > 0 && alphaNumeric[0] == '-')
                {
                    sign = -1;
                    workingString = alphaNumeric.Substring(1);
                    workingLength = alphaLength - 1;
                }
                else
                {
                    workingString = alphaNumeric;
                    workingLength = alphaLength;
                }


                for (int i = workingLength - 1; i >= 0; i--)
                {
                    char letter = workingString[i];

                    int tempNumber = NumberFromLetter(letter.ToString());
                    if (tempNumber != -1)
                    {
                        int factor = (int)Math.Pow(26, (workingLength - i - 1));
                        number += factor * tempNumber;
                    }
                    else
                    {
                        throw new FormatException("Illegal character '" + letter + "'");
                    }
                }
            }

            return sign * number;
        }

        private static string LetterFromNumber(int number)
        {
            string letter = null;

            if (0 <= number && number < 26)
            {
                char c = (char) (number + 65);
                letter = c.ToString();
            }

            return letter;
        }

        private static int NumberFromLetter(string letter)
        {
            int number = -1;

            if (letter != null && letter.Length == 1 && Char.IsLetter(letter[0]))
            {
                char c = letter[0];
                number = (int)c - 65;
            }

            return number;
        }
    }
}
