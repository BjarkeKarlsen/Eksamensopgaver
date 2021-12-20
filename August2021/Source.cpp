#include "Person.h"
#include "Vaccinecenter.h"

int main() {
	Vaccinecenter dinMor;
	Person p1("Din Mor1", "111111 - 1111", 0);
	Person p2("Din Mor2", "222222-2222", 1);
	Person p3("Din Mor3", "222222-2222", 2);
	Person p4("Din Mor4", "222222-2222", 3);

	dinMor.tilføjPersonTilKo(p1);
	dinMor.tilføjPersonTilKo(p2);
	dinMor.tilføjPersonTilKo(p3);
	dinMor.tilføjPersonTilKo(p4);

	dinMor.print();

	dinMor.fjernPersonFraKo();
	dinMor.fjernPersonFraKo();

	dinMor.print();
	

	return 0;
}