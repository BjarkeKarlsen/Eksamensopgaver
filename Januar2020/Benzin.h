#pragma once
#include "Braendstof.h"
class Benzin : public Braendstof
{
public:
	Benzin(double pris, int oktan);
	void setOktan(int oktan);
	int getOktan() const;
	void printBeskrivelse() const override;

private:
	int oktan_;
};

