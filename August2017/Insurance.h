#pragma once
#include <string>
using namespace std;
class Insurance
{
public:
	Insurance(string, double, int);
	double getStandardPrice() const;
	int getDeductible() const;
	virtual double calculatePrice() const = 0;
	virtual void print() const;

protected:
	string policynumber_;

private:
	double standardPrice_;
	int deductible_;
};