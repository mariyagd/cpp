#include <iostream>
#include "Sample1.class.hpp"

/*
 * this->a1 = p1;
 * L'attribut a1 de l'instance courante prend la
 * valeur du paramètre p1.
 */

Sample1::Sample1( char p1, int p2, float p3 ) {

	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1: " << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "this->a2: " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this->a3: " << this->a3 << std::endl;

	return;
}

Sample1::~Sample1( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}
