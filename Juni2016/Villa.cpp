#include "Villa.h"
#include <iostream>
using namespace std;
#include "Ejerbolig.h"


Villa::Villa(int areal, int antalPlan)
{
	antalPlan_ = (antalPlan >= 0 && antalPlan <= 3) ? antalPlan : 0;
}

void Villa::printBolig() const
{
	cout << "Villa" << endl;
	Ejerbolig::printBolig();
	cout << "Antal plan: " << antalPlan_ << endl;
}
