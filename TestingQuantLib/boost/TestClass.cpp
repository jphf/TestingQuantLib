#include<boost/shared_ptr.hpp>
#include<boost/foreach.hpp>
#include<vector>
#include "TestClassA.h"

void testSharedPtra() {
	A* ptr_myA = new A(1.0);
	delete ptr_myA;
}

void testSharedPtrc() {
	boost::shared_ptr<A> bptr_myA(new A(1.0));
}

void testSharedPtrd() {
	A* ptr_myA = new A(1.0);
	boost::shared_ptr<A> bptr_myA(ptr_myA);
	std::cout << bptr_myA->getValue() << std::endl;
}

void testSharedPtrg() {
	boost::shared_ptr<A> bptr_myA(new A(1.0));
	bptr_myA.reset(new A(2.0));
}

void testSharedPtrh() {

	std::vector<double>* v = new std::vector<double>(100);
	boost::shared_ptr<std::vector<double>> ptr(v);
	for (int i = 0; i < 100; i++) {
		(*ptr)[i] = i;
	}

	double sum = 0;
	BOOST_FOREACH(double x, *ptr) sum += x;

	std::cout << sum << std::endl;
}

//int main() {
//	//testSharedPtra();
//
//	//testSharedPtrc();
//
//	//testSharedPtrd();
//
//	//testSharedPtrg();
//
//	testSharedPtrh();
//}