#include "StringCalculator.h"
#include <sstream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

int StringCalculator::calculate(const std::string & str)
{
	if (str.empty())
		return 0;

	vector<string> delimiters;
	string numberStr;
	if (str.find("//") == 0)
	{
		string remainingString = str.substr(2);

		if (remainingString[0] == '[')
		{
			while (remainingString[0] == '[')
			{
				string::size_type endDelimPos = remainingString.find(']');
				string currDelim = remainingString.substr(1, endDelimPos - 1);
				
				delimiters.push_back(currDelim);
				remainingString = remainingString.substr(endDelimPos + 1);
			}
			numberStr = remainingString;
		}
		else
		{
			delimiters.push_back(string(1, (str[2])));
			numberStr = str.substr(3);
		}
	}
	else
	{
		delimiters.push_back(",");
		delimiters.push_back("\n");
		numberStr = str;
	}

	vector<string> strings = split(numberStr, delimiters);
	
	int sum = 0;
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		int number;
		stringstream ss(*it);
		ss >> number;

		if (number < 0)
			throw exception();

		if (number <= 1000)
			sum += number;
	}

	return sum;
}

StringCalculator::StringCalculator()
{
}

StringCalculator::~StringCalculator()
{
}