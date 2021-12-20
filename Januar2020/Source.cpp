#include "Benzin.h"
#include "Optankning.h"

int main() {
	Benzin b1(4, 98);

	Optankning op1(50, 40, &b1);
	op1.printInformation();

	return 0;
}