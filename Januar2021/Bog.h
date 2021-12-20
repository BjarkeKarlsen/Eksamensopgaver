#pragma once
#include <iostream>
using namespace std;
class Bog
{
public:
	Bog(const string &titel, const string &forfatter);
	~Bog();
	void setTitel(const std::string& titel);
	void setForfatter(const std::string& forfatter);
	std::string getTitel() const;
	std::string getForfatter() const;
	virtual int getMinimumsAlder() const = 0;
	virtual void print() const;

private:
	string titel_;
	string forfatter_;

};

