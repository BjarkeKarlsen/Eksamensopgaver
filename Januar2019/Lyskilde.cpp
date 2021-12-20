#include "Lyskilde.h"

Lyskilde::Lyskilde(double forbrug, double lysstyrke)
	: forbrug_(forbrug > 0 ? forbrug : 0), lysstyrke_(lysstyrke > 0 ? lysstyrke : 0)
{
}

Lyskilde::~Lyskilde()
{
}

void Lyskilde::setForbrug(double forbrug)
{
	forbrug_ = forbrug > 0 ? forbrug : 0;
}

double Lyskilde::getForbrug() const
{
	return forbrug_;
}

void Lyskilde::setLysstyrke(double lysstyrke)
{
	lysstyrke_ = (lysstyrke > 0 ? lysstyrke : 0);
}

double Lyskilde::getLysstyrke() const
{
	return lysstyrke_;
}

void Lyskilde::print() const
{
	cout << "Lyskilde med forbrug " << forbrug_ << " W" << endl;
	cout << "og lysstyrke " << lysstyrke_ << " lumen" << endl;
	cout << "kan daempes: ";
	if (getDaempbar()) {
		cout << "Ja" << endl;
	} else
		cout << "Nej" << endl;
}
