#include "SimpleRecipe.h"
#include "OvenRecipe.h"
#include <iostream>
using namespace std;
int main()
{
	SimpleRecipe* rPtr = new SimpleRecipe("Laksemad", 20);
	cout << rPtr->getName() << " tager " << rPtr->getTotalTime() <<
		" minutter i alt at lave." << endl;
	delete rPtr;
	rPtr = new OvenRecipe("RoastBeef", 15, 180, 45);
	cout << rPtr->getName() << " tager " << rPtr->getTotalTime()
		<< " minutter i alt at lave." << endl;
	return 0;
}