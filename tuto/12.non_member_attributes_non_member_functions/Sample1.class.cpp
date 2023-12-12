#include <iostream>
#include "Sample1.class.hpp"

/*
 * Sample1::_nbInst; -> pour un attribu non membre.
 *
 * int Sample1::_nbInst = 0; -> comme _nbInst
 * n'est pas membre, je vais l'initialiser dans
 * le constructeur. c'est la seule facon
 * d'initialiser un attribut statique (non membre)
 */

Sample1::Sample1( void ) {

	std::cout << "Constructor called" << std::endl;
	Sample1::_nbInst += 1;
	return;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	Sample1::_nbInst -= 1;
	return;
}

int	Sample1::getNbInst() {

	return Sample1::_nbInst;
}

int Sample1::_nbInst = 0;