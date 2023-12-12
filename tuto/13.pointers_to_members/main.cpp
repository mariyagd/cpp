#include "Sample1.class.hpp"
#include <iostream>

/*
 * int 	Sample1::*p = NULL;
 * ici je déclare un pointeur sur un entier
 * qui est de la classe Sample1. Ce pointeur
 * est initialisé à NULL;
 *
 * p = &Sample1::foo;
 * j'assigne  l'adresse de foo à la variable p;
 *
 * instance.*p = 21;
 * ici j'assigne la valeur 21 au compte tenu du poointeur p
 * de l'instance "instance.
 *
 * 	void	(Sample1::*f)( void) const;
 * 	est pointeur vers une fonction en précisant
 * 	à quelle classe elle appartient
 *
 * 		f = &Sample1::bar;
 * 	le pointeur f va pointer vers la fonction bar
 * 	de la classe Sample1. Mais je ne sais pas à
 * 	quelle instance je fais référence.
 *
 * 	donc j'uitlise les opérateur point . et flèche ->
 */



int main(void)
{
	Sample1 	instance;
	Sample1 * 	instancep = &instance; // pointeur vrs l'adresse de instance

	int 	Sample1::*p = NULL;
	void	(Sample1::*f)( void) const;

	p = &Sample1::foo;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	f = &Sample1::bar;
	(instance.*f)();
	(instancep->*f)();

	return 0;
}


