#include "Shape.h"

Shape::Shape(int x, int y)
{
	centerX_ = x;
	centerY_ = y;
}

void Shape::move(int x, int y)
{
	centerX_ = x;
	centerY_ = y;
}
