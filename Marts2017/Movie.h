#pragma once
#include "MoviePerson.h"
#include <vector>
class Movie
{
public:
	Movie(string title, MoviePerson* directorPtr);
	void hireActor(MoviePerson* actorPtr);
	void print() const;
private:
	string title_;
	MoviePerson* directorPtr_;
	vector<MoviePerson*> actorPtrs_;

};

