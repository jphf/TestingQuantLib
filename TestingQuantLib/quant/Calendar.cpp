#include<ql/quantlib.hpp>
#include<boost/foreach.hpp>
using namespace QuantLib;

void CalendarTesting1() {
	Calendar frankfCal = Germany(Germany::FrankfurtStockExchange);
	Calendar saudiArabCal = SaudiArabia();
	Date nyEve(31, Dec, 2009);

	std::cout << "Is BD:" << frankfCal.isBusinessDay(nyEve) << std::endl;
	std::cout << "Is Holiday:" << frankfCal.isHoliday(nyEve) << std::endl;
	std::cout << "Is Weekend:" << saudiArabCal.isWeekend(Saturday) << std::endl;
	std::cout << "Is Last BD:" << frankfCal.isEndOfMonth(Date(30, Dec, 2009)) << std::endl;
	std::cout << "Last BD:" << frankfCal.endOfMonth(nyEve) << std::endl;
}

void CalendarTesting2() {
	Calendar frankfCal = Germany(Germany::FrankfurtStockExchange);
	Date d1(24, Dec, 2009), d2(30, Dec, 2009), d3(31, Dec, 2009);

	frankfCal.addHoliday(d2);
	frankfCal.removeHoliday(d3);

	std::cout << "Is Business Day:" << frankfCal.isBusinessDay(d2) << std::endl;
	std::cout << "Is Business Day:" << frankfCal.isBusinessDay(d3) << std::endl;

	std::vector<Date> holidayVec = frankfCal.holidayList(d1, d2, false);
	std::cout << "----------" << std::endl;
	BOOST_FOREACH(Date d, holidayVec) std::cout << d << std::endl;
}

void CalendarTesting3() {
	Calendar frankfCal = Germany(Germany::FrankfurtStockExchange);
	Date firstDate(31, Oct, 2009);
	Date secondDate(1, Jan, 2010);

	std::cout << "Date 2 Adv:" << frankfCal.adjust(secondDate, BusinessDayConvention(Preceding)) << std::endl;
	std::cout << "Date 2 Adv:" << frankfCal.adjust(secondDate, BusinessDayConvention(ModifiedFollowing)) << std::endl;

	Period mat(2, Months);
	std::cout << "Date 1 Month Adv:" << frankfCal.advance(firstDate, mat, BusinessDayConvention(Following), false) << std::endl;
	std::cout << "Date 1 Month Adv:" << frankfCal.advance(firstDate, mat, BusinessDayConvention(ModifiedFollowing), false) << std::endl;

	std::cout << "Business Days Between:" << frankfCal.businessDaysBetween(firstDate, secondDate, false, false);
}

void CalendarTesting4() {
	Date from(1, Jan, 2009);
	Date to(31, Dec, 2009);
	Calendar calendars[] = { Germany(), UnitedKingdom(), UnitedStates(), Switzerland() , Japan() };

	int size;
	int max = 0;
	Calendar maxCalendar;
	BOOST_FOREACH(Calendar c, calendars) {
		size = c.holidayList(from, to, false).size();
		//std::cout << c << ": " << c.holidayList(from, to, false).size() << std::endl;
		if (max < size) {
			max = size;
			maxCalendar = c;
		}
	}

	std::cout << maxCalendar << std::endl;
}

//int main() {
//	//CalendarTesting1();
//	//CalendarTesting2();
//	//CalendarTesting3();
//	CalendarTesting4();
//}