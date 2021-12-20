#include "EBook.h"

EBook::EBook(const string& category, const string& title, const string &author, int numberOfPages)
    : EMedia(category, title), author_(author)
{
    if (numberOfPages <= 0) {
        numberOfPages_ = 0;
    }
    else if (numberOfPages >= 500) {
        numberOfPages_ = 500;
    }
    else
        numberOfPages_ = numberOfPages;
}

string EBook::getAuthorOrArtist() const
{
    return author_;
}

int EBook::getNumberOfPages() const
{
    return numberOfPages_;
}

double EBook::calculatePrice() const
{
    return numberOfPages_*0.5;
}

void EBook::print() const
{
    EMedia::print();
    cout << "Forfatter: " << author_ << endl;
    cout << numberOfPages_ << " sider" << endl;
    cout << "kr. " << calculatePrice() << endl;
}
