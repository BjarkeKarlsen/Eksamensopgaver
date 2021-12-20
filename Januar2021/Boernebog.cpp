#include "Boernebog.h"

Boernebog::Boernebog(const string& titel, const string& forfatter, int minimumsAlder)
    : Bog(titel, forfatter)
{
    setMinimumsAlder(minimumsAlder);
}

int Boernebog::getMinimumsAlder() const
{
    return minimumsAlder_;
}

void Boernebog::setMinimumsAlder(int minimumsAlder)
{
    minimumsAlder_ = minimumsAlder > 0 ? minimumsAlder : 0;
}
