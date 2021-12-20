//Declartion of vector
		vector< Kasse> katalog;

//Loop for const STL vector - 2020 Juni
		void EMediaShop::print() const
			{
				cout << "Butiksnavn: " << namePtr_ << endl;
				for (auto iter = mediaList_.cbegin(); iter != mediaList_.cend(); iter++) {
					(*iter)->print();
				}
			}

// Push Back funktion of STL
		//- Method 1
		katalog.push_back(k1); 

		//- Method 2
		if (nyPersonIKø.getVaccineStatus() < 2) {
			ko_.push_back(&nyPersonIKø);			
		}

		//- Method 3 - Juni 2021
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

//Use of front and pop - August 2021
		void Vaccinecenter::fjernPersonFraKo()
		{
			(*(ko_.front()))++;

			std::cout << "\nDenne Person er nu vaccineret og står ikke i kø" << std::endl;

			(ko_.front()->print());

			ko_.pop_front();
		}


// Pop
		std::cout << s1.pop() << std::endl;


//Operator while use of STL - Juni 2021
		Flyttebil& Flyttebil::operator+=(const Flyttekasse& kasse)
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


//Search name with use of STL
			void EMediaShop::searchAuthorOrArtist(const string& name) const
			{
				bool found = false;
				for (auto iter = mediaList_.cbegin(); iter != mediaList_.cend(); iter++) {
					if ((*iter)->getAuthorOrArtist() == name) {
						(*iter)->print();
						found = true;
					}
				}
		
				if (found == false) {
					cout << "DEr blev ikke fundet en bog eller album med den ønskede forfatter eller kunstner" << endl;
				}
			}


//Use STL to find the biggest number -Januar 2020
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