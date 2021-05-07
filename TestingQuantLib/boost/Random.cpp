#include<boost/random.hpp>
#include<boost/foreach.hpp>
#include<boost/math/distributions.hpp>
#include<iostream>

void randomFunc1() {
	unsigned long seed = 12411;
	boost::mt19937 rng(seed);

	boost::uniform_int<> six(1, 6);

	boost::variate_generator<boost::mt19937&, boost::uniform_int<>> unsix(rng, six);

	std::cout << unsix() << std::endl;
	std::cout << unsix() << std::endl;
	std::cout << unsix() << std::endl;
}

void randomFunc2() {
	unsigned long seed = 89210;
	boost::lagged_fibonacci1279 rng(seed);

	boost::normal_distribution<> norm(10, 0.1);

	boost::variate_generator<boost::lagged_fibonacci1279&, boost::normal_distribution<>> unnorm(rng, norm);

	std::cout << unnorm() << std::endl;
	std::cout << unnorm() << std::endl;
	std::cout << unnorm() << std::endl;
}

void randomFunc3() {
	unsigned long seed = 12411;
	boost::mt19937 rng(seed);
	boost::cauchy_distribution<> cdist;
	boost::variate_generator<boost::mt19937&, boost::cauchy_distribution<>> cauchy(rng, cdist);

	std::cout << cauchy() << std::endl;
	std::cout << cauchy() << std::endl;
	std::cout << cauchy() << std::endl;

	rng.seed(seed);
	std::cout << "-------------" << std::endl;
	std::cout << cauchy() << std::endl;
	std::cout << cauchy() << std::endl;
	std::cout << cauchy() << std::endl;
}

void randomFunc4() {
	unsigned long seed = 24061;
	boost::mt19937 rng(seed);
	boost::uniform_on_sphere<double, std::vector<double>> myUn(5);
	boost::variate_generator<boost::mt19937&, boost::uniform_on_sphere<double, std::vector<double>>> unSphere(rng, myUn);
	std::vector<double> res = unSphere();

	BOOST_FOREACH(double x, res) std::cout << x << std::endl;
	double sum = 0;
	BOOST_FOREACH(double x, res) sum += x * x;
	std::cout << "---------" << std::endl;
	std::cout << "Vector Length:" << std::sqrt(sum) << std::endl;

}

void randomFunc5() {
	boost::math::uniform_distribution<> d1(0, 1);

	unsigned long seed = 1111;
	boost::mt19937 rng(seed);
	boost::uniform_real<> ur(0.0, 1.0);

	boost::variate_generator<boost::mt19937&, boost::uniform_real<>> unReal(rng, ur);

	std::cout << boost::math::quantile(d1, unReal()) << std::endl;
}

//void main() {
//	randomFunc1();
//	randomFunc2();
//	randomFunc3();
//	randomFunc4();
//	randomFunc5();
//}