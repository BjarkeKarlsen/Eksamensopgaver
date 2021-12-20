#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Borger : public Person
{
public:
	Borger(const string &navn, const char *personnummer, int vaccineStatus, const char *aldersgruppe);
	~Borger();
	void setAldersgruppe(const char*);
	const char* getAldersgruppe();
	void print() const;

private:
	char* aldersgruppe_;
};

