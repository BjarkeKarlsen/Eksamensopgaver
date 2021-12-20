#include "Sommerhus.h"

Sommerhus::Sommerhus(const char* name, int areal, float afstandTilStrand, const Dato& koebsdato, int koebspris, int antalSengepladser)
    : Feriebolig(koebsdato, koebspris, antalSengepladser), afstandTilStrand_(afstandTilStrand > 0 ? afstandTilStrand : 0.0)
{
    setAreal(areal);
    navn_ = new char[strlen(name) + 1];
    strcpy_s(navn_, strlen(name) + 1, name);
}

void Sommerhus::setAreal(int areal)
{
    areal_ = (areal <= 25 ? areal : 25);
}

void Sommerhus::setNavn(const char* name)
{
    if (strlen(name) != strlen(navn_)) {
        delete[] navn_;
        navn_ = new char[strlen(name) + 1];
    }
    strcpy_s(navn_, strlen(name) + 1, name);
}

int Sommerhus::beregnAfgivt() const
{
    return (areal_*95);
}

void Sommerhus::print() const
{
    cout << navn_ << endl;
    cout << areal_ << "m2" << endl;
    cout << "Nærmeste strand: " << afstandTilStrand_ << " km" << endl;
    cout << getAntalSengepladser() << "sovepladser" << endl;
    cout << "Sidst handlet " << getKoebsdato() << endl;
    cout << "Pris " << getKoebspris() << endl;
    cout << "Ejendomsskat " << beregnAfgivt() << "kr. pr år" << endl;
}
