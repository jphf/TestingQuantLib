#pragma once
#include<algorithm>
#include<cmath>

double gbmPath(double spot, double rd, double rf, double vol, double tau, double rn) {
	double res = spot * std::exp((rd - rf - 0.5 * vol * vol) * tau + vol * std::sqrt(tau) * rn);
	return res;
}

double discountedCallPayoff(double assetValue, double strike, double rd, double tau) {
	double res = std::max(assetValue - strike, 0.0) * std::exp(-rd * tau);
	return res;
}

double discountedPutPayoff(double assetValue, double strike, double rd, double tau) {
	double res = std::max(strike - assetValue, 0.0) * std::exp(-rd * tau);
	return res;
}