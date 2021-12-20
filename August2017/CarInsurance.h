#pragma once
#include "Insurance.h"

class CarInsurance : public Insurance
{
public:
	CarInsurance(string, double, int, int);
	virtual double calculatePrice() const;
	virtual void print() const;
private:
	int kmPerYear_;
};