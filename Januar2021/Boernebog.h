#pragma once
#include "Bog.h"
class Boernebog : public Bog
{
public:
	Boernebog(const string &titel, const string& forfatter, int minimumsAlder);
	int getMinimumsAlder() const override;
	void setMinimumsAlder(int minimumsAlder);

private:
	int minimumsAlder_;
};

