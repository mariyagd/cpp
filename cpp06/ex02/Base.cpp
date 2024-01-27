#include "Base.hpp"

#include <iostream>

Base::~Base() {
	return;
}


A::A() : Base(){
	return;
}

A::~A() {
	return;
}

B::B() : Base() {
	return;
}

B::~B() {
	return;
}

C::C() : Base() {
	return;
}

C::~C() {
	return;
}

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

	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void	identify(Base &p) {

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;

	}
	catch (std::exception &e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "Class B" << std::endl;
		}
		catch (std::exception &e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "Class C" << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	return;
}
