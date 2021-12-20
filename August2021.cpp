Opgave 1 

Opgave 1A

    Person::Person(const std::string & navn, const char* personnummer, int vaccineStatus)
        : navn_(navn), vaccineStatus_(vaccineStatus >= 0 && vaccineStatus <= 2 ? vaccineStatus : 0)
    {
        strcpy_s(personnummer_, 12, personnummer);
    }

    void Person::print() const
    {
        cout << navn_ << endl << personnummer_ << endl;
        if (vaccineStatus_ == 0)
            cout << "Ikke Vaccineret";
        else
            cout << "Vaccineret " << vaccineStatus_ << ". gang" << endl;
    }

Opgave 1B

    const Person& operator++();
    Person operator++(int dummy);

Opgave 1C

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

Opgave 1D


    #include "Person.h"

    int main() {
        Person person1("Kurt Hansen", "222222-2222", 0);
        person1.print();

        ++person1;
        person1.print();

        person1++;
        person1.print();

        person1++;
        person1.print();

        return 0;
    }

Opgave 2A 

    virtual void print() const;
    virtual ~Person();


    Person::~Person() {

    }

Opgave 2B
    #pragma once
    #include "Person.h"
    #include <iostream>
    using namespace std;

    class Borger : public Person
    {
    public:
        Borger(const string& navn, const char* personnummer, int vaccineStatus, const char* aldersgruppe);
        ~Borger();
        void setAldersgruppe(const char*);
        const char* getAldersgruppe();
        void print() const;

    private:
        char* aldersgruppe_;
    };



Opgave 2C

    #include "Borger.h"

    Borger::Borger(const string& navn, const char* personnummer, int vaccineStatus, const char* aldersgruppe)
        : Person(navn, personnummer, vaccineStatus)
    {
        aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
        strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
    }

    Borger::~Borger()
    {
        delete[] aldersgruppe_;
    }

    void Borger::setAldersgruppe(const char* aldersgruppe)
    {

        if (strlen(aldersgruppe_) != strlen(aldersgruppe)) {
            delete[] aldersgruppe_;
            aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
        }

        strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
    }

    const char* Borger::getAldersgruppe()
    {
        return aldersgruppe_;
    }

    void Borger::print() const
    {
        Person::print();
        cout << "Aldersgruppe " << aldersgruppe_ << endl;
    }

Opgave 3A


    #include "Vaccinecenter.h"

    Vaccinecenter::Vaccinecenter() {


    }

    void Vaccinecenter::tilføjPersonTilKo(Person& nyPersonIKø)
    {
        if (nyPersonIKø.getVaccineStatus() < 2) {
            ko_.push_back(&nyPersonIKø);
        }
    }

    void Vaccinecenter::fjernPersonFraKo()
    {
        (*(ko_.front()))++;

        std::cout << "\nDenne Person er nu vaccineret og står ikke i kø" << std::endl;

        (ko_.front()->print());

        ko_.pop_front();
    }

    void Vaccinecenter::print() const
    {
        std::deque<Person*>::const_iterator iter;
        for (iter = ko_.begin(); iter != ko_.end(); iter++) {
            (*iter)->print();
        }
    }




Opgave 3B

    #include "Person.h"
    #include "Vaccinecenter.h"

    int main() {
        Vaccinecenter dinMor;
        Person p1("Din Mor1", "111111 - 1111", 0);
        Person p2("Din Mor2", "222222-2222", 1);
        Person p3("Din Mor3", "222222-2222", 2);
        Person p4("Din Mor4", "222222-2222", 3);

        dinMor.tilføjPersonTilKo(p1);
        dinMor.tilføjPersonTilKo(p2);
        dinMor.tilføjPersonTilKo(p3);
        dinMor.tilføjPersonTilKo(p4);

        dinMor.print();

        dinMor.fjernPersonFraKo();
        dinMor.fjernPersonFraKo();

        dinMor.print();


        return 0;
    }