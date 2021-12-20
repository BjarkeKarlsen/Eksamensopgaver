#pragma once
#include <iostream>
using namespace std;
class EMedia
{
public:
	EMedia(const string& category, const string& title);
	~EMedia();
	string getCategory() const;
	string getTitle() const;
	virtual string getAuthorOrArtist() const = 0;
	virtual double calculatePrice() const = 0;
	virtual void print() const;
private:
	string category_;
	string title_;
};

