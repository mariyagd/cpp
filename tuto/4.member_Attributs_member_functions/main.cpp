#include "Sample.class.hpp"
#include <iostream>

/*
 * Variable "instance" est une instance de la classe Sample
 * En instanciant la classe Sample, je fais automatiquement
 * un appel au constructeur, et le code dans le constructeur
 * va être exécuté.
 *
 * En C, lorsque je sors d'une fonction, toutes les
 * variables locales sont détruites. Donc pour détruire
 * la variable "instance", le destructeur sera appelé et
 * son code sera exécuté.
 */

int main(void)
{
	Sample instance;

	instance.foo = 42;
	std::cout << "instance.foo: " << instance.foo << std::endl;
	instance.bar();
	return (0);
}


