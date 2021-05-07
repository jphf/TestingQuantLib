#include<ql/quantlib.hpp>
#include<boost/foreach.hpp>
#include<vector>

using namespace QuantLib;

void dayCounterTesting1() {
	DayCounter dc = Thirty360();
	Date d1(1, Oct, 2009);
	Date d2 = d1 + 2 * Months;

	std::cout << "Days Between d1/d2:" << dc.dayCount(d1, d2) << std::endl;
	std::cout << "Year Fraction d1/d2:" << dc.yearFraction(d1, d2) << std::endl;
}

void dayCounterTesting2() {
	Date from(1, Jan, 2020);
	Date to(31, Dec, 2020);
	Calendar calendar = Taiwan();
	std::vector<Date> holidays = calendar.holidayList(from, to, false);

	DayCounter dc = Business252();

	Date mFrom, mTo;

	Date last = from;
	int max = 0;
	int days = 0;
	BOOST_FOREACH(Date d, holidays) {
		days = dc.dayCount(last, d);
		std::cout << last << " " << d << " " << days << std::endl;
		if (max < days) {
			max = days;
			mFrom = last;
			mTo = d;
		}
		last = d;
	}

	days = dc.dayCount(last, to);
	std::cout << last << " " << to << " " << days << std::endl;
	if (max < days) {
		max = days;
		mFrom = last;
		mTo = to;
	}

	std::cout << "from: " << mFrom << std::endl;
	std::cout << "to: " << mTo << std::endl;
	std::cout << "max: " << max << std::endl;
}

//int main() {
//	//dayCounterTesting1();
//	dayCounterTesting2();
//}