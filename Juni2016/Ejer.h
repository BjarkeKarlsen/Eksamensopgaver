#pragma once
#include <iostream>
#include "Ejerbolig.h"

using namespace std;
class Ejer
{
public:
	Ejer(char* navn, Ejerbolig* bolig);
	Ejer(const Ejer&);
	~Ejer();
	void setNavn(char* nytnavn);
	void printEjer() const;
private:
	char* navnPtr_ = nullptr;
	Ejerbolig* boligPtr_ = nullptr;

};