#pragma once
#include <iostream>
#include <string>
//using namespace std;
class Transaktion
{
public:
	Transaktion(std::string tekst, double beloeb);
	double getBeloeb() const;
	std::string getTekst() const;
private:
	std::string tekst_;
	double beloeb_;
};

std::ostream& operator<<(std::ostream&, const Transaktion&);
