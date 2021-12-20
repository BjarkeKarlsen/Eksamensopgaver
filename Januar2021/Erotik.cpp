#include "Erotik.h"

Erotik::Erotik(const string& titel, const string& forfatter)
    : Bog(titel, forfatter)
{
}

int Erotik::getMinimumsAlder() const
{
    return 18;
}
