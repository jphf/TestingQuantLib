#include<boost/any.hpp>

#include<iostream>
#include<vector>
#include<string>
#include<map>

void callAny(boost::any x);

void AnyTesting1() {
	boost::any myVar;

	myVar = 1.1;
	myVar = std::string("1.1");
	myVar = std::vector<double>(3);

	double x = 1.1;
	callAny(x);
}

void callAny(boost::any x) {

}

void AnyTesting2() {
	boost::any myAny;
	double myDbl(1.1);

	myAny = myDbl;

	bool isDbl = myAny.type() == typeid(double);
	std::cout << "Is Double:" << isDbl << std::endl;
	bool isString = myAny.type() == typeid(std::string);
	std::cout << "Is String:" << isString << std::endl;

	double* ptrMyDbl = boost::any_cast<double>(&myAny);
	if (ptrMyDbl != NULL) std::cout << "My Double: " << *ptrMyDbl << std::endl;

	int* ptrMyInt = boost::any_cast<int>(&myAny);
	if (ptrMyInt == NULL) std::cout << "Cast Failed" << std::endl;
}

void AnyTesting3() {
	
	enum BarrierType{DownAndOut, UpAndIn, DownAndIn, UpAndOut};

	std::map<std::string, boost::any> myPropertySet;

	myPropertySet["domRate"] = 0.003;
	myPropertySet["forRate"] = 0.031;
	myPropertySet["Name"] = std::string("Barrier Option");
	myPropertySet["BarrType"] = BarrierType(DownAndIn);
	
}

//int main() {
//	//AnyTesting1();
//	//AnyTesting2();
//	AnyTesting3();
//}