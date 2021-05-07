#pragma once
#include<iostream>

class A
{
public:
	A(const double& myValue);
	~A();

	double getValue() const;
private:
	double myValue_;
};

A::A(const double& myValue) :myValue_(myValue)
{
	std::cout << "Constructor of A" << std::endl;
}

A::~A()
{
	std::cout << "Destructor of A with value " << myValue_ << std::endl;
}

double A::getValue() const{
	return myValue_;
}