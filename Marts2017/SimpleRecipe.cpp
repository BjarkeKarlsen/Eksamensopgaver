#include "SimpleRecipe.h"
SimpleRecipe::SimpleRecipe(string name, int workTime)
{
	name_ = name;
	workTime_ = workTime;
}
string SimpleRecipe::getName()
{
	return name_;
}
int SimpleRecipe::getWorkTime() const
{
	return workTime_;
}
int SimpleRecipe::getTotalTime() const
{
	return workTime_;
}