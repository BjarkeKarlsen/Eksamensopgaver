#include "Vaccinecenter.h"

Vaccinecenter::Vaccinecenter(){

	
}

void Vaccinecenter::tilf�jPersonTilKo(Person& nyPersonIK�)
{
	if (nyPersonIK�.getVaccineStatus() < 2) {
		ko_.push_back(&nyPersonIK�);
	}
}

void Vaccinecenter::fjernPersonFraKo()
{
	(*(ko_.front()))++;

	std::cout << "\nDenne Person er nu vaccineret og st�r ikke i k�" << std::endl;

	(ko_.front()->print());

	ko_.pop_front();
}

void Vaccinecenter::print() const
{
	std::deque<Person*>::const_iterator iter;
	for (iter = ko_.begin(); iter != ko_.end(); iter++) {
		(*iter)->print();
	}
}
