#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <regex>

class StringCalculator
{
public:
	static int calculate(const std::string& str);

private:
	StringCalculator();
	virtual ~StringCalculator();

	// The goal of this exercise is not to find a string split function in C++. Hence, it is provided.
	static std::vector<std::string> split(const std::string& str, const std::string& regex)
	{
		std::regex re(regex);
		std::sregex_token_iterator
			first{ str.begin(), str.end(), re, -1 },
			last;
		return{ first, last };
	}

};

#endif