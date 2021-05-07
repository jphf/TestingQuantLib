#include<ql/quantlib.hpp>
#include<ql/types.hpp>
#include<iostream>
#include<exception>

using namespace QuantLib;

Real myReciproke(Real x) {
	QL_REQUIRE(x != 0, "Zero");
	return 1 / x;
}

//int main() {
//	try {
//		Real x = 2.0;
//		std::cout << myReciproke(x) << std::endl;
//	}
//	catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	catch (...) {
//		std::cout << "unknown error" << std::endl;
//	}
//}