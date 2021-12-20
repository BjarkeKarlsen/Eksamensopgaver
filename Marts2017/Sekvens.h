#pragma once
class Sekvens
{
public:
	Sekvens();
	~Sekvens();
	Sekvens(const Sekvens& CopyMe);
	const Sekvens& operator=(const Sekvens& copyMe);
	Sekvens& push_back(int data);
	int getLength() const;
	int getByIndex(int index) const;
	void print() const;

private:
	int length_;
	int* dataPtr_ = nullptr;


};

