#include <iostream>
#include "Sample1.class.hpp"

/*
 * Dans le constructeur, je peux utiliser
 * les attributs privés et publiques.
 */

Sample1::Sample1( void ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample1::bar( void ) const {

	std::cout << "Member function called" << std::endl;
	return;
}
