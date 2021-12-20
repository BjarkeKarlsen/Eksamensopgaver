Opgave 1A

	#pragma once
	class Kasse
	{
	public:
		Kasse(double lengde, double bredde, double hojde);
		double getLengde() const;
		double getBredde() const;
		double getHojde() const;
		void setLengde(double l);
		void setBredde(double b);
		void setHojde(double h);

	private:
		int hojde_;
		int bredde_;
		int lengde_;
	};

Opgave 1B

	Kasse::Kasse(double lengde, double bredde, double hojde) {
		setLengde(lengde);
		setBredde(bredde);
		setHojde(hojde);
	}

	double Kasse::beregnVolumen()
	{
		return (lengde_ * bredde_ * hojde_) / 1000;
	}

Opgave 1C
	// Tilføjer friend funktion i klasse
	class Kasse
	{
		friend ostream& operator<<(ostream& os, const Kasse& kasse);
	};

	// Laver operatoren << uden for klassen 
	ostream& operator<<(ostream& os, const Kasse& kasse);

	// Implemtere den i cpp filen
	ostream& operator<<(ostream& os, const Kasse& kasse)
	{
		os << "Kasse med laendgde " << kasse.getLengde() << " cm ,";
		os << "bredde " << kasse.getBredde() << " cm, hoejde " << kasse.getHojde() << " cm" << endl;
		os << "og volumen " << kasse.beregnVolumen() << " liter" << endl;
		return os;
	}

Opgave 1D

#include "Kasse.h"

	int main() {
		Kasse k1(50, 25, 10);

		cout << k1 << endl;

		return 0;
	}

Opgave 1E

	#include "Kasse.h"

	int main() {
		Kasse k1(50, 25, 10);
		Kasse k2(5, 25, 10);
		Kasse k3(50, 2, 1);
		Kasse k4(5, 2, 1);
		Kasse k5(5343, 2, 1);

		vector< Kasse> katalog;
		katalog.push_back(k1);
		katalog.push_back(k2);
		katalog.push_back(k3);
		katalog.push_back(k4);
		katalog.push_back(k5);

		for (auto i = katalog.begin(); i != katalog.end(); i++) {
			cout << *i << endl;
		}

		return 0;
	}

Opgave 1F

	#include "Kasse.h"

	int main() {
		Kasse k1(50, 25, 10);
		Kasse k2(5, 25, 10);
		Kasse k3(50, 2, 1);
		Kasse k4(5, 2, 1);
		Kasse k5(5343, 2, 100);

		vector< Kasse> katalog;
		katalog.push_back(k1);
		katalog.push_back(k2);
		katalog.push_back(k3);
		katalog.push_back(k4);
		katalog.push_back(k5);

		for (auto i = katalog.begin(); i != katalog.end(); i++) {
			cout << *i << endl;
		}

		Kasse max_value = katalog[1];

		for (auto i = katalog.begin(); i != katalog.end(); i++) {
			if (max_value.beregnVolumen() < (*i).beregnVolumen()) {
				max_value = *i;
			}
		}
		cout << "Den stoerste kasse er: " << endl << max_value << endl;

		return 0;
	

Opgave 2A
	#pragma once
	class Braendstof
	{
	public:
		Braendstof(double pris);
		virtual ~Braendstof();
		double getPrisPerLiter() const;
		void setPrisPerLiter(double);
		virtual void printBeskrivelse() const = 0;

	protected:
		double prisPerLiter_;
	};

Opgave 2B

	#include "Braendstof.h"

	Braendstof::Braendstof(double pris)
	{
		setPrisPerLiter(pris);
	}

	Braendstof::~Braendstof()
	{
	}

	double Braendstof::getPrisPerLiter() const
	{
		return prisPerLiter_;
	}

	void Braendstof::setPrisPerLiter(double pris)
	{
		prisPerLiter_ = (pris > 0 ? pris : 10.00);
	}

Opgave 2C
	//Kan ikke kompile, da der er full virtual methode i klassen

	#include "Braendstof.h"

	int main() {
		Braendstof b1(4);

		return 0;
	}

Opgave 2D

	#pragma once
	#include "Braendstof.h"
	class Benzin : public Braendstof
	{
	public:
		Benzin(double pris, int oktan);
		void setOktan(int oktan);
		int getOktan() const;
		void printBeskrivelse() const override;

	private:
		int oktan_;
	};

Opgave 2E

	#include "Benzin.h"
	#include <iostream>
	using namespace std;

	Benzin::Benzin(double pris, int oktan)
		: Braendstof(pris)
	{
		setOktan(oktan);
	}

	void Benzin::setOktan(int oktan)
	{
		oktan_ = (oktan >= 88 && oktan <= 101 ? oktan : 95);
	}

	int Benzin::getOktan() const
	{
		return oktan_;
	}

	void Benzin::printBeskrivelse() const
	{
		cout << "Benzin med oktantal " << getOktan() << endl;
		cout << "Pris per liter: " << getPrisPerLiter() << " kr." << endl;
	}

Opgave 2F

	#include "Benzin.h"

	int main() {
		Benzin b1(4, 98);
		b1.printBeskrivelse();

		return 0;
	}

Opgave 2G
// h fil
Optankning(double liter, double kilometer, Braendstof * braendstof);

	//cpp fil
	Optankning::Optankning(double liter, double kilometer, Braendstof * braendstof)
		: antalLiter_(liter > 0 ? liter : 0), antalKilometer_(kilometer > 0 ? kilometer : 0), braendstofPtr_(braendstof)
	{
	}

Opgave 2F

	#include "Benzin.h"
	#include "Optankning.h"

	int main() {
		Benzin b1(4, 98);

		Optankning op1(50, 40, &b1);
		op1.printInformation();

		return 0;
	}