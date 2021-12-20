#include "Transaktion.h"

Transaktion::Transaktion(std::string tekst, double beloeb)
{
	tekst_ = tekst;
	beloeb_ = beloeb;
}
double Transaktion::getBeloeb() const
{
	return beloeb_;
}
std::string Transaktion::getTekst() const
{
	return tekst_;
}

std::ostream& operator<<(std::ostream& os, const Transaktion& transaktion)
{
	os << transaktion.getTekst() << " " << transaktion.getBeloeb() << std::endl;
	return os;
}
