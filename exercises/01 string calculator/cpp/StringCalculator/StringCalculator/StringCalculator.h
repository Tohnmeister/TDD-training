#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <regex>

class StringCalculator
{
public:

private:
	StringCalculator();
	virtual ~StringCalculator();

	// See far below if you find yourself having trouble splitting a string in C++.





























































	std::vector<std::string> StringCalculator::split(const std::string& str, const std::string& regex)
	{
		std::regex re(regex);
		std::sregex_token_iterator
			first{ str.begin(), str.end(), re, -1 },
			last;
		return{ first, last };
	}
};

#endif