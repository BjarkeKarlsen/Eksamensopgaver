#pragma once
class BitSet
{
public:
	BitSet(int size);
	//rule of three
	~BitSet();
	BitSet(const BitSet&);
	const BitSet& operator=(const BitSet&);
	void print() const;
	BitSet& shiftIn(int);
private:
	int size_;
	int* dataPtr_;
};

