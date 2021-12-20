#include "Insurance.h"
#include <iostream>

Insurance::Insurance(string policy, double standardprice, int deductible)
{
	policynumber_ = policy;
	standardPrice_ = (standardprice >= 500 ? standardprice : 500);
	deductible_ = (deductible <= 0 && deductible <= 5000 ? deductible : 5000);
}

double Insurance::getStandardPrice() const
{
	return standardPrice_;
}
int Insurance::getDeductible() const
{
	return deductible_;
}
double Insurance::calculatePrice() const
{
	return 0.0;
}
void Insurance::print() const
{
	cout << "Policenummer " << policynumber_ << endl;
	cout << "Selvrisiko " << deductible_ << " kr" << endl;
}