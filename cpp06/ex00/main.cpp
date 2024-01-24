#include "ScalarConverter.hpp"

int main( int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "This program takes only one parameter" << std::endl;
		return 1;
	}
	std::string scalar(av[1]);
	ScalarConverter::convert( scalar );

}