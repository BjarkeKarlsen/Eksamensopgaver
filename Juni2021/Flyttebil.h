#pragma once
#include "Flyttekasse.h"
#include <list>
#include <iostream>
using namespace std;

class Flyttebil
{
public:
	Flyttebil(int kapacitet);
	int beregnAntalFlyttekasser(const Flyttekasse&) const;
	void fyldTomFlyttebil(const Flyttekasse& flyttekasse, int antal);
	void tomFlyttebil();
	Flyttebil& operator+=(const Flyttekasse& kasse);

private:
	int kapacitet_;
	list<const Flyttekasse*> indhold_;
};

