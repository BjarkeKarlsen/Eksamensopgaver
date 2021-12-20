#include "Bog.h"
#include <iostream>
using namespace std;

Bog::Bog(const string& titel, const string& forfatter)
{
    setTitel(titel);
    setForfatter(forfatter);
}

Bog::~Bog() {

}

void Bog::setTitel(const std::string& titel)
{
    titel_ = (titel != "") ? titel : "Ukendt";
}

void Bog::setForfatter(const std::string& forfatter)
{
    forfatter_ = (forfatter != "") ? forfatter : "Ukendt";
}

std::string Bog::getTitel() const
{
    return titel_;
}

std::string Bog::getForfatter() const
{
    return forfatter_;
}

int Bog::getMinimumsAlder() const
{
    return 0;
}

void Bog::print() const
{
    cout << forfatter_ << ": " << titel_ << endl;
    cout << "Minimumsalder: " << getMinimumsAlder() << " arr" << endl;
}
