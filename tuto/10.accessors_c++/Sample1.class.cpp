#include <iostream>
#include "Sample1.class.hpp"

/*
 */

Sample1::Sample1( void ) {

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

/*
 * L'utilisateur pourra modifier la valeur de _foo
 * mais elle ne pourra pas être négative.
 */

void	Sample1::setFoo(int v) {

	if (v >= 0)
		this->_foo = v;
	return;
}
