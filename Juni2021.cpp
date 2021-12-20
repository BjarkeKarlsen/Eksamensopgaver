Opgave 1A
	#pragma once
	#include "Flyttekasse.h"
	#include <list>
	#include <iostream>
	using namespace std;

	class Flyttebil
	{
	public:
		Flyttebil(int kapacitet);
		int beregnAntalFlyttekasser(const Flyttekasse&) const;
		void fyldTomFlyttebil(const Flyttekasse& flyttekasse, int antal);
		void tomFlyttebil();

	private:
		int kapacitet_;
		list<const Flyttekasse*> indhold_;
	};


Opgave 1B
	#include "Flyttebil.h"

	Flyttebil::Flyttebil(int kapacitet)
		: kapacitet_(kapacitet >= 10 && kapacitet <= 40 ? kapacitet : 10)
	{
	}

	int Flyttebil::beregnAntalFlyttekasser(const Flyttekasse& flyttekasse) const
	{
		return (kapacitet_ / (flyttekasse.beregnVolumen() / 1000));
	}

	void Flyttebil::fyldTomFlyttebil(const Flyttekasse& flyttekasse, int antal)
	{
		int maxAntal = beregnAntalFlyttekasser(flyttekasse);

		if (!indhold_.empty() && antal <= maxAntal) {
			for (int i = 0; i < antal; i++) {
				indhold_.push_back(&flyttekasse);
			}
		}
		else {
			cout << "Flyttebilen er tom eller der er ikkke plads til " << antal << " flyttekasser.";
			cout << "Der fyldes ingen flyttekasser i flyttebilen." << endl;

			cout << "Der er nu " << indhold_.size() << " flyttekasser i flyttebilen." << endl;
		}
	}

	void Flyttebil::tomFlyttebil()
	{
		indhold_.clear();
		cout << "Flyttebilen er tom" << endl;
	}


Opgave 1C

	#include "Flyttebil.h"
	#include "Flyttekasse.h"

	int main() {
		Flyttekasse k1(30, 20, 50);
		Flyttekasse k2(10, 20, 70);
		Flyttekasse k3(40, 50, 50);
		Flyttebil b1(8);
		b1.fyldTomFlyttebil(k1, 5);
		b1.beregnAntalFlyttekasser(k1);
		b1.fyldTomFlyttebil(k2, 5);
		b1.tomFlyttebil();


		return 0;
	}

Opgave 1D
	Flyttebil & operator+=(const Flyttekasse & kasse);

Opgave 1E
	Flyttebil & Flyttebil::operator+=(const Flyttekasse & kasse)
	{
		if (indhold_.size() <= beregnAntalFlyttekasser(kasse)) {
			indhold_.push_back(&kasse);
		}
		else {
			cout << "Der er ikke plads til flere flyttekasser i flyttebilen" << endl;
		}
		cout << "Der er nu " << indhold_.size() << " flyttekasser i flyttebilen." << endl;

		return *this;
	}

Opgave 1F
	#include "Flyttebil.h"
	#include "Flyttekasse.h"

	int main() {
		Flyttekasse k1(30, 20, 50);
		Flyttekasse k2(10, 20, 70);
		Flyttekasse k3(40, 50, 50);
		Flyttebil b1(8);
		b1 += k1, k2;
		b1.fyldTomFlyttebil(k3, 5);
		b1 += k1;

		return 0;
	}

Opgave 2A
#pragma once
#include "Dato.h"
#include <iostream>
using namespace std;


class Feriebolig {
	public:
		Feriebolig(const Dato& koebsdato, int koebspris, int antalSengepladser);
		~Feriebolig();
		Dato getKoebsdato() const;
		void setKoebsdato(const Dato& koebsdato);
		int getKoebspris() const;
		void setKoebspris(int koebspris);
		int getAntalSengepladser() const;
		void setAntalSengepladser(int antalSengepladser);
		void print() const;

	protected:
		Dato koebsdato_;

	private:
		int koebspris_;
		int antalSengepladser_;

	};


Opgave 2B
	#pragma once
	#include "Dato.h" 
	#include "Feriebolig.h"

	class Sommerhus : public Feriebolig
	{
	public:
		Sommerhus(const char* navn, int areal, float afstandTilStrand, const Dato& koebsdato, int koebspris, int antalSengepladser);
		void setAreal(int);
		void setNavn(const char*);
		int beregnAfgivt() const override;
		void print() const override;
	private:
		int areal_;
		float afstandTilStrand_;
		char* navn_;
	};



Opgave 2C

	#include "Sommerhus.h"

	Sommerhus::Sommerhus(const char* name, int areal, float afstandTilStrand, const Dato& koebsdato, int koebspris, int antalSengepladser)
		: Feriebolig(koebsdato, koebspris, antalSengepladser), afstandTilStrand_(afstandTilStrand > 0 ? afstandTilStrand : 0.0)
	{
		setAreal(areal);
		navn_ = new char[strlen(name) + 1];
		strcpy_s(navn_, strlen(name) + 1, name);
	}

	void Sommerhus::setAreal(int areal)
	{
		areal_ = (areal <= 25 ? areal : 25);
	}

	void Sommerhus::setNavn(const char* name)
	{
		if (strlen(name) != strlen(navn_)) {
			delete[] navn_;
			navn_ = new char[strlen(name) + 1];
		}
		strcpy_s(navn_, strlen(name) + 1, name);
	}

	int Sommerhus::beregnAfgivt() const
	{
		return (areal_ * 95);
	}

	void Sommerhus::print() const
	{
		cout << navn_ << endl;
		cout << areal_ << "m2" << endl;
		cout << "Nærmeste strand: " << afstandTilStrand_ << " km" << endl;
		cout << getAntalSengepladser() << "sovepladser" << endl;
		cout << "Sidst handlet " << getKoebsdato() << endl;
		cout << "Pris " << getKoebspris() << endl;
		cout << "Ejendomsskat " << beregnAfgivt() << "kr. pr år" << endl;
	}


Opgave 2D

	#include "Sommerhus.h"

	int main() {


		Sommerhus s1("Lynghytten", 55, 1.6, Dato(1, 5, 2021), 1345000, 4);
		s1.print();

		s1.setNavn("Lasso");
		s1.setAntalSengepladser(6);
		s1.setAreal(250);
		s1.setKoebsdato(535);
		s1.setKoebsdato(Dato(3, 3, 3333));

		Feriebolig* feriboligPtr = &s1;

		feriboligPtr->print();

		return 0;
	}