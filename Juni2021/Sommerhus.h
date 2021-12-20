#pragma once
#include "Dato.h" 
#include "Feriebolig.h"

class Sommerhus : public Feriebolig
{
public:
	Sommerhus(const char* navn, int areal, float afstandTilStrand, const Dato& koebsdato, int koebspris, int antalSengepladser);
	void setAreal(int);
	void setNavn(const char*);
	int beregnAfgivt() const override;
	void print() const override;
private:
	int areal_;
	float afstandTilStrand_;
	char* navn_;
};

