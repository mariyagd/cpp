#include "Sample1.class.hpp"
#include <iostream>

/*
 * 	if (&instance1 == &instance1) -> on compare les adresses
 * 	if (instance1.compare(&instance2) == 0) -> on compare les valeurs
 */

int main(void)
{
	Sample1 instance1 (42);
	Sample1 instance2 (42);

	if (&instance1 == &instance1)
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not physically equal" << std::endl;
	if (&instance1 == &instance2)
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;

	if (instance1.compare(&instance1) == 0)
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not physically equal" << std::endl;
	if (instance1.compare(&instance2) == 0)
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;
	return 0;
}


