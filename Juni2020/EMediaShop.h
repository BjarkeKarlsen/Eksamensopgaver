#pragma once
#include "EMedia.h"
#include <list>
class EMediaShop
{
public:
	EMediaShop(const char* name);
	~EMediaShop();
	void addEMedia(const EMedia&);
	void searchTitle(const string&) const;
	void searchAuthorOrArtist(const string&) const;
	void print() const;
	void operator+=(const EMedia& media);

private:
	list<const EMedia*> mediaList_;
	char* namePtr_;
};

