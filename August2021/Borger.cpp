#include "Borger.h"

Borger::Borger(const string& navn, const char* personnummer, int vaccineStatus, const char* aldersgruppe)
	: Person(navn, personnummer, vaccineStatus)
{
	aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
	strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
}

Borger::~Borger()
{
	delete[] aldersgruppe_;
}

void Borger::setAldersgruppe(const char* aldersgruppe)
{

	if (strlen(aldersgruppe_) != strlen(aldersgruppe)) {
		delete[] aldersgruppe_;
			aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
	}

	strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
}

const char* Borger::getAldersgruppe()
{
	return aldersgruppe_;
}

void Borger::print() const
{
	Person::print();
	cout << "Aldersgruppe " << aldersgruppe_ << endl;
}
