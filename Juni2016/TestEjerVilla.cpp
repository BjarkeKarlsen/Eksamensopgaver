#include "Ejer.h"
#include "Ejerbolig.h"
#include "Villa.h"

int main()
{
	Ejer ejer("Kurt Hansen");

	ejer.printEjer();
	ejer.setNavn("Kurt Pedersen");
	ejer.printEjer();



	Ejerbolig Bolig(120);

	Ejer ejer1("Kurt Hansen", &Bolig);

	ejer1.printEjer();

	//opgave 2i

	Villa villa(143, 2);
	Ejer ejer2("Anne Poulen", &villa);

	ejer2.printEjer();

	return 0;
}