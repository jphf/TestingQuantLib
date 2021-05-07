#include<boost/shared_ptr.hpp>
#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<boost/math/distributions.hpp>
#include<iostream>

double indicatorFunc(const double& x, const double& a, const double& b) {
	if (x >= a && x <= b) return 1.0;
	else return 0.0;
}

void testingBind1() {
	double a = -1.0, b = 1.0;

	boost::function<double(double)> ind;
	ind = boost::bind(indicatorFunc, _1, a, b);

	std::cout << ind(2.0) << std::endl;
	std::cout << ind(0.5) << std::endl;
}

void testingBind2() {
	double x = 1.01, a = -1.0, b = 1.0;

	std::cout << "Original Function:" << indicatorFunc(x, a, b) << std::endl;
	boost::function<double(double, double, double)> indRecordered;
	indRecordered = boost::bind(indicatorFunc, _3, _1, _2);
	std::cout << "Recordered Arguments:" << indRecordered(a, b, x) << std::endl;
}

class NormalClass {
public:
	NormalClass() {}
	double normalPdf(const double& x, const double& mean, const double& std) {
		boost::math::normal_distribution<> d(mean, std);
		return pdf(d, x);
	}
	double normalCdf(const double& x, const double& mean, const double& std) {
		boost::math::normal_distribution<> d(mean, std);
		return cdf(d, x);
	}
};

void testingBind3() {
	boost::function<double(double)> stdNd, stdNcumm;
	NormalClass nc;
	stdNd = boost::bind(&NormalClass::normalPdf, &nc, _1, 0.0, 1.0);
	stdNcumm = boost::bind(&NormalClass::normalCdf, &nc, _1, 0.0, 1.0);

	std::cout << stdNd(1.1) << std::endl;
	std::cout << stdNcumm(0.0) << std::endl;
}

//int main() {
//	//testingBind1();
//	//testingBind2();
//	testingBind3();
//}