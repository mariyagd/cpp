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
//	std::cout << "full string: \"" << s1 << "\"" << std::endl;
	try
	{
		ScalarConverter::convert(s1);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}

//	std::stringstream min;
//	std::stringstream max;
//
//	min << std::numeric_limits<int>::min();
//	max << std::numeric_limits<int>::max();
//
//	std::string s = "1256";
//	std::string s2 = "-2147483648";
//
//	int a;
//
//	std::istringstream sA(s);
//	sA >> a;
//
//	std::cout << "a = " << a << std::endl;
//
//	std::cout << "max " << max.str() << std::endl;
//	std::cout << "min " << min.str() << std::endl;
//	std::cout << s << " " << (s > max.str() ? "overflow" : "int") << std::endl;
//	std::cout << s2 << " " << (s2 > min.str() ? "NOTint" : "int") << std::endl;
}