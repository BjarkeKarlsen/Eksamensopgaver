#pragma once
class Sundhedspersonale
{
public:
	Sundhedspersonale();
	void setRisikogruppe(int);
	int getAldersgruppe() const;
	void print() const;

private:
	int risikogruppe_ = 1;
};

