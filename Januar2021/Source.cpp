#include "Boernebog.h"
#include "Erotik.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	Erotik bog1("50 Shades of Grey", "E.L.James");
	Boernebog bog2("Hojda fra Pjort", "Ole Lund Kirkegaard", 8);

	vector<Bog* >books;

	books.push_back(&bog1);
	books.push_back(&bog2);

	for (auto i = books.begin(); i != books.end(); i++) {
		(*i)->print();
	}

	return 0;
}