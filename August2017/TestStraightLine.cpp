#include "StraightLine.h"
#include <iostream>
#include <vector>

int main()
{
	StraightLine ob1(1, 2);
	StraightLine ob2;

	ob1.print();
	ob2.print();

	StraightLine ob3;

	cout << "indtast første parameter, tryk enter og derefter andet" << endl;
	cin >> ob3;

	if (ob3 == ob1 || ob3 == ob2)
		cout << "Linjen findes i forvejen" << endl;
	else
		cout << "Linjen findes ikke i forvejen" << endl;

	//opgave 1F
	vector<StraightLine> objekter; // Sådan erklærer man et obejekt af vector som kan lagre objekter af klassen StraightLine

	//opgave 1G
	objekter.push_back(ob1); // lægger et objekt i min vector-objkekt
	objekter.push_back(ob2);
	objekter.push_back(ob3);

	//opgave 1H
	for (vector<StraightLine>::iterator i = objekter.begin(); i != objekter.end(); i++)
		i->print();

}