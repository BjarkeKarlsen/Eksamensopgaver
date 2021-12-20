#include "EBook.h"
#include "MusicAlbum.h"
#include "EMediaShop.h"

int main() {
	EBook book("Krimi", "Mord i Natten", "Slemme Kurt", 240);
	MusicAlbum music("Lort", "Lorten", "Lortsen", 40);

	EMediaShop l("My");

	l += book;
	l += music;
	l.print();

	return 0;
}