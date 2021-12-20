////Opgave 1A
//	#pragma once
//	#include <iostream>
//	using namespace std;
//	class EMedia
//	{
//	public:
//		EMedia(const string& category, const string& title);
//		~EMedia();
//		string getCategory() const;
//		string getTitle() const;
//		virtual string getAuthorOrArtist() const = 0;
//		virtual double calculatePrice() const = 0;
//		virtual void print() const;
//	private:
//		string category_;
//		string title_;
//	};
//
//	//#include "EMedia.h"
//
//	EMedia::EMedia(const string& category, const string& title)
//		: category_(category), title_(title)
//	{
//	}
//
//	EMedia::~EMedia()
//	{
//	}
//
//	string EMedia::getCategory() const
//	{
//		return category_;
//	}
//
//	string EMedia::getTitle() const
//	{
//		return title_;
//	}
//
//	void EMedia::print() const
//	{
//		cout << "Genre: " << category_ << endl << "Titel: " << title_ << endl;
//	}
//
//
////Opgave 2A
//	#pragma once
//	//#include "EMedia.h"
//	class EBook : public EMedia
//	{
//	public:
//		EBook(const string& category, const string& title, const string& author, int numberOfPages);
//		string getAuthorOrArtist() const override;
//		int getNumberOfPages() const;
//		double calculatePrice() const override;
//		void print() const override;
//
//	private:
//		string author_;
//		int numberOfPages_;
//	};
//
//
//	//#include "EBook.h"
//
//	EBook::EBook(const string& category, const string& title, const string& author, int numberOfPages)
//		: EMedia(category, title), author_(author)
//	{
//		if (numberOfPages <= 0) {
//			numberOfPages_ = 0;
//		}
//		else if (numberOfPages >= 500) {
//			numberOfPages_ = 500;
//		}
//		else
//			numberOfPages_ = numberOfPages;
//	}
//
//	string EBook::getAuthorOrArtist() const
//	{
//		return author_;
//	}
//
//	int EBook::getNumberOfPages() const
//	{
//		return numberOfPages_;
//	}
//
//	double EBook::calculatePrice() const
//	{
//		return numberOfPages_ * 0.5;
//	}
//
//	void EBook::print() const
//	{
//		EMedia::print();
//		cout << "Forfatter: " << author_ << endl;
//		cout << numberOfPages_ << " sider" << endl;
//		cout << "kr. " << calculatePrice() << endl;
//	}
//
////Opgave 2B
//
//	//#include "MusicAlbum.h"
//
//	MusicAlbum::MusicAlbum(const string& category, const string& title, const string& artist, double duration)
//		: EMedia(category, title), artist_(artist)
//	{
//		if (duration <= 0) {
//			duration_ = 0;
//		}
//		else if (duration >= 1.5) {
//			duration_ = 1.5;
//		}
//		else
//			duration_ = duration;
//	}
//
//	string MusicAlbum::getAuthorOrArtist() const
//	{
//		return artist_;
//	}
//
//	double MusicAlbum::getDuration() const
//	{
//		return duration_;
//	}
//
//	double MusicAlbum::calculatePrice() const
//	{
//		return duration_ * 100;
//	}
//
//	void MusicAlbum::print() const
//	{
//		int timer = (int)duration_;
//		int minutter = ((int)(duration_ * 60)) % 60;
//		cout << "Kunster: " << artist_ << endl;
//		cout << timer << " t " << minutter << " m" << endl;
//		cout << "kr. " << calculatePrice() << endl << endl;
//	}
//
//
////Opgave 2C
//
//	//#include "EBook.h"
//	//#include "MusicAlbum.h"
//
//	int main() {
//		EBook book("Krimi", "Mord i Natten", "Slemme Kurt", 240);
//		MusicAlbum music("Lort", "Lorten", "Lortsen", 40);
//
//		book.print();
//		music.print();
//
//		return 0;
//}
//
////Opgave 3A
//
//	#pragma once
//	//#include "EMedia.h"
//	#include <list>
//	class EMediaShop
//	{
//	public:
//		EMediaShop(const char* name);
//		~EMediaShop();
//		void addEMedia(const EMedia&);
//		void searchTitle(const string&) const;
//		void searchAuthorOrArtist(const string&) const;
//		void print() const;
//
//	private:
//		list<const EMedia*> mediaList_;
//		char* namePtr_;
//	};
//
//	//#include "EMediaShop.h"
//
//	EMediaShop::EMediaShop(const char* name)
//	{
//		namePtr_ = new char[strlen(name) + 1];
//		strcpy_s(namePtr_, strlen(name) + 1, name);
//	}
//
//	EMediaShop::~EMediaShop()
//	{
//		delete[] namePtr_;
//	}
//
//	void EMediaShop::addEMedia(const EMedia& emedia)
//	{
//		mediaList_.push_back(&emedia);
//	}
//
//	void EMediaShop::searchTitle(const string&) const
//	{
//
//	}
//
//	void EMediaShop::searchAuthorOrArtist(const string& name) const
//	{
//		bool found = false;
//		for (auto iter = mediaList_.cbegin(); iter != mediaList_.cend(); iter++) {
//			if ((*iter)->getAuthorOrArtist() == name) {
//				(*iter)->print();
//				found = true;
//			}
//		}
//
//		if (found == false) {
//			cout << "DEr blev ikke fundet en bog eller album med den ønskede forfatter eller kunstner" << endl;
//		}
//	}
//
//	void EMediaShop::print() const
//	{
//		cout << "Butiksnavn: " << namePtr_ << endl;
//		for (auto iter = mediaList_.cbegin(); iter != mediaList_.cend(); iter++) {
//			(*iter)->print();
//		}
//	}
//
//
//
//
//
//
////Opgave 3B
//
//	//#include "EBook.h"
//	//#include "MusicAlbum.h"
//	//#include "EMediaShop.h"
//
//	int main() {
//		EBook book("Krimi", "Mord i Natten", "Slemme Kurt", 240);
//		MusicAlbum music("Lort", "Lorten", "Lortsen", 40);
//
//		EMediaShop l("My");
//
//		l.addEMedia(book);
//		l.addEMedia(music);
//
//		l.searchAuthorOrArtist("Lortsen");
//		l.searchAuthorOrArtist("k");
//		l.print();
//
//		return 0;
//	}
//
//
////Opgave 3C
//	void operator+=(const EMedia & media);
//
//	void EMediaShop::operator+=(const EMedia& media) {
//		addEMedia(media);
//	}
//
//
////Opgave 3D
//	//#include "EBook.h"
//	//#include "MusicAlbum.h"
//	//#include "EMediaShop.h"
//
//	int main() {
//		EBook book("Krimi", "Mord i Natten", "Slemme Kurt", 240);
//		MusicAlbum music("Lort", "Lorten", "Lortsen", 40);
//
//		EMediaShop l("My");
//
//		l += book;
//		l += music;
//		l.print();
//
//		return 0;
//	}