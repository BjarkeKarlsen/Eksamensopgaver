#include "Flyttebil.h"

Flyttebil::Flyttebil(int kapacitet)
	: kapacitet_(kapacitet >= 10 && kapacitet <= 40 ? kapacitet : 10)
{
}

int Flyttebil::beregnAntalFlyttekasser(const Flyttekasse& flyttekasse) const
{
	return (kapacitet_/(flyttekasse.beregnVolumen()/1000));
}

void Flyttebil::fyldTomFlyttebil(const Flyttekasse& flyttekasse, int antal)
{
	int maxAntal = beregnAntalFlyttekasser(flyttekasse);
	
	if (indhold_.empty() && antal <= maxAntal) {
		for (int i = 0; i < antal; i++) {
			indhold_.push_back(&flyttekasse);
		}
	}
	else {
		cout << "Flyttebilen er tom eller der er ikkke plads til " << antal << " flyttekasser.";
		cout << "Der fyldes ingen flyttekasser i flyttebilen." << endl;
	}
	cout << "Der er nu " << indhold_.size() << " flyttekasser i flyttebilen." << endl;
}

void Flyttebil::tomFlyttebil()
{
	indhold_.clear();
	cout << "Flyttebilen er tom" << endl;
}

Flyttebil& Flyttebil::operator+=(const Flyttekasse& kasse)
{
	if (indhold_.size() <= beregnAntalFlyttekasser(kasse)) {
		indhold_.push_back(&kasse);
	}
	else {
		cout << "Der er ikke plads til flere flyttekasser i flyttebilen" << endl;
	}
	cout << "Der er nu " << indhold_.size() << " flyttekasser i flyttebilen." << endl;

	return *this;
}
