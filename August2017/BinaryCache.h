#pragma once
#include <iostream>
using namespace std;
class BinaryCache
{
public:
	BinaryCache(int capacity);
	BinaryCache(const BinaryCache& b); //copyconstructor
	~BinaryCache(); //destructor
	int getSize() const;
	int getCapacity() const;
	void addNumber(int number);
	void print() const;
private:
	int size_;
	int capacity_;
	int* numberPtr_;
};

