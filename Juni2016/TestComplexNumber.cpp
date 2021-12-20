#include "ComplexNumber.h"
#include <stdio.h>
#include <list>
using namespace std;


int main()
{
	//opgave 1B
	ComplexNumber obj(1, 2);

	obj.print();


	//opgave 1E

	ComplexNumber obj1(3, 4);

	cout << obj + obj1 << endl;

	//opgave 1F

	list<ComplexNumber> data;
	ostream_iterator<ComplexNumber> myOutput(cout, "\n");

	//opgave 1G
	data.push_back(ComplexNumber(-2, 4));
	data.push_back(ComplexNumber(6, -8));
	data.push_back(ComplexNumber(9, -2));

	//opgave 1H
	copy(data.begin(), data.end(), myOutput);

	return 0;

}