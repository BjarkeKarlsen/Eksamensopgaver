#include "OvenRecipe.h"

OvenRecipe::OvenRecipe(string name, int worktime, int temperature, int ovenTime)
    :SimpleRecipe(name, worktime)
{
    temperature_ = temperature;
    ovenTime_ = ovenTime;
}

int OvenRecipe::getTemperature() const
{
    return temperature_;
}

int OvenRecipe::getOvenTime() const
{
    return ovenTime_;
}

int OvenRecipe::getTotalTime() const
{
    return  SimpleRecipe::getTotalTime() + ovenTime_;;
}
