#include "BitSet.h"

int main()
{
	BitSet bit(8);
	bit.shiftIn(1).shiftIn(0).shiftIn(1).shiftIn(1);

	bit.print();
}