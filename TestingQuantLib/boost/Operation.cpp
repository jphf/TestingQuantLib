#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/io.hpp>
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/symmetric.hpp>
#include<boost/numeric/ublas/matrix_proxy.hpp>
#include<boost/numeric/ublas/vector_proxy.hpp>
#include<boost/numeric/ublas/lu.hpp>

using namespace boost::numeric::ublas;

void vecOperation1() {
	vector<double> myVec(3, 2.2);
	myVec[2] = -5.1;

	std::cout << myVec << std::endl;
	std::cout << sum(myVec) << std::endl;
	std::cout << norm_1(myVec) << std::endl;
	std::cout << norm_2(myVec) << std::endl;
	std::cout << norm_inf(myVec) << std::endl;
	std::cout << index_norm_inf(myVec) << std::endl;
}

void vecOperation2() {
	vector<double> myVec1(3, 2.2); myVec1[2] = -5.1;
	vector<double> myVec2(3, -1.2);myVec2[2] = 1.1;

	double multiplier = 2.0;

	std::cout << myVec1.size() << std::endl;
	std::cout << myVec1 << std::endl;
	std::cout << myVec2 << std::endl;
	std::cout << inner_prod(myVec1, myVec2) << std::endl;
	std::cout << myVec1 + myVec1 << std::endl;
	std::cout << myVec1 - myVec1 << std::endl;
	std::cout << myVec1 * multiplier << std::endl;
	std::cout << myVec1 / multiplier << std::endl;
}

void matrixOperation1() {
	matrix<double> myMat(3, 3, 2.5);
	myMat(0.0) = myMat(2, 2) = 1.0;
	myMat(0, 2) = -3.6;
	myMat(2, 0) = 5.9;

	std::cout << "My Mat:" << myMat << std::endl;
	std::cout << "Num Rows:" << myMat.size1() << std::endl;
	std::cout << "Num Cols:" << myMat.size2() << std::endl;
	std::cout << "My Mat Transp:" << trans(myMat) << std::endl;
	std::cout << "My Mat Real Part:" << real(myMat) << std::endl;
	myMat.resize(4, 4);
	std::cout << "My Resized Mat:" << myMat << std::endl;
}

void matrixOperation2() {
	symmetric_matrix<double, upper> myCorrMat(3);
	myCorrMat(0, 0) = myCorrMat(1, 1) = myCorrMat(2, 2) = 1.0;
	myCorrMat(0, 1) = 0.4;
	myCorrMat(0, 2) = -0.6;
	myCorrMat(1, 2) = 0.1;
	std::cout << "Initial Mat:" << myCorrMat << std::endl;

	double multipler = 0.5;
	symmetric_matrix<double, upper> myCorrMat1 = myCorrMat;
	std::cout << "Sum Mat:" << myCorrMat1 + myCorrMat << std::endl;
	std::cout << "Scalar Mult:" << myCorrMat1 * multipler << std::endl;
	std::cout << "Scalar Dev:" << myCorrMat1 / multipler << std::endl;
}

void matrixOperation3() {
	matrix<double> myMat(3, 3, 2.5);
	myMat(0, 0) = myMat(2, 2) = 1.0;
	myMat(0, 2) = -3.6;
	myMat(2, 0) = 5.9;

	matrix_row<matrix<double>> mr(myMat, 2);
	matrix_column<matrix<double>> mc(myMat, 2);

	std::cout << "Mat:" << myMat << std::endl;
	std::cout << "Row:" << mr << std::endl;
	std::cout << "Col:" << mc << std::endl;
}

void matrixOperation4() {
	matrix<double> myMat(3, 3, 2.5);
	myMat(0, 0) = myMat(2, 2) = 1.0;
	myMat(0, 2) = -3.6;
	myMat(2, 0) = 5.9;

	vector<double> myVec(3, 2.0);
	std::cout << prod(myMat, myMat) << std::endl;
	std::cout << prod(myMat, myVec) << std::endl;
}

void matrixOperation5() {
	matrix<double> A(3, 3, -0.5);
	A(0, 0) = A(2, 2) = 1.8;
	A(0, 2) = -2.6;
	A(2, 0) = 1.9;

	vector<double> b(3, 0.4);
	b(0) = -0.3;

	matrix<double> A1 = A;
	vector<double> x = b;

	permutation_matrix<double> P1(A1.size1());

	lu_factorize(A1, P1);
	lu_substitute(A1, P1, x);

	std::cout << "x=" << x << std::endl;
	std::cout << "A*x=" << prod(A, x) << std::endl;
	std::cout << "b=" << b << std::endl;

}

//int main() {
//	//vecOperation1();
//	//vecOperation2();
//	//matrixOperation1();
//	//matrixOperation2();
//	//matrixOperation3();
//	//matrixOperation4();
//	matrixOperation5();
//	return 0;
//}