#pragma once
#include "EMedia.h"
class EBook : public EMedia
{
public:
	EBook(const string& category, const string& title, const string& author, int numberOfPages);
	string getAuthorOrArtist() const override;
	int getNumberOfPages() const;
	double calculatePrice() const override;
	void print() const override;

private:
	string author_;
	int numberOfPages_;
};

