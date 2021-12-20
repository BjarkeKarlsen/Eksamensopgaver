#include "BinaryCache.h"
#include <iostream>

int main()
{
	BinaryCache obj(2);

	obj.addNumber(1);
	obj.addNumber(1);
	obj.addNumber(1);
	obj.print();
	cout << obj.getSize() << endl;
	cout << obj.getCapacity() << endl;

	return 0;
}