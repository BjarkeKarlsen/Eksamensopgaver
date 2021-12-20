Opgave 1A

	#pragma once
	class Resistor
	{
	public:
		Resistor(double resistance = 1.0);
		double getResitance() const;
		void setResitance(double);
		double getConductance() const;
		void setConductance(double);

	private:
		double resistance_;
	};

Opgave 1B

#include "Resistor.h"

Resistor::Resistor(double resistance)
	: resistance_(resistance > 0 ? resistance : 1)
{
}

double Resistor::getResitance() const
{
	return resistance_;
}

void Resistor::setResitance(double resistance)
{
	resistance_ = (resistance > 0 ? resistance : 1);
}

double Resistor::getConductance() const
{
	return 1 / resistance_;
}

void Resistor::setConductance(double conductance)
{
	resistance_ = resistance_ > 0 ? (1 / conductance) : resistance_;
}


Opgave 1C

	#include "Resistor.h"
	#include <iostream>
	using namespace std;

	int main() {
		Resistor r1(5.0);
		Resistor r2(0.1);
		r2.setConductance(10);

		cout << "Object 1 Resitance :" << r1.getResitance() << endl;
		cout << "Object 1 Conductance: " << r1.getConductance() << endl;

		cout << "Object 2 Resitance :" << r2.getResitance() << endl;
		cout << "Object 2 Conductance: " << r2.getConductance() << endl;

		return 0;
	}

Opgave 1D
	friend Resistor operator&&(const Resistor & right, const Resistor & left);
	friend Resistor operator||(const Resistor& right, const Resistor& left);
	Resistor operator&&(const Resistor& right, const Resistor& left);
	Resistor operator||(const Resistor& right, const Resistor& left);

	Resistor operator&&(const Resistor& right, const Resistor& left)
	{
		Resistor local(0);
		local = right.resistance_ + left.resistance_;
		return local;
	}

	Resistor operator||(const Resistor& right, const Resistor& left)
	{
		Resistor local(0);
		local.setConductance(right.getConductance() + left.getConductance());
		//local.resistance_ = (right.getResitance() * left.getResitance())/ (right.getResitance() + left.getResitance());
		//local.resistance_ = (right.resistance_ * left.resistance_) / (right.resistance_ + left.resistance_);
		return local;
	}

Opgave 1E

	#include "Resistor.h"
	#include <iostream>
	using namespace std;

	int main() {
		Resistor a(5.0), b(15);
		Resistor c, d;

		c = a && b;
		d = a || b;

		cout << "Object c Resitance :" << c.getResitance() << endl;
		cout << "Object c Conductance: " << c.getConductance() << endl;

		cout << "Object d Resitance :" << d.getResitance() << endl;
		cout << "Object d Conductance: " << d.getConductance() << endl;

		return 0;
	}

Opgave 2A
	#pragma once
	#include <iostream>
	using namespace std;
	class Bog
	{
	public:
		Bog(const string& titel, const string& forfatter);
		~Bog();
		void setTitel(const std::string& titel);
		void setForfatter(const std::string& forfatter);
		std::string getTitel() const;
		std::string getForfatter() const;
		virtual int getMinimumsAlder() const = 0;
		virtual void print() const;

	private:
		string titel_;
		string forfatter_;

	};


Opgave 2B
	#include "Bog.h"
	#include <iostream>
	using namespace std;

	Bog::Bog(const string& titel, const string& forfatter)
	{
		setTitel(titel);
		setForfatter(forfatter);
	}

	Bog::~Bog() {

	}

	void Bog::setTitel(const std::string& titel)
	{
		titel_ = (titel != "") ? titel : "Ukendt";
	}

	void Bog::setForfatter(const std::string& forfatter)
	{
		forfatter_ = (forfatter != "") ? forfatter : "Ukendt";
	}

	std::string Bog::getTitel() const
	{
		return titel_;
	}

	std::string Bog::getForfatter() const
	{
		return forfatter_;
	}

	int Bog::getMinimumsAlder() const
	{
		return 0;
	}

	void Bog::print() const
	{
		cout << forfatter_ << ": " << titel_ << endl;
		cout << "Minimumsalder: " << getMinimumsAlder() << " arr" << endl;
	}



Opgave 2C
	#pragma once
	#include "Bog.h"
	class Erotik : public Bog
	{
	public:
		Erotik(const string& titel, const string& forfatter);
		int getMinimumsAlder() const override;
	};


Opgave 2D
	#include "Erotik.h"

	Erotik::Erotik(const string & titel, const string & forfatter)
		: Bog(titel, forfatter)
	{
	}

	int Erotik::getMinimumsAlder() const
	{
		return 18;
	}


Opgave 2E
	#pragma once
	#include "Bog.h"
	class Boernebog : public Bog
	{
	public:
		Boernebog(const string& titel, const string& forfatter, int minimumsAlder);
		int getMinimumsAlder() const override;
		void setMinimumsAlder(int minimumsAlder);

	private:
		int minimumsAlder_;
	};




Opgave 2F

	#include "Boernebog.h"

	Boernebog::Boernebog(const string& titel, const string& forfatter, int minimumsAlder)
		: Bog(titel, forfatter)
	{
		setMinimumsAlder(minimumsAlder);
	}

	int Boernebog::getMinimumsAlder() const
	{
		return minimumsAlder_;
	}

	void Boernebog::setMinimumsAlder(int minimumsAlder)
	{
		minimumsAlder_ = minimumsAlder > 0 ? minimumsAlder : 0;
	}


Opgave 2G
	#include "Boernebog.h"
	#include "Erotik.h"
	#include <iostream>
	using namespace std;

	int main() {
		Erotik bog1("50 Shades of Grey", "E.L.James");
		Boernebog bog2("Hojda fra Pjort", "Ole Lund Kirkegaard", 8);

		bog1.print();
		bog2.print();
		return 0;
	}

Opgave 2H
	#include "Boernebog.h"
	#include "Erotik.h"
	#include <iostream>
	#include <vector>
	using namespace std;

	int main() {
		Erotik bog1("50 Shades of Grey", "E.L.James");
		Boernebog bog2("Hojda fra Pjort", "Ole Lund Kirkegaard", 8);

		vector<Bog* >books;

		books.push_back(&bog1);
		books.push_back(&bog2);

		for (auto i = books.begin(); i != books.end(); i++) {
			(*i)->print();
		}

		return 0;
	}