#include "EMediaShop.h"

EMediaShop::EMediaShop(const char* name)
{
	namePtr_ = new char[strlen(name) + 1];
	strcpy_s(namePtr_, strlen(name) + 1, name);
}

EMediaShop::~EMediaShop()
{
	delete[] namePtr_;
}

void EMediaShop::addEMedia(const EMedia& emedia)
{
	mediaList_.push_back(&emedia);
}

void EMediaShop::searchTitle(const string&) const
{

}

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

void EMediaShop::print() const
{	
	cout << "Butiksnavn: " << namePtr_ << endl;
	for (auto iter = mediaList_.cbegin(); iter != mediaList_.cend(); iter++) {
		(*iter)->print();
	}
}

void EMediaShop::operator+=(const EMedia& media) {
	addEMedia(media);
}

