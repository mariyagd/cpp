#include "ScalarConverter.hpp"
#include <sstream>      // std::istringstream

# define ITALIC		"\033[2;3m"
# define BLUE		"\033[1;34m"
# define BOLD		"\033[1m"

int main( int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "This program takes only one parameter" << std::endl;
		return 1;
	}
	(void)av;

	std::string s1(av[1]);
	try
	{
		ScalarConverter::convert(s1);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
}