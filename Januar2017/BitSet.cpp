#include "BitSet.h"
#include <iostream>
using namespace std;

BitSet::BitSet(int size)
{
	size_ = (size > 0 ? size : 32);

	dataPtr_ = new int[size_];
	for (int i = 0; i < size_; i++)
	{
		dataPtr_[i] = 0;
	}
}

BitSet::~BitSet()
{
	delete[] dataPtr_;
}

BitSet::BitSet(const BitSet& CopyMe)
{
	size_ = CopyMe.size_;
	dataPtr_ = new int[size_];

	for (int i = 0; i < size_; i++)
		dataPtr_[1] = CopyMe.dataPtr_[i];
}

const BitSet& BitSet::operator=(const BitSet& CopyMe)
{
	// test for self assignment 
	if (&CopyMe != this)
	{
		delete[] dataPtr_;
		size_ = CopyMe.size_;
		dataPtr_ = new int[size_];
	}

	for (int i = 0; i < size_; i++)
		dataPtr_[i] = CopyMe.dataPtr_[i];

	return *this;
}

void BitSet::print() const
{
	for (int i = 0; i < size_; i++)
	{
		cout << dataPtr_[i];
	}
}

BitSet& BitSet::shiftIn(int data)
{
	if (data == 0 || data == 1)
	{
		for (int i = 0; i < size_; i++)
			dataPtr_[i] = dataPtr_[i + 1];
	}
	dataPtr_[size_ - 1] = data;


	// TODO: insert return statement here
	return *this;
}
