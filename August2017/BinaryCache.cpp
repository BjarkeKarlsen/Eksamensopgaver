#include "BinaryCache.h"

BinaryCache::BinaryCache(int capacity)
{
	capacity_ = (capacity >= 1 ? capacity : 1);
	size_ = 0;
	numberPtr_ = new int[capacity_];
}

BinaryCache::BinaryCache(const BinaryCache& b)
{
	if (this != &b)
	{
		if (capacity_ != b.capacity_)
		{
			delete[] numberPtr_;
			capacity_ = b.capacity_;
			size_ = b.size_;
			numberPtr_ = new int[capacity_];
		}
		for (int i = 0; i < size_; i++)
			numberPtr_[i] = b.numberPtr_[i];
	}
	return *this;
}

BinaryCache::~BinaryCache()
{
	delete[] numberPtr_;
}

int BinaryCache::getSize() const
{
	return size_;
}
int BinaryCache::getCapacity() const
{
	return capacity_;
}
void BinaryCache::addNumber(int number)
{
	if (number == 1 || number == 0)
	{
		if (capacity_ == size_) {
			int* temp = numberPtr_;

			capacity_ *= 2;
			numberPtr_ = new int[capacity_];

			for (int i = 0; i < size_; i++)
				numberPtr_[i] = temp[i];
			delete[] temp;
		}
		numberPtr_[size_++] = number; //lægges i pladsen size + 1 - bagerst
	}
}
void BinaryCache::print() const
{
	for (int i = 0; i < size_; i++)
	{
		cout << numberPtr_[i];
	}
	cout << endl;
}