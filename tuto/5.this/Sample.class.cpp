#include <iostream>
#include "Sample.class.hpp"

/* Dans la classe Sample, je souhaite accéder
 * à la fonction Sample qui est le constructeur
 *
 * Le constructeur et le destructeur n'ont pas de types de retour.
 *
 * La fonction membre a un type de retour.
 *
 * Si la classe a des attributs, il est préférable de
 * les initialiser dans le constructeur.
 *
 * Le mot-clé "this" est un pointeur qui point sur l'instance
 * courante.
 *
 * this->bar permet d'appeler une fonction membre bar
 * directement à partir du pointeur
 * */

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;

	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();
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