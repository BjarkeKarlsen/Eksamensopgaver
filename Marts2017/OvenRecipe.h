#pragma once
#include "SimpleRecipe.h"
#include <iostream>
using namespace std;
class OvenRecipe : public SimpleRecipe
{
public:
	OvenRecipe(string name, int worktime, int temperature, int ovenTime);
	int getTemperature() const;
	int getOvenTime() const;
	int getTotalTime() const override;
private:
	int temperature_;
	int ovenTime_;
};

