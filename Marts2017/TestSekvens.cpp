#include "Sekvens.h"
#include <iostream>
using namespace std;

int main()
{
	Sekvens s;
	s.print();

	s.push_back(1).push_back(2).push_back(3).push_back(4).push_back(5);
	s.push_back(5).push_back(4).push_back(3).push_back(2).push_back(1);
	s.print();
	cout << endl;

	cout << "Element med index 3 er " << s.getByIndex(3) << endl;
	

	Sekvens s1;
	s1.push_back(1).push_back(2);
	Sekvens s2(s1);
	s2.push_back(3).push_back(4);
	Sekvens s3;
	s3 = s2;
	s3.push_back(5).push_back(6);
	s1.print(); cout << endl;
	s2.print(); cout << endl;
	s3.print(); cout << endl;
	return 0;
}