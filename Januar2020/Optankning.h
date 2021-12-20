#pragma once

#include "Braendstof.h"

// Denne fil skal du tilrette for at svare p� Opgave 2.G

class Optankning
{
public:
	Optankning(double liter, double kilometer, Braendstof* );
	void printInformation() const;

private:
	Braendstof* braendstofPtr_;
	double antalLiter_;
	double antalKilometer_;
};


