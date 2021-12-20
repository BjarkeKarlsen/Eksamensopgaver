#include "Movie.h"

Movie::Movie(string title, MoviePerson* directorPtr)
{
	title_ = title;
	directorPtr_ = directorPtr;
}

void Movie::hireActor(MoviePerson* actorPtr)
{
	actorPtrs_.push_back(actorPtr);
}

void Movie::print() const
{
	cout << "The Movie: " << title_ << endl;
	cout << "Directed by: " << directorPtr_->getName() << directorPtr_->getNumberOfOscars() << endl;
	cout << "Starring: " << endl;

	for (auto it = actorPtrs_.begin(); it != actorPtrs_.end(); ++it)
	{
		cout << " ";
		(*it)->print();
	}
}
