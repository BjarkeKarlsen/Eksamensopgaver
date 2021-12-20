#include "Kasse.h"

// I denne fil skal du tilf�je kode for at svare p� Opgave 1.B, 1.C og 1.F
Kasse::Kasse(double lengde, double bredde, double hojde) {
	setLengde(lengde);
	setBredde(bredde);
	setHojde(hojde);
}

double Kasse::getLengde() const
{
	return lengde_;
}

double Kasse::getBredde() const
{
	return bredde_;
}

double Kasse::getHojde() const
{
	return hojde_;
}

void Kasse::setLengde(double l)
{
	lengde_ = (l > 0.0) ? l : 10.0;
}

void Kasse::setBredde(double b)
{
	bredde_ = (b > 0.0) ? b : 10.0;
}

void Kasse::setHojde(double h)
{
	hojde_ = (h > 0.0) ? h : 10.0;
}

double Kasse::beregnVolumen() const
{
	return (lengde_ * bredde_ * hojde_)/1000.0;
}

ostream& operator<<(ostream& os, const Kasse& kasse)
{
	os << "Kasse med laendgde " << kasse.getLengde() << " cm ,";
	os << "bredde " << kasse.getBredde()<< " cm, hoejde " << kasse.getHojde() << " cm" << endl;
	os << "og volumen " << kasse.beregnVolumen() << " liter" << endl;
	return os;
}

bool operator<(const Kasse& kasse1, const Kasse& kasse2)
{
	if (kasse1.beregnVolumen() < kasse2.beregnVolumen()) {
		return true;
	}

	return false;
}

bool operator>(const Kasse& kasse1, const Kasse& kasse2)
{
	return (kasse1.beregnVolumen() > kasse2.beregnVolumen() ? true : false);
}
