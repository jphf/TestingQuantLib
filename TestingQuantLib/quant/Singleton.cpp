#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include<boost/optional/optional_io.hpp>
#include <vector>
#include<string>

#include<ql/types.hpp>

#include "ObjectRepository.h"
#include "MyOption.h"
#include "MakeMyOption.h"

std::ostream& operator<<(std::ostream& out, const ObjectRepository::Error& err) {
	if (err == ObjectRepository::NoError) {
		return out << " NoError ";
	}
	else if (err == ObjectRepository::CastingFailed) {
		return out << " CastingFailed ";
	}
	else if (err == ObjectRepository::IdNotDound) {
		return out << " IdNotFound ";
	}
	else {
		return out << " UnknownError ";
	}
}

void addVariable();

void testingSingleton1() {
	addVariable();

	std::string myStr1("myStr1");
	std::vector<int> myVec1(6, 2);

	ObjectRepository::instance().addObject("str1", myStr1);
	ObjectRepository::instance().addObject("vec1", myVec1);

	std::string myDbId("dbl1");

	ObjectRepository::Error myErr;

	boost::optional<double> myDblGet = ObjectRepository::instance().getObject<double>(myDbId, myErr);

	std::cout << "Object exist?:" << ObjectRepository::instance().objectExists(myDbId) << std::endl;
	std::cout << "getObject double return: " << myDblGet << std::endl;
	std::cout << "dereferenced double return: " << *myDblGet << std::endl;
	std::cout << "Error: " << myErr << std::endl;
	std::cout << "--------------------------" << std::endl;

	boost::optional<std::vector<int>> myVecGet = ObjectRepository::instance().getObject<std::vector<int>>("vec1");

	//std::cout << "getObject vector return: " << myVecGet << std::endl;

	BOOST_FOREACH(int x, *myVecGet) std::cout << x << std::endl;
}



void testingSingleton2() {
	try {
		addVariable();

		double myDbl2 = 4.144, myDbl3 = 3.122;
		std::string myStr1("myStr1"), myStr2("myStr2");
		std::vector<int> myVec1(6, 2), myVec2(10, 1), myVec3(2, 2), myVec4(4, 1);

		ObjectRepository::instance().addObject("dbl2", myDbl2);
		ObjectRepository::instance().addObject("dbl3", myDbl3);

		ObjectRepository::instance().addObject("str1", myStr1);
		ObjectRepository::instance().addObject("str2", myStr2);

		ObjectRepository::instance().addObject("vec1", myVec1);
		ObjectRepository::instance().addObject("vec2", myVec2);
		ObjectRepository::instance().addObject("vec3", myVec3);
		ObjectRepository::instance().addObject("vec4", myVec4);

		std::cout << "Number Objects:" << ObjectRepository::instance().numberObjects() << std::endl;
		std::cout << "Number Doubles:" << ObjectRepository::instance().getObjectCount<double>() << std::endl;
		std::cout << "Number Strings:" << ObjectRepository::instance().getObjectCount<std::string>() << std::endl;
		std::cout << "Number vectors:" << ObjectRepository::instance().getObjectCount<std::vector<int>>() << std::endl;
		std::cout << "---------------------" << std::endl;

		std::string myDblId("dbl1");
		ObjectRepository::Error err;

		boost::optional<double> myDblGet = ObjectRepository::instance().getObject<double>(myDblId, err);

		std::cout << " Object exist?: " << ObjectRepository::instance().objectExists(myDblId) << std::endl;
		std::cout << " getObject double return: " << myDblGet << std::endl;
		std::cout << " dereferenced double return: " << *myDblGet << std::endl;
		std::cout << " Error: " << err << std::endl;
		std::cout << "---------------------" << std::endl;
		
		ObjectRepository::instance().deleteObject(myDblId);
		myDblGet = ObjectRepository::instance().getObject<double>(myDblId, err);
		std::cout << " Object exist?: " << ObjectRepository::instance().objectExists(myDblId) << std::endl;
		std::cout << " getObject after delete return: " << myDblGet << std::endl;
		std::cout << " Error: " << err << std::endl;
		std::cout << "---------------------" << std::endl;

		double myDbl1 = 2.123;
		ObjectRepository::instance().addObject(myDblId, myDbl1);
		boost::optional<std::string> wrongTypeGet = ObjectRepository::instance().getObject<std::string>(myDblId, err);
		std::cout << " getObject wrong type return : " << wrongTypeGet << std::endl;
		std::cout << " Error: " << err << std::endl;
		std::cout << "---------------------" << std::endl;

		boost::optional<double> wrongDblType = ObjectRepository::instance().getObject<double>("myDblFalse", err);
		std::cout << " getObject wrong id return : " << wrongDblType << std::endl;
		std::cout << " Error: " << err << std::endl;
		std::cout << "---------------------" << std::endl;

		boost::optional<std::vector<int>> myVecGet = ObjectRepository::instance().getObject<std::vector<int>>("vec1", err);
		//std::cout << " getObject vector return : " << myVecGet << std::endl;
		std::cout << " Error: " << err << std::endl;
		BOOST_FOREACH(int x, *myVecGet) std::cout << x << std::endl;


	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << " unknown error " << std::endl;
	}
}

void addVariable() {
	double myDbl1 = 2.123;
	ObjectRepository::instance().addObject("dbl1", myDbl1);
}

void addOption1() {
	QuantLib::Real spot = 100.0, strike = 110.0;
	QuantLib::Rate rd = 0.03, rf = 0.01;
	QuantLib::Volatility vol = 0.20;
	QuantLib::Time mat = 1.0;
	MyOption::Type type(MyOption::Call);

	MyOption optionMade = MakeMyOption()
		.withType(type)
		.withMat(mat)
		.withSpot(spot)
		.withForRate(rf)
		.withStrike(strike)
		.withVol(vol)
		.withDomRate(rd);
	ObjectRepository::instance().addObject("option1", optionMade);
}

void addOption2() {
	QuantLib::Real spot = 100.0, strike = 110.0;
	QuantLib::Rate rd = 0.03, rf = 0.01;
	QuantLib::Volatility vol = 0.20;
	QuantLib::Time mat = 1.0;
	MyOption::Type type(MyOption::Call);

	MyOption optionMade = MakeMyOption()
		.withType(type)
		.withMat(mat)
		.withSpot(spot)
		.withForRate(rf)
		.withStrike(strike)
		.withVol(vol)
		.withDomRate(rd);
	ObjectRepository::instance().addObject("option2", optionMade);
}

void testingSingleton3() {
	addOption1();
	addOption2();

	ObjectRepository::Error err;
	boost::optional<MyOption> myOptionGet = ObjectRepository::instance().getObject<MyOption>("option1", err);
	std::cout << err << std::endl;
	std::cout << (*myOptionGet).getMat() << std::endl;
	std::cout << (*myOptionGet).getSpot() << std::endl;
	std::cout << (*myOptionGet).getStrike() << std::endl;
}

//int main() {
//	//testingSingleton1();
//	//testingSingleton2();
//
//	testingSingleton3();
//}