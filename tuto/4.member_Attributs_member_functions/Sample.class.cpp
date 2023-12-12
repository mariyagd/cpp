#include <iostream>
#include "Sample.class.hpp"

/* Dans la classe Sample, je souhaite accéder
 * à la fonction Sample qui est le constructeur
 *
 * Le constructeur et le destructeur n'ont pas de types de retour.
 *
 * La fonction membre a un type de retour.
 * */

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar( void ) {
	std::cout << "Member function bar called" << std::endl;
	return;
}