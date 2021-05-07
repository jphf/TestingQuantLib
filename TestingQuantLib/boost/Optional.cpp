#include<boost/optional.hpp>
#include<boost/optional/optional_io.hpp>

#include<iostream>

#include "Optional2.h"

void testingOptional1() {
	boost::optional<double> myOpt1;
	double b = 1.1;
	boost::optional<double> myOpt2(b);

	std::cout << myOpt1 << std::endl;
	std::cout << myOpt2 << std::endl;

	if (myOpt1 == boost::none) {
		std::cout << "Empty Object" << std::endl;
	}
	else {
		std::cout << *myOpt1 << std::endl;
	}

	if (myOpt2 == boost::none) {
		std::cout << "Empty Object" << std::endl;
	}
	else {
		std::cout << myOpt2.get() << std::endl;
	}
}

void testingOptional2() {
	boost::gregorian::date d1(2009, 9, 20);

	SimpleSettlementClass settlement1(d1);
	SimpleSettlementClass settlement2(d1, 3);

	std::cout << "Settlement 1: " << settlement1.settlement() << std::endl;
	std::cout << "Settlement 2: " << settlement2.settlement() << std::endl;
	std::cout << "Settlement 1 Days: " << settlement1.settlementDays() << std::endl;
	std::cout << "settlement 2 Days: " << settlement2.settlementDays() << std::endl;

}

//int main() {
//	//testingOptional1();
//	testingOptional2();
//}