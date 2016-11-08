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

	// The goal of this exercise is not to find a string split function in C++. Hence, it is provided.
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