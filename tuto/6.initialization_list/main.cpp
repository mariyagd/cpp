#include "Sample1.class.hpp"
#include "Sample2.class.hpp"
#include <iostream>

/*
 * Deux manières d'assigner les attributs
 * de la classe.
 *
 * Il faut faire comme dans la classe Sample2
 */

int main(void)
{
	Sample1 instance('b', 43, 3.15);
	Sample2 instance2('a', 42, 3.14);

	return (0);
}


