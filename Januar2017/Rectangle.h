#pragma once
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, int vert, int hori);
	void draw() const override;
	virtual int area() const;
	void setSides(int vert, int hori);
private:
	int sideVertical_;
	int sideHorizontal_;

};