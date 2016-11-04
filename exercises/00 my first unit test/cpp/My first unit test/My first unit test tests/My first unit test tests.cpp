#include <iostream>
#include "FuzzyDate.h"

using namespace std;
using namespace date;

int main()
{
	FuzzyDate fd(Quarters::Q4, 2017);
	cout << fd.contains(year{ 2017 } / 10 / 1);

    return 0;
}