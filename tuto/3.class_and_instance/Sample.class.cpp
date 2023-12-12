#include <iostream>
#include "Sample.class.hpp"

/* Dans la classe Sample, je souhaite accéder
 * à la fonction Sample qui est le constructeur
 *
 * Le constructeur est le destructeur n'ont pas de types de retour
 * */

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}