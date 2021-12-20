#pragma once
class Shape
{
public:
	Shape(int x, int y);
	void move(int x, int y);
	virtual void draw() const = 0;
	virtual int area() const = 0;
protected:
	int centerX_;
	int centerY_;
private:
};

