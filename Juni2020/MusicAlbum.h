#pragma once
#include "EMedia.h"
class MusicAlbum : public EMedia
{
public:
	MusicAlbum(const string &category, const string& title, const string &artist, double duration);
	string getAuthorOrArtist() const override;
	double getDuration() const;
	double calculatePrice() const override;
	void print() const override;
private:
	string artist_;
	double duration_;
};

