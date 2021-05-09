#include<ql/quantlib.hpp>
#include<boost/shared_ptr.hpp>
#include"SimpleYield.h"

void testingDesignPattern2() {
	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Time mat = 1.0;
	SimpleDiscountFactor myDf(myYield, mat);
	std::cout << "Discount before update:" << myDf.getDiscount() << std::endl;
	myYield->setYield(0.01);
	std::cout << "Discount after update:" << myDf.getDiscount() << std::endl;
}

void testingDesignPattern3() {
	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Time mat = 1.0;

	boost::shared_ptr<SimpleDiscountFactor> myDf(new SimpleDiscountFactor(myYield, mat));

	SimpleDiscountedCF myCf(myDf);

	std::cout << "Cash Flow before update:" << myCf.discountCashFlow(100.0) << std::endl;
	myYield->setYield(0.01);
	std::cout << "Cash Flow after update:" << myCf.discountCashFlow(100.0) << std::endl;
}

void testingDesignPattern2a() {
	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Date mat = Date::todaysDate() + 12 * Months;
	DayCounter dc = ActualActual();

	SimpleDiscountFactor1 myDf(myYield, mat, dc);

	std::cout << "Discount before yield update:" << myDf.getDiscount() << std::endl;
	myYield->setYield(0.01);
	std::cout << "Discount after yield update:" << myDf.getDiscount() << std::endl;
	Settings::instance().evaluationDate() = mat - 1 * Months;
	std::cout << "Discount after evaluation date update" << myDf.getDiscount() << std::endl;
}

//int main() {
//	//testingDesignPattern2();
//	//testingDesignPattern3();
//	testingDesignPattern2a();
//}