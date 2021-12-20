#include "Sommerhus.h"

int main() {
	

	Sommerhus s1("Lynghytten", 55, 1.6, Dato(1, 5, 2021), 1345000, 4);
	s1.print();

	s1.setNavn("Lasso");
	s1.setAntalSengepladser(6);
	s1.setAreal(250);
	s1.setKoebsdato(535);
	s1.setKoebsdato(Dato(3, 3, 3333));
	
	Feriebolig* feriboligPtr = &s1;
	
	feriboligPtr->print();

	return 0;
}