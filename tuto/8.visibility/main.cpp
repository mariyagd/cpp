#include "Sample1.class.hpp"
#include <iostream>

/*
 * On ne peux pas avoir acces aux attributs privés
 * depuis le main
 */

int main(void)
{
	Sample1 instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;

	instance.publicBar();

//	instance._privateFoo= 42;
//	std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;
//	instance._privateBar;

	return 0;
}


