#include <iostream>
#include <string>
#include "PmergeMe.hpp"
#include "PmergeMeList2.hpp"

int main( int ac, char **av )
{
	if (ac == 1)
	{
		std::cerr << RED_BOLD << "Invalid input" << END << std::endl;
		return 1;
	}
	std::string str(av[1]);
	try
	{
		PmergeMeList	p(av);
		p.startSortWithList();
	}
	catch ( const std::exception &e )
	{
		std::cerr << RED_BOLD << "Exception thrown: " << e.what() << END << std::endl;
		return 1;
	}
	return 0;
}