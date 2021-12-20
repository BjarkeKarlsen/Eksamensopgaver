#pragma once
#include "Dato.h"
#include <iostream>
using namespace std;


class Feriebolig {
public:
	Feriebolig(const Dato& koebsdato, int koebspris, int antalSengepladser);
	~Feriebolig();
	Dato getKoebsdato() const;
	void setKoebsdato(const Dato& koebsdato);
	int getKoebspris() const;
	void setKoebspris(int koebspris);
	int getAntalSengepladser() const;
	void setAntalSengepladser(int antalSengepladser);
	virtual int beregnAfgivt() const = 0;
	virtual void print() const;

protected:
	Dato koebsdato_;

private:
	int koebspris_;
	int antalSengepladser_;

};
