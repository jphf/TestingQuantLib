#include<boost/archive/text_oarchive.hpp>
#include<boost/archive/binary_oarchive.hpp>
#include<boost/serialization/vector.hpp>
#include<boost/foreach.hpp>
#include<boost/function.hpp>
#include<boost/bind.hpp>
#include<boost/random.hpp>
#include<fstream>
#include<ostream>
#include<sstream>
#include<boost/timer.hpp>
#include<boost/archive/binary_iarchive.hpp>
#include "Serialization3.h"
#include "serialization4.h"


void testingSerialization1() {
	boost::timer t;

	unsigned long seed = 89210;
	std::stringstream stream; stream << seed;
	std::string filename("F:\\tmp\\");
	filename += "normal_mt_" + stream.str() + ".bin";

	std::ofstream ostr(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive oa(ostr);

	boost::mt19937 rng(seed);
	boost::normal_distribution<> norm;
	boost::variate_generator<boost::mt19937&, boost::normal_distribution<>> normGen(rng, norm);

	int numVars = 5000000;
	std::vector<double> myVec(numVars);
	BOOST_FOREACH(double& x, myVec) x = normGen();
	oa << myVec;
	ostr.close();
	std::cout << "Elapsed time:" << t.elapsed() << std::endl;
}

void testingSerialization2() {
	boost::timer t;
	std::string filename("F:\\tmp\\");
	filename += "normal_mt_89210.bin";

	std::ifstream istr(filename.c_str(), std::ios::binary);

	std::vector<double> myVecLoaded;
	boost::archive::binary_iarchive ia(istr);
	ia >> myVecLoaded;
	istr.close();

	for (int i = 0; i < 10; i++) std::cout << myVecLoaded[i] << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Elapsed:" << t.elapsed() << std::endl;
}

void testingSerialization3() {
	unsigned long numSims = 1000000, seed = 20424;
	double spot = 100.0, strike = 102.0, rd = 0.02, rf = 0.03, vol = 0.124, tau = 1.0;

	boost::function<double(double)> pathGen, discountedPayoff;
	pathGen = boost::bind(gbmPath, spot, rd, rf, vol, tau, _1);
	discountedPayoff = boost::bind(discountedCallPayoff, _1, strike, rd, tau);
	SimpleGenericMonteCarloClass mc(numSims, seed);

	mc.performSimulation(pathGen, discountedPayoff);

	std::string filenameTxt("F:\\tmp\\monteCarloTest.txt");
	std::string filenameBin("F:\\tmp\\monteCarloTest.bin");

	std::ofstream ostrTxt(filenameTxt.c_str());
	std::ofstream ostrBin(filenameBin.c_str(), std::ios::binary);

	boost::archive::text_oarchive oaTxt(ostrTxt);
	boost::archive::binary_oarchive oaBin(ostrBin);

	oaTxt << mc;
	oaBin << mc;

	ostrTxt.close();
	ostrBin.close();
}

void testingSerialization4() {
	std::string filenameBin("F:\\tmp\\monteCarloTest.bin");
	std::ifstream istrBin(filenameBin.c_str(), std::ios::binary);
	boost::archive::binary_iarchive iaBin(istrBin);

	SimpleGenericMonteCarloClass mc;

	iaBin >> mc;

	istrBin.close();

	std::cout << "Mean Old (Call):" << mc.getMean() << std::endl;

	double spot = 100.0, strike = 102.0, rd = 0.02, tau = 1.0, rf = 0.03, vol = 0.124;
	boost::function<double (double)> discountedPayoff, pathGen;

	discountedPayoff = boost::bind(discountedPutPayoff, _1, strike, rd, tau);
	pathGen = boost::bind(gbmPath, spot, rd, rf, vol, tau, _1);

	mc.performSimulation(pathGen, discountedPayoff);
	std::cout << "Mean New (Put):" << mc.getMean() << std::endl;
}

//int main() {
//	//testingSerialization1();
//	//testingSerialization2();
//
//	//testingSerialization3();
//
//	// not work
//	testingSerialization4();
//}