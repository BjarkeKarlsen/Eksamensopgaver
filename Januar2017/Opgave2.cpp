#include "Shape.h"
#include "Rectangle.h"
#include <vector>

int main()
{
	//opgave 2a
	 Shape obj1(2, 4); // vil selvfølgelig ikke lade den compilere da klassen er abstrakt

	//opgave 2c
	
	Rectangle obj(3, 4, 10, 40);
	obj.draw();
	obj.move(5, 6);
	obj.setSides(50, 60);
	obj.draw();
	

	//opgave 2d
	vector<Shape*>objekter;
	objekter.push_back(new Rectangle(5, 6, 10, 20));
	objekter.push_back(new Rectangle(7, 6, 15, 20));
	objekter.push_back(new Rectangle(3, 2, 19, 20));

	for (vector<Shape*>::iterator i = objekter.begin(); i != objekter.end(); i++)
		(*i)->draw();



	return 0;
}