#pragma once
#include <string>
#include<iostream>
#include <stdio.h>

class Person
{
public:
	Person(const std::string &navn, const char *personnummer, int vaccineStatus);
	virtual ~Person();
	std::string getNavn() const;
	const char* getPersonnummer() const;
	int getVaccineStatus() const;
	virtual void print() const;
	const Person& operator++();
	Person operator++(int dummy);
private:
	std::string navn_;					// Ingen restriktioner
	char personnummer_[12];				// Ingen restriktioner
	int vaccineStatus_;					// gyldige v�rdier 0, 1, 2 - default 0
};