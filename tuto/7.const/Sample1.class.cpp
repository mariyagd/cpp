#include <iostream>
#include "Sample1.class.hpp"

/*
 * L'attribut pi sera initialisé à la valeur f
 * du constructeur. et la veluer de qd est initialisé à 42.
 */

Sample1::Sample1( float const f ) : pi( f ), qd ( 42 ) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

/*
 * A noter la place de const -> pas de modifications de valeurs
 */

void	Sample1::bar (void ) const {

	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
}