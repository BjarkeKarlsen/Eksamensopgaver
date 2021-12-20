#include <iostream>
using namespace std;
template <typename MyType>

void isInRange(const MyType& min, const MyType& max, const MyType& value)
{
	if (value <= max && value >= min)
		cout << value << " er mellem " << min << " og " << max << endl;
	else
		cout << value << " er ikke mellem " << min << " og " << max << endl;
}

//opgave 1B
int main()
{
	isInRange(0, 10, 5);

	isInRange(0.0, 13.5, 10.0);

	isInRange('a', 'z', 'c');


}


