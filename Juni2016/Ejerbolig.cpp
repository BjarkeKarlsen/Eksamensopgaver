#include "Ejerbolig.h"
#include <iostream>
using namespace std;


Ejerbolig::Ejerbolig(int areal)
{
	areal_ = (areal > 0 ? areal : 0);

}

void Ejerbolig::printBolig() const
{
	cout << "Boligareal: " << areal_ << " m2" << endl;
}
