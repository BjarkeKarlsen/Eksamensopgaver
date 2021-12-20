#include "Ejer.h"

Ejer::Ejer(char* navn, Ejerbolig* bolig)
{
	setNavn(navn);
	boligPtr_ = bolig;
}


Ejer::Ejer(const Ejer&)
{
}

Ejer::~Ejer()
{
	delete[] navnPtr_;
}

void Ejer::setNavn(char* nytnavn)
{
	delete[] navnPtr_;
	navnPtr_ = new char[strlen(nytnavn) + 1];
	strcpy(navnPtr_, nytnavn);

}

void Ejer::printEjer() const
{
	cout << endl << navnPtr_ << endl;
	boligPtr_->printBolig();
}




