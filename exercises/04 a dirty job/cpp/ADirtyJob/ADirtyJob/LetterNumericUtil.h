#ifndef LETTERNUMERICUTIL_H
#define LETTERNUMERICUTIL_H

#include <string>

class LetterNumericUtil
{
public:
	static std::string lettersFromNumber(int number, std::string::size_type minimalNumberOfCharacters);
	static int numberFromLetters(const std::string& alphaNumeric);

private:
	LetterNumericUtil();
	~LetterNumericUtil();

	static std::string letterFromNumber(int number);
	static int numberFromLetter(char letter);
};

#endif