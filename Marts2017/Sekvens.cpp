#include "Sekvens.h"
#include <iostream>
using namespace std;

Sekvens::Sekvens()
{
	length_ = 0;
	dataPtr_ = nullptr;
}

Sekvens::~Sekvens()
{
	delete[]dataPtr_;
}

Sekvens::Sekvens(const Sekvens& copyMe)
{
	length_ = copyMe.length_;

	dataPtr_ = new int[length_];

	for (int i = 0; i < length_; i++)
	{
		dataPtr_[i] = copyMe.dataPtr_[i];
	}

}

const Sekvens& Sekvens::operator=(const Sekvens& copyMe)
{
	if (this != &copyMe)
	{
		if (length_ != copyMe.length_)
		{
			delete dataPtr_;
			length_ = copyMe.length_;
			dataPtr_ = new int[length_];
		}

		for (int i = 0; i < length_; i++)
		{
			dataPtr_[i] = copyMe.dataPtr_[i];
		}
	}
	return *this;

}
Sekvens& Sekvens::push_back(int data)
{
	int* temp = dataPtr_;
	dataPtr_ = new int[length_ + 1];
	for (int i = 0; i < length_; i++)
	{
		dataPtr_[i] = temp[i];
	}
	dataPtr_[length_] = data;
	delete temp;
	length_++;

	return *this;
}

int Sekvens::getLength() const
{
	return length_;
}

int Sekvens::getByIndex(int index) const
{
	if (0 <= index && index < length_)
	{
		return dataPtr_[index];
	}
	else
	{
		return 0;
	}
}

void Sekvens::print() const
{
	for (int i = 0; i < length_; i++)
	{
		cout << dataPtr_[i] << " ";
	}
}
