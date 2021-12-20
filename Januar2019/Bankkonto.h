#pragma once
#include "Transaktion.h"
#include <vector>

class Bankkonto
{
public:
	Bankkonto(std::string);
	Bankkonto& indsaetTransaktion(const Transaktion&);
	void printKontoUdskrift() const;

private: 
	std::string ejer_;
	double saldo_;
	std::vector<Transaktion> transaktioner_;


};

