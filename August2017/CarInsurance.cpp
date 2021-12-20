#include "CarInsurance.h"
#include <iostream>
CarInsurance::CarInsurance(string policy, double standardprice, int deductible, int kmperyear)
	: Insurance(policy, standardprice, deductible)
{
	kmPerYear_ = kmperyear >= 10000 ? kmperyear : 10000;

}
double CarInsurance::calculatePrice() const
{
	return (getStandardPrice() - getDeductible() * 0.2 + (kmPerYear_ -
		10000) * 0.1);
}
void CarInsurance::print() const
{
	cout << "Bilforsikring " << endl;
	Insurance::print();
	cout << "K\x9Brsel pr. \x86r " << kmPerYear_ << " km" << endl;
	cout << "Pris " << calculatePrice() << " kr" << endl;
}

