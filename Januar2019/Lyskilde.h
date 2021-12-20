#pragma once
#include <iostream>
using namespace std;

class Lyskilde
{
public:
	Lyskilde(double forbrug, double lysstyrke);
	virtual ~Lyskilde();
	void setForbrug(double);
	double getForbrug() const;
	void setLysstyrke(double);
	double getLysstyrke() const;
	virtual bool getDaempbar() const = 0;
	virtual void print() const;

private:
	double forbrug_; 
	double lysstyrke_;
};

