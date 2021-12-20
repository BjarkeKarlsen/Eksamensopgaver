#include "Benzin.h"
#include <iostream>
using namespace std;

Benzin::Benzin(double pris, int oktan)
    : Braendstof(pris)
{
    setOktan(oktan);
}

void Benzin::setOktan(int oktan)
{
    oktan_ = (oktan >= 88 && oktan <= 101 ? oktan : 95);
}

int Benzin::getOktan() const
{
    return oktan_;
}

void Benzin::printBeskrivelse() const
{
    cout << "Benzin med oktantal " << getOktan() << endl;
    cout << "Pris per liter: " << getPrisPerLiter()<< " kr." << endl;
}
