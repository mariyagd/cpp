#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>

#define BLUE		"\033[1;34m"
#define END			"\033[0m"
#define BLUE_BG		"\033[44m"


void	print_small_line( void ) {

	std::cout << BLUE << std::setw(15) << std::setfill('-') << "" << END << std::endl;
}

void	print_line( void ) {

	std::cout << BLUE << std::setw(100) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');
}


int main( void ) {

	int search;
	int result;

	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::vector<int> c {1, 23, 42}" << END << std::endl;

		std::vector< int > c;
		c.push_back( 1 );
		c.push_back( 23 );
		c.push_back( 42 );

		search = 23;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::vector< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		search = 0;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::vector< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

	}

	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::deque<int> c {1, 23, 42}" << END << std::endl;

		std::deque< int > c;
		c.push_back( 1 );
		c.push_back( 23 );
		c.push_back( 42 );

		search = 23;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::deque< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		search = 0;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::deque< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::list<int> c {1, 23, 42}" << END << std::endl;

		std::list< int > c;
		c.push_back( 1 );
		c.push_back( 23 );
		c.push_back( 42 );

		search = 23;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::list< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		search = 0;
		try
		{
			std::cout << "search for: " << search << std::endl;
			result = easyfind<std::list< int > >( c, search );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	print_line();


}
