#include "Stack.h"
#include <iostream>


int main() {
	Stack s1(5);
	s1 += 2;
	s1 += 5;
	
	std::cout << "Popper elementerne. Indsat 2 og saa 5" << std::endl;
	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;

	std::cout << "Popping an empty stack with catch" << std::endl;
	try {
		s1.pop();
		std::cout << "Popping element" << std::endl;
	}
	catch (StackPopException e) {
		std::cout << "You tried popping an empty stack" << std::endl;
	}

	return 0; 
}