#pragma once
#include <iostream>
using namespace std;
class ComplexNumber
{
public:
	ComplexNumber(double realPart, double imaginaryPart);
	double getRealPart() const;
	double getImaginaryPart() const;
	void print() const;
private:
	double realPart_ = 0;
	double imaginaryPart_ = 0;
};

//iostream skal skrives som en fri funktion
ostream& operator<<(ostream&, const ComplexNumber&);
// Fri funktion af + operatoren
ComplexNumber operator+(const ComplexNumber& n1, const ComplexNumber& n2);