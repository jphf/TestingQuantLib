#include<boost/math/distributions.hpp>
#include<iostream>

using namespace std;

void distributionFunc1() {

	boost::math::normal_distribution<> d(0.5, 1);

	cout << "CDF:" << cdf(d, 0.2) << endl;
	cout << "PDF:" << pdf(d, 0.0) << endl;
	cout << "Inverse:" << quantile(d, 0.1) << endl;
	cout << "Mode:" << mode(d) << endl;
	cout << "Variance:" << variance(d) << endl;
	cout << "SD:" << boost::math::standard_deviation(d) << endl;
	cout << "Skew:" << boost::math::skewness(d) << endl;
	cout << "Kurtosis:" << boost::math::kurtosis(d) << endl;
	cout << "Excess Kurt:" << boost::math::kurtosis_excess(d) << endl;

	std::pair<double, double> sup = boost::math::support(d);
	cout << "Left Sup:" << sup.first << endl;
	cout << "Right Sup:" << sup.second << endl;

}

void distributionFunc2() {
	double leftBound = 0.0, rightBound = 2.0;
	boost::math::uniform_distribution<> d1(leftBound, rightBound);

	double numTrials = 10, probTrail = 0.2;
	boost::math::binomial_distribution<> d2(numTrials, probTrail);

	double degFreedom = 20;
	boost::math::students_t_distribution<> d3(degFreedom);
	boost::math::chi_squared_distribution<> d4(degFreedom);

	double mean = 0.0, var = 0.20;
	boost::math::lognormal_distribution<> d5(mean, var);
	boost::math::cauchy_distribution<> d6(mean, var);

	double degFreedom1 = 20, degFreedom2 = 35;
	boost::math::fisher_f_distribution<> d7(degFreedom1, degFreedom2);

	double nonCentPar = 0.2;
	boost::math::non_central_chi_squared_distribution<> d8(degFreedom1, nonCentPar);

	double arrivRate = 0.2;
	boost::math::poisson_distribution<> d9(arrivRate);
	boost::math::exponential_distribution<> d10(arrivRate);
}

//int main() {
//	distributionFunc2();
//}