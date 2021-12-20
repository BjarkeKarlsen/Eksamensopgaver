// August 2021 - Declartion of const char as dynamic memory
        void Borger::setAldersgruppe(const char* aldersgruppe)
        {
            //If aldersgruppe is already declared
            if (strlen(aldersgruppe_) != strlen(aldersgruppe)) {
                delete[] aldersgruppe_;
                aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
            }

            strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
        }

// August 2021 - Declartion of const char as dynamic memory
        Borger::Borger(const string& navn, const char* personnummer, int vaccineStatus, const char* aldersgruppe)
            : Person(navn, personnummer, vaccineStatus)
        {
            aldersgruppe_ = new char[strlen(aldersgruppe) + 1];
            strcpy_s(aldersgruppe_, strlen(aldersgruppe) + 1, aldersgruppe);
        }

//Remeber to delete dynamic memmory 
        EMediaShop::~EMediaShop()
        {
            delete[] namePtr_;
        }

