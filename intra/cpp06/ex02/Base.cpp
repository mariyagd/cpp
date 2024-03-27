#include "Base.hpp"

#include <iostream>

Base*	generate( void ) {

	int randNumber = rand() % 3;

	switch (randNumber)
	{
		case 0 :
			return new A;
		case 1 :
			return new B;
		case 2 :
			return new C;
		default :
			return 0;
	}
}


void	identify(Base *p) {

	int i = 0;

	if (p == nullptr)
	{
		std::cout << "Null pointer doesn't point to an instance of a class" << std::endl;
		return;
	}
	if (dynamic_cast<A *>(p) != nullptr) {
		std::cout << "Class A ";
		i++;
	}
	if (dynamic_cast<B *>(p) != nullptr) {
		std::cout << "Class B ";
		i++;
	}
	if (dynamic_cast<C *>(p) != nullptr) {
		std::cout << "Class C ";
		i++;
	}
	switch (i) {
		case 0 : // unknown
			std::cout << "Unknown: Base class or another class derived from Base" << std::endl;
			return;
		case 1 : // A, B, or C
			std::cout << std::endl;
			return;
		default: // multiple inheritance
			std::cout << ": Unknown: multiple inheritance" << std::endl;
	}
	return;
}

void	identify(Base &p) {

	int i = 0;
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "Class A ";
		i++;
	}
	catch (const std::bad_cast &e) {}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Class B ";
		i++;
	}
	catch (const std::bad_cast &e) {}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Class C ";
		i++;
	}
	catch (const std::bad_cast &e) {}

	switch (i)
	{
		case 0 : 	// unknown
			std::cout << "Unknown: Base class or another class derived from Base" << std::endl;
			return;
		case 1 : 	// A, B, or C
			std::cout << std::endl;
			return;
		default: 	// multiple inheritance
			std::cout << ": Unknown: multiple inheritance" << std::endl;
	}
	return;
}