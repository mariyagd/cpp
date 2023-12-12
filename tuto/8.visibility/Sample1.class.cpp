#include <iostream>
#include "Sample1.class.hpp"

/*
 * Dans le constructeur, je peux utiliser
 * les attributs privés et publiques.
 */

Sample1::Sample1( void ) {

	std::cout << "Constructor called" << std::endl;
	this->publicFoo = 0;
	std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample1::publicBar (void ) const {

	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Sample1::_privateBar() const {

	std::cout << "Member function _privateBar called" << std::endl;
	return;
}