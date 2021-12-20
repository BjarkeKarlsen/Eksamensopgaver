#pragma once
#include <string>
using namespace std;
class SimpleRecipe
{
public:
	SimpleRecipe(string name, int workTime);
	string getName();
	int getWorkTime() const;
	virtual int getTotalTime() const;
private:
	string name_;
	int workTime_;
};