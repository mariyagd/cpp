#include "Sample1.class.hpp"
#include "Sample2.class.hpp"
#include <iostream>

/*
 * On ne peux pas avoir acces aux attributs privés
 * depuis le main
 */

int main(void)
{
	Sample1 instance; // structure
	Sample2 instance2; //classe

	instance2.foo = 4;

	return 0;
}


