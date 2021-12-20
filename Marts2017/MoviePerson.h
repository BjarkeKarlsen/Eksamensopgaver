#pragma once
#include <iostream>
using namespace std;

class MoviePerson
{
public:
	MoviePerson(string name);
	string getName() const;
	MoviePerson& addOscar();
	int getNumberOfOscars() const;
	void print() const;
private:
	string name_;
	int numberOfOscars_;
};

#pragma once
#include <iostream>
using namespace std;

class MoviePerson
{
public:
	MoviePerson(string name);
	string getName() const;
	MoviePerson& addOscar();
	int getNumberOfOscars() const;
	void print() const;
private:
	string name_;
	int numberOfOscars_;
};

