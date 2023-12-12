#include <iostream>
#include "Sample1.class.hpp"

/*
 */

Sample1::Sample1( int v ) {

	this->_foo = v;
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample1::getFoo( void ) const {

	return this->_foo;
}

int	Sample1::compare(Sample1 * other) const {

	if (this->_foo < other->getFoo())
		return -1;
	else if (this->_foo > other->getFoo())
		return 1;
	return 0;
}
