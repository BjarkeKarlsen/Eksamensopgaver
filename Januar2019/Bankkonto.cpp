#include "Bankkonto.h"

Bankkonto::Bankkonto(std::string ejer)
	: ejer_(ejer)
{
}

Bankkonto& Bankkonto::indsaetTransaktion(const Transaktion& transaktion)
{
	transaktioner_.push_back(transaktion);
	saldo_ += transaktion.getBeloeb();

	return *this;
}

void Bankkonto::printKontoUdskrift() const
{
	std::cout << "Bankkonto med ejer " << ejer_ << std::endl;
	std::cout << "Saldo: " << saldo_ << std::endl;
	for (auto i = transaktioner_.begin(); i != transaktioner_.end(); i++) {
		std::cout << (*i);
	}
}
