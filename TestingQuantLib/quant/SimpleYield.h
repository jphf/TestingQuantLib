#pragma once
#include<ql/quantlib.hpp>
#include<boost/shared_ptr.hpp>

using namespace QuantLib;

class SimpleYield :
	public Observable
{
private:
	Rate yield_;
public:
	SimpleYield(const Rate& yield) :yield_(yield) {

	}
	Rate getYield() const { return yield_; }

	void setYield(const Rate& yield) {
		yield_ = yield;
		notifyObservers();
	}
};

class SimpleDiscountFactor : public Observable, Observer {
private:
	DiscountFactor df_;
	Time mat_;
	boost::shared_ptr<SimpleYield> y_;
public:
	SimpleDiscountFactor(const boost::shared_ptr<SimpleYield>& y, Time& mat) :y_(y), mat_(mat) {
		registerWith(y_);
		df_ = exp(-y_->getYield() * mat_);
	}
	void update() {
		df_ = exp(-y_->getYield() * mat_);
		notifyObservers();
	}
	Real getDiscount() const {
		return df_;
	}
};

class SimpleDiscountedCF :public Observer {
private:
	boost::shared_ptr<SimpleDiscountFactor> df_;
	Real discountedUnit_;
public:
	SimpleDiscountedCF(const boost::shared_ptr<SimpleDiscountFactor>& df) : df_(df) {
		discountedUnit_ = df_->getDiscount();
		registerWith(df_);
	}
	void update() {
		discountedUnit_ = df_->getDiscount();
	}
	Real discountCashFlow(const Real& amount) const {
		return discountedUnit_ * amount;
	}
};

class SimpleDiscountFactor1 : public Observable, Observer {
private:
	DiscountFactor df_;
	Date evalDate_, matDate_;
	boost::shared_ptr<SimpleYield> y_;
	DayCounter dc_;
public:
	SimpleDiscountFactor1(const boost::shared_ptr<SimpleYield>& y, const Date& matDate, const DayCounter& dc)
		:y_(y), matDate_(matDate), dc_(dc) {
		evalDate_ = Settings::instance().evaluationDate();
		registerWith(y_);
		registerWith(Settings::instance().evaluationDate());
		df_ = exp(-y_->getYield() * dc_.yearFraction(evalDate_, matDate_));
	}
	void update() {
		evalDate_ = Settings::instance().evaluationDate();
		df_ = exp(-y_->getYield() * dc_.yearFraction(evalDate_, matDate_));
		notifyObservers();
	}
	Real getDiscount() const {
		return df_;
	}
};

class SimpleDiscountFactor2 : public Observable, Observer {
private:
	DiscountFactor df_;
	Time mat_;
	Handle<SimpleYield> y_;

public:
	SimpleDiscountFactor2(const Handle<SimpleYield>& y, Time& mat) :y_(y), mat_(mat) {
		registerWith(y_);
		df_ = exp(-(*y_)->getYield() * mat_);
	}
	void update() {
		df_ = exp(-(*y_)->getYield() * mat_);
		notifyObservers();
	}
	Real getDiscount() const {
		return df_;
	}
};