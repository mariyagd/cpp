#include "Sample1.class.hpp"
#include <iostream>

/*
 * NE MARCHE PAS
 */

void	f0( void) {

	Sample1 instance;

	std::cout << "Number of instances : " << Sample1::getNbInst << std::endl;
	return;
}

void	f1( void ){

	Sample1 instance;

	std::cout << "Number of instances : " << Sample1::getNbInst << std::endl;
	f0();
	return;
}

int main(void)
{

	std::cout << "Number of instances : " << Sample1::getNbInst << std::endl;
	f1();
	std::cout << "Number of instances : " << Sample1::getNbInst << std::endl;

	return 0;
}


