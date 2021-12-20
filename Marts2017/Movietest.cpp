#include "MoviePerson.h"
#include "Movie.h"


int main()
{
	MoviePerson p1("Dustin Hoffman");
	MoviePerson p2("Lana Wachowski");
	MoviePerson p3("Sandra Bullock");

	p1.addOscar().addOscar();
	p3.addOscar();

	p1.print();
	p2.print();
	p3.print();

	Movie M("MatrixRevisited", &p2);
	M.hireActor(&p1);
	M.print();


	return 0;
}