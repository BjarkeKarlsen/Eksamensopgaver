#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Kasse
{
	friend ostream& operator<<(ostream& os, const Kasse& kasse);

public:
	Kasse(double lengde, double bredde, double hojde);
	double getLengde() const;
	double getBredde() const;
	double getHojde() const;
	void setLengde(double l);
	void setBredde(double b);
	void setHojde(double h);
	double beregnVolumen() const;

private:
	double hojde_;
	double bredde_;
	double lengde_;
};

ostream& operator<<(ostream& os, const Kasse& kasse);
bool operator<(const Kasse& kasse1, const Kasse& kassek2);
bool operator>(const Kasse& kasse1, const Kasse& kassek2);