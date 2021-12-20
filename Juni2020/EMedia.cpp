#include "EMedia.h"

EMedia::EMedia(const string& category, const string& title)
    : category_(category), title_(title)
{
}

EMedia::~EMedia()
{
}

string EMedia::getCategory() const
{
    return category_;
}

string EMedia::getTitle() const
{
    return title_;
}

void EMedia::print() const
{
    cout << "Genre: " << category_ << endl << "Titel: " << title_ << endl;
}
