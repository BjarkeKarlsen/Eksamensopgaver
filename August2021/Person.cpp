#include "Person.h"

using namespace std;

Person::Person(const std::string& navn, const char* personnummer, int vaccineStatus)
    : navn_(navn), vaccineStatus_(vaccineStatus >= 0 && vaccineStatus <= 2 ? vaccineStatus : 0)
{
    strcpy_s(personnummer_, 12, personnummer);
    //navn_ = navn;
    //vaccineStatus_ = (vaccineStatus >= 0 && vaccineStatus <= 2 ? vaccineStatus : 0); 
}

Person::~Person() {

}

string Person::getNavn() const
{
    return navn_;
}

const char* Person::getPersonnummer() const
{
    return personnummer_;
}

int Person::getVaccineStatus() const
{
    return vaccineStatus_;
}

void Person::print() const
{
    cout << navn_ << endl << personnummer_ << endl;
    if (vaccineStatus_ == 0)
        cout << "Ikke Vaccineret";
    else
        cout << "Vaccineret " << vaccineStatus_ << ". gang" << endl;
}

const Person& Person::operator++()
{
    if (vaccineStatus_ < 2) {
        vaccineStatus_++;
    }

    return *this;
}

Person Person::operator++(int dummy)
{
    Person local = *this;

    if (vaccineStatus_ < 2) {
        ++((*this).vaccineStatus_);
        //vaccineStatus_++;
    }
    
    return local;
}
