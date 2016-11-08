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

	string delim;
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
				
				if (!delim.empty())
					delim += "|";

				delim += currDelim;
				remainingString = remainingString.substr(endDelimPos + 1);
			}
			delim = "(" + delim + ")";
			numberStr = remainingString;
		}
		else
		{
			delim = str[2];
			numberStr = str.substr(3);
		}
	}
	else
	{
		delim = "[,\n]";
		numberStr = str;
	}

	vector<string> strings = split(numberStr, delim);
	
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