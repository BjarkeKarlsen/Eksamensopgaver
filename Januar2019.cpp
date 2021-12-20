Opgave 1A

	#pragma once
	#include <iostream>
	using namespace std;

	class Lyskilde
	{
	public:
		Lyskilde(double forbrug, double lysstyrke);
		virtual ~Lyskilde();
		void setForbrug(double);
		double getForbrug() const;
		void setLysstyrke(double);
		double getLysstyrke() const;
		virtual bool getDaempbar() const = 0;
		virtual void print() const;

	private:
		double forbrug_;
		double lysstyrke_;
	};

Opgave 1B
#include "Lyskilde.h"

Lyskilde::Lyskilde(double forbrug, double lysstyrke)
{
}

Lyskilde::~Lyskilde()
{
}

void Lyskilde::setForbrug(double forbrug)
{
	forbrug_ = forbrug > 0 ? forbrug : 0;
}

double Lyskilde::getForbrug() const
{
	return forbrug_;
}

void Lyskilde::setLysstyrke(double lysstyrke)
{
	lysstyrke_ = (lysstyrke > 0 ? lysstyrke : 0);
}

double Lyskilde::getLysstyrke() const
{
	return lysstyrke_;
}

void Lyskilde::print() const
{
	cout << "Lyskilde med forbrug " << forbrug_ << " W" << endl;
	cout << "og lysstyrke " << lysstyrke_ << " lumen" << endl;
	cout << "kan daempes: ";
	if (getDaempbar()) {
		cout << "Ja" << endl;
	}
	cout << "Nej" << endl;
}

Opgave 1C
	#include "Lyskilde.h"

	int main() {
		Lyskilde k1(21.23, 23.94);

		return 0;
	}

Opgave 1D
	#pragma once
	#include "Lyskilde.h"

	class GloedePaere : public Lyskilde
	{
	public:
		GloedePaere(double forbrug, double lysstyrke, string filamenttype);
		void setFilamenttype(string);
		string getFilamenttype() const;
		bool getDaempbar() const override;
		void print() const override;

	private:
		string filamenttype_;
	};

Opgave 1E

	#include "GloedePaere.h"

	GloedePaere::GloedePaere(double forbrug, double lysstyrke, string filamenttype = "Wolfram")
		: Lyskilde(forbrug, lysstyrke), filamenttype_(filamenttype)
	{
	}

	void GloedePaere::setFilamenttype(string filamenttype)
	{
		filamenttype_ = filamenttype;
	}


	string GloedePaere::getFilamenttype() const
	{
		return filamenttype_;
	}

	bool GloedePaere::getDaempbar() const
	{
		return true;
	}

	void GloedePaere::print() const
	{
		cout << "Gloedeparere med filanment af: " << getFilamenttype() << endl;
		Lyskilde::print();
	}

Opgave 1F
	#include "GloedePaere.h"

	int main() {
		GloedePaere g1(60, 400, "");
		g1.print();

		return 0;
	}

Opgave 2A
	std::ostream & operator<<(std::ostream & os, const Transaktion & transaktion)
	{
		os << transaktion.getTekst() << " " << transaktion.getBeloeb() << std::endl;
		return os;
	}

Opgave 2B

	#include "Transaktion.h"

	int main() {
		Transaktion t1("Dankort Kvickly", -345.95);
		std::cout << t1 << std::endl;

		return 0;
	}

Opgave 2C

	#include "Bankkonto.h"

	Bankkonto::Bankkonto(std::string ejer)
		: ejer_(ejer)
	{
	}

	Bankkonto& Bankkonto::indsaetTransaktion(const Transaktion& transaktion)
	{
		transaktioner_.push_back(transaktion);
		saldo_ += transaktion.getBeloeb();

		return *this;
	}

	void Bankkonto::printKontoUdskrift() const
	{
		std::cout << "Bankkonto med ejer " << ejer_ << std::endl;
		std::cout << "Saldo: " << saldo_ << std::endl;
		for (auto i = transaktioner_.begin(); i != transaktioner_.end(); i++) {
			std::cout << (*i) << std::endl;
		}
	}

Opgave 2D

	#include "Bankkonto.h"


	int main() {
		std::string name = "Duwe";
		Bankkonto b1(name);
		Transaktion t1("Dankort Kvickly", -345.95);
		b1.indsaetTransaktion(t1);
		b1.indsaetTransaktion(Transaktion("MobilePay Biografen", -180));

		b1.printKontoUdskrift();

		return 0;
	}

Opgave 3A
	#include "Stack.h"

	Stack::Stack(int stacksize)
		: stacksize_(stacksize > 0 ? stacksize : 10)
	{
		dataPtr_ = new int[stacksize];
		stacktop_ = 0;
	}

	Stack::~Stack()
	{
		delete dataPtr_;
	}

	int Stack::pop()
	{
		if (stacktop_ > 0) {
			stacktop_--;
			return dataPtr_[stacktop_];
		}
		else {
			return 0;
		}
	}

	Stack& Stack::operator+=(int element)
	{
		if (stacktop_ < stacksize_) {
			dataPtr_[stacktop_] = element;
			stacktop_++;
		}
		return *this;
	}

	bool Stack::isEmpty() const
	{
		return (stacktop_ == 0 ? true : false);
	}

	bool Stack::isFull() const
	{
		return (stacktop_ == stacksize_ ? true : false);
	}

Opgave 3B
	#include "Stack.h"
	#include <iostream>


	int main() {
		Stack s1(5);
		s1 += 2;
		s1 += 5;

		std::cout << "Popper elementerne. Indsat 2 og saa 5" << std::endl;
		std::cout << s1.pop() << std::endl;
		std::cout << s1.pop() << std::endl;

		return 0;
	}


Opgave 3C
	int Stack::pop()
	{
		if (stacktop_ > 0) {
			stacktop_--;
			return dataPtr_[stacktop_];
		}
		else {
			throw StackPopException();
			return 0;
		}
	}

Opgave 3D
	#include "Stack.h"
	#include <iostream>


	int main() {
		Stack s1(5);
		s1 += 2;
		s1 += 5;

		std::cout << "Popper elementerne. Indsat 2 og saa 5" << std::endl;
		std::cout << s1.pop() << std::endl;
		std::cout << s1.pop() << std::endl;

		std::cout << "Popping an empty stack with catch" << std::endl;
		try {
			s1.pop();
			std::cout << "Popping element" << std::endl;
		}
		catch (StackPopException e) {
			std::cout << "You tried popping an empty stack" << std::endl;
		}

		return 0;
	}