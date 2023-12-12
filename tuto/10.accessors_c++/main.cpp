#include "Sample1.class.hpp"
#include <iostream>

/*
 */

int main(void)
{
	Sample1 instance;

	instance.setFoo( 42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	instance.setFoo( -42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

	return 0;
}


