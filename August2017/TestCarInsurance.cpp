#include "CarInsurance.h"
#include "Insurance.h"

int main()
{
	Insurance* myPtr = new CarInsurance("AB-10123456", 50000, 2500, 20000);

	myPtr->print();
	return 0;
}
