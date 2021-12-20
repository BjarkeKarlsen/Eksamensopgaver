#include "Feriebolig.h"
#include <math.h>
#include <iostream>
#include "../Juni2020.cpp"

using namespace std;


Feriebolig::Feriebolig(const Dato& koebsdato, int koebspris, int antalSengepladser)
{
    koebsdato_ = koebsdato;
    setKoebspris(koebspris);
    setAntalSengepladser(antalSengepladser);
}

Feriebolig::~Feriebolig()
{
}

Dato Feriebolig::getKoebsdato() const
{
    return koebsdato_;
}

void Feriebolig::setKoebsdato(const Dato& købsdato)
{
    koebsdato_ = købsdato;
}

int Feriebolig::getKoebspris() const
{
    return koebspris_;
}

void Feriebolig::setKoebspris(int købspris)
{
    koebspris_ = (købspris > 100000 ? købspris : 100000);
}

int Feriebolig::getAntalSengepladser() const
{
    return antalSengepladser_;
}

void Feriebolig::setAntalSengepladser(int antalSengepladser)
{
    antalSengepladser_ = (antalSengepladser > 0 ? antalSengepladser : 4);
}

void Feriebolig::print() const
{
    cout << antalSengepladser_ << " sovepladser" << endl;
    cout << "Sidst handlet " << koebsdato_ << endl;
    cout << "Pris " << koebspris_ << " kr" << endl;
}