#pragma once
#include<deque>
#include"Person.h"

class Vaccinecenter
{
public:
	Vaccinecenter();
	void tilf�jPersonTilKo( Person& nyPersonIK� );
	void fjernPersonFraKo();
	void print() const;
private:
	std::deque<Person*> ko_;
};