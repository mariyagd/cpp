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


// (Note: an implicit conversion and static_cast can perform this conversion as well.)
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
		case 0 :
			std::cout << "Unknown: Base class or another derived class" << std::endl;
			return;
		case 1 :
			std::cout << std::endl;
			return;
		default:
			std::cout << ": Unknown: multiple inheritance" << std::endl;
	}
	return;
}

// (Note: an implicit conversion and static_cast can perform this conversion as well.)
void	identify(Base &p) {

	int i = 0;
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "Class A ";
		i++;
	}
	catch (std::exception &e) {}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "Class B ";
		i++;
	}
	catch (std::exception &e) {}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "Class C ";
		i++;
	}
	catch (std::exception &e) {}

	switch (i) {
		case 0 :
			std::cout << "Unknown: Base class or another derived class" << std::endl;
			return;
		case 1 :
			std::cout << std::endl;
			return;
		default:
			std::cout << ": Unknown: multiple inheritance" << std::endl;
	}
	return;
}

/*
//A downcast can also be performed with static_cast, 
// which avoids the cost of the runtime check, 
// but it's only safe if the program can guarantee 
// (through some other logic) that the object pointed 
// to by expression is definitely Derived.

void	identify(Base *p) {

	if (p == nullptr)
		std::cout << "Null pointer doesn't point to an instance" << std::endl;
	else if (static_cast<A*>(p) != nullptr)
		std::cout << "Class A" << std::endl;
	else if (static_cast<B*>(p) != nullptr)
		std::cout << "Class B" << std::endl;
	else if (static_cast<C*>(p) != nullptr)
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Class Base" << std::endl;
}


void	identify(Base &p) {

	try {
		(void) static_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (std::exception &e) {
		try {
			(void) static_cast<B &>(p);
			std::cout << "Class B" << std::endl;
		}
		catch (std::exception &e) {
			try {
				(void) static_cast<C &>(p);
				std::cout << "Class C" << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Class Base" << std::endl;
			}
		}
	}
	return;
}
*/

