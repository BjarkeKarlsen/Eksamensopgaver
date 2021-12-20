#include "Resistor.h"

Resistor::Resistor(double resistance )
    : resistance_(resistance  >  0 ? resistance : 1)
{
}

double Resistor::getResitance() const
{
    return resistance_;
}

void Resistor::setResitance(double resistance)
{
    resistance_ = (resistance > 0 ? resistance : 1);
}

double Resistor::getConductance() const
{
    return 1/resistance_;
}

void Resistor::setConductance(double conductance)
{
    resistance_ = resistance_ > 0 ? (1 / conductance) : resistance_;
}

Resistor operator&&(const Resistor& right, const Resistor& left)
{
    Resistor local(0);
    local = right.resistance_ + left.resistance_;
    return local;
}

Resistor operator||(const Resistor& right, const Resistor& left)
{
    Resistor local(0);
    local.setConductance(right.getConductance() + left.getConductance());
    //local.resistance_ = (right.getResitance() * left.getResitance())/ (right.getResitance() + left.getResitance());
    //local.resistance_ = (right.resistance_ * left.resistance_) / (right.resistance_ + left.resistance_);
    return local;
}
