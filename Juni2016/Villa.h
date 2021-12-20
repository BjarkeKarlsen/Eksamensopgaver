#pragma once
class Villa : public Ejerbolig
{
public:
	Villa(int areal, int antalPlan);
	virtual void printBolig() const;

private:
	int antalPlan_ = 0;
};

