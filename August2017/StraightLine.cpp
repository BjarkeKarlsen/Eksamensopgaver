#include "StraightLine.h"

StraightLine::StraightLine(int slope, int yCross)
{
	slope_ = slope;
	yCross_ = yCross;
}

void StraightLine::setSlope(int slope)
{
	slope_ = slope;
}


int StraightLine::getSlope() const
{
	return slope_;
}

void StraightLine::setYCross(int yCross)
{
	yCross_ = yCross;
}

int StraightLine::getYCross() const
{
	return yCross_;
}

void StraightLine::print() const
{
	if (yCross_ >= 0)
		cout << "y = " << slope_ << "x + " << yCross_ << endl;
	else
		cout << "y = " << slope_ << "x - " << -yCross_ << endl;
}

bool StraightLine::operator==(const StraightLine& correctLine) const
{
	return (slope_ == correctLine.slope_ && yCross_ == correctLine.yCross_);
}

istream& operator>>(istream& is, StraightLine& line)
{
	int a, b;

	is >> a >> b;

	line.setSlope(a);
	line.setYCross(b);
	return is;
}
