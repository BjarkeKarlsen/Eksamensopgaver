#include "MusicAlbum.h"

MusicAlbum::MusicAlbum(const string& category, const string& title, const string& artist, double duration)
	: EMedia(category, title), artist_(artist)
{
    if (duration <= 0) {
        duration_ = 0;
    }
    else if (duration >= 1.5) {
        duration_ = 1.5;
    }
    else
        duration_ = duration;
}

string MusicAlbum::getAuthorOrArtist() const
{
	return artist_;
}

double MusicAlbum::getDuration() const
{
	return duration_;
}

double MusicAlbum::calculatePrice() const
{
	return duration_ * 100;
}

void MusicAlbum::print() const
{
    int timer = (int)duration_;
    int minutter = ((int)(duration_ * 60)) % 60;
    cout << "Kunster: " << artist_ << endl;
    cout << timer << " t " << minutter << " m" << endl;
    cout << "kr. " << calculatePrice() << endl << endl;
}
