#pragma once
#include "StackPopException.h"
class Stack
{
public:
	Stack(int stacksize = 10);
	~Stack();
	int pop();
	Stack& operator+=(int);
	bool isEmpty() const;
	bool isFull() const;

private:
	int* dataPtr_;
	const int stacksize_;
	int stacktop_;
};

