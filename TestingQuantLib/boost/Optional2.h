#pragma once
#include<boost/date_time/gregorian/gregorian.hpp>
#include<boost/optional.hpp>

class SimpleSettlementClass {
private:
	boost::gregorian::date d_;
	boost::optional<int> settlementDays_;
public:
	SimpleSettlementClass(const boost::gregorian::date& d) :d_(d) {

	}

	SimpleSettlementClass(const boost::gregorian::date& d, const int& settlementDays) :d_(d), settlementDays_(settlementDays) {

	}

	boost::gregorian::date settlement() const {
		if (settlementDays_) {
			return d_ + boost::gregorian::days(*settlementDays_);
		}
		else {
			return d_;
		}
	}

	int settlementDays() const {
		if (settlementDays_) {
			return *settlementDays_;
		}
		else {
			return 0;
		}
	}
};
