#include "LetterNumericUtil.h"
#include <cmath>
#include <exception>
#include <cctype>

using namespace std;

std::string LetterNumericUtil::lettersFromNumber(int number, string::size_type minimalNumberOfCharacters)
{
	// ZC  =   652
	// 652 / 26   =    25 %  2  ->  2 = C
	//  25 / 26   =     0 % 25  -> 25 = Z

	// QZC = 11468
	// 11468 / 26 =   441 %  2  ->  2 = C
	//   441 / 26 =    16 % 25  -> 25 = Z
	//    16 / 26 =     0 % 16  -> 16 = Q 

	string alphaNumeric;
	string sign = "";

	int intermediate = abs(number);

	if (number < 0)
	{
		sign = "-";
	}

	while (intermediate > 0)
	{
		int result = intermediate / 26;
		int rest = intermediate % 26;

		// prepend character
		alphaNumeric.insert(0, letterFromNumber(rest));

		// next time, use result as intermediate
		intermediate = result;
	}

	while (alphaNumeric.length() < minimalNumberOfCharacters)
	{
		alphaNumeric.insert(0, "A");
	}

	alphaNumeric.insert(0, sign);

	return alphaNumeric;
}

int LetterNumericUtil::numberFromLetters(const std::string& alphaNumeric)
{
	int number = 0;
	int sign = 1;
	int alphaLength = alphaNumeric.length();

	string workingString;
	int workingLength = 0;

	if (alphaLength > 0 && alphaNumeric[0] == '-')
	{
		sign = -1;
		workingString = alphaNumeric.substr(1);
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

		int tempNumber = numberFromLetter(letter);
		if (tempNumber != -1)
		{
			int factor = static_cast<int>(pow(26, (workingLength - i - 1)));
			number += factor * tempNumber;
		}
		else
		{
			string exceptionMessage = "Illegal character '" + string(1, letter) + "'";
			throw exception(exceptionMessage.c_str());
		}
	}

	return sign * number;
}

LetterNumericUtil::LetterNumericUtil()
{
}


LetterNumericUtil::~LetterNumericUtil()
{
}

std::string LetterNumericUtil::letterFromNumber(int number)
{
	string letter;

	if (0 <= number && number < 26)
	{
		char c = (char)(number + 65);
		letter = string(1, c);
	}

	return letter;
}

int LetterNumericUtil::numberFromLetter(char letter)
{
	int number = -1;

	if (isalpha(letter))
	{
		number = static_cast<int>(letter) - 65;
	}

	return number;
}
