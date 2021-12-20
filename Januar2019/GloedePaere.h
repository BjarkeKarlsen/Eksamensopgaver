#pragma once
#include "Lyskilde.h"

class GloedePaere : public Lyskilde
{
public: 
	GloedePaere(double forbrug, double lysstyrke, string filamenttype);
	void setFilamenttype(string);
	string getFilamenttype() const;
	bool getDaempbar() const override;
	void print() const override;

private:
	string filamenttype_;
};

