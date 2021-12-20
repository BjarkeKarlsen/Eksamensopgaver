
#pragma once
#include <iostream>
using namespace std;
class StraightLine
{
public:
	StraightLine(int = 0, int = 0);
	void setSlope(int);
	int getSlope() const;
	void setYCross(int);
	int getYCross() const;
	void print() const;

	bool operator==(const StraightLine&) const;
private:
	int slope_;
	int yCross_;
};

istream& operator>>(istream& is, StraightLine& line);
