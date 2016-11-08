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
	static std::vector<std::string> split(const std::string& str, const std::vector<std::string>& delimiters)
	{
		std::vector<std::string> strings;
		std::string::size_type startPos = 0;
		std::string::size_type currentPos = 0;
		const std::string::size_type length = str.length();
		while (currentPos < length)
		{
			auto it = std::find_if(delimiters.begin(), delimiters.end(),
				[str, currentPos](std::string delimiter){ return str.substr(currentPos, delimiter.length()) == delimiter; });

			if (it != delimiters.end())
			{
				strings.push_back(str.substr(startPos, currentPos - startPos));
				startPos = currentPos + it->length();
				currentPos = startPos;
			}
			else
			{
				++currentPos;
			}
		}
		strings.push_back(str.substr(startPos));

		return strings;
	}
};

#endif