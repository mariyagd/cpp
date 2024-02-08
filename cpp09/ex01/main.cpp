#include <iostream>
#include <string>
#include "RPN.hpp"
#include <string.h>

int main( int ac, char **av )
{
	if ( ac != 2)
	{
		std::cerr << "This program takes one argument" << std::endl;
		return 1;
	}
	if ( strlen(av[1]) == 0 )
	{
		std::cerr << "Empty argument" << std::endl;
		return 1;
	}
	std::string str(av[1]);
	try
	{
		Rpn rpn( str );
		std::cout << rpn;
	}
	catch ( const std::runtime_error &e )
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;

}


