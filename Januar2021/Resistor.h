#pragma once
class Resistor
{
	friend Resistor operator&&(const Resistor& right, const Resistor& left);
	friend Resistor operator||(const Resistor& right, const Resistor& left);
public:
	Resistor(double resistance = 1.0);
	double getResitance() const;
	void setResitance(double);
	double getConductance() const;
	void setConductance(double);
	

private:
	double resistance_;
};

Resistor operator&&(const Resistor& right, const Resistor& left);
Resistor operator||(const Resistor& right, const Resistor& left);