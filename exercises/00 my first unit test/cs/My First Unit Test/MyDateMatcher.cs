using System;
using System.Collections.Generic;
using System.Linq;

namespace My_First_Unit_Test
{
    public class MyDateMatcher
    {
        private readonly IList<DateTime> myDates;

        public MyDateMatcher(IList<DateTime> dates)
        {
            myDates = dates;
        }

        public IList<DateTime> DatesAreMatching(MyFuzzyDate fuzzyDate)
        {
            var matches = myDates.Where(fuzzyDate.Contains).ToList();

            return matches;
        }
    }
}
