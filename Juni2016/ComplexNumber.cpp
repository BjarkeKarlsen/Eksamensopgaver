#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realPart, double imaginaryPart)
{
	realPart_ = realPart;
	imaginaryPart_ = imaginaryPart;
}

double ComplexNumber::getRealPart() const
{
	return realPart_;
}

double ComplexNumber::getImaginaryPart() const
{
	return imaginaryPart_;
}

void ComplexNumber::print() const
{
	cout << realPart_;
	if (imaginaryPart_ < 0)
		cout << " - j" << -imaginaryPart_;
	else
		cout << " + j" << imaginaryPart_;
}

ostream& operator<<(ostream& os, const ComplexNumber& n)
{
	n.print(); //kalder public print metoden 
	return os; //returnerer output
}
ComplexNumber operator+(const ComplexNumber& n1, const ComplexNumber& n2)
{

	return ComplexNumber(n1.getRealPart() + n2.getRealPart(), n1.getImaginaryPart() + n2.getImaginaryPart());
}

