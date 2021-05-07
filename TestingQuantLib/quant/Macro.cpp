#include<ql/quantlib.hpp>
#include<ql/errors.hpp>
#include<iostream>
#include<exception>
#include<tchar.h>

using namespace QuantLib;

void testingMacro1() {
	double x = 0.0;
	QL_REQUIRE(x != 0, "Zero number!");
}

void testingMacro2() {
	QL_FAIL("Failed!");
}

//int _tmain(int argc, _TCHAR* argv[]) {
//	try {
//		//testingMacro1();
//		testingMacro2();
//	}
//	catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//		return 1;
//	}
//	catch (...) {
//		std::cout << "unknown error" << std::endl;
//		return 1;
//	}
//	return 0;
//}