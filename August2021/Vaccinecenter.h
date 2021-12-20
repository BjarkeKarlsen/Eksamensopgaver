#pragma once
#include<deque>
#include"Person.h"

class Vaccinecenter
{
public:
	Vaccinecenter();
	void tilføjPersonTilKo( Person& nyPersonIKø );
	void fjernPersonFraKo();
	void print() const;
private:
	std::deque<Person*> ko_;
};