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


	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::vector<int> c" << END << ": ";

		std::vector< int > c;

		// test on empty container
		TestEmptyContainer< std::vector< int > > test_empty;
		test_empty(c);

		print_line();

		std::cout << BLUE_BG << std::left << std::setw(20) << "std::vector<int> c" << END << ": ";
		size_t 	size = rand() % 10 + 1;
		TestSequenceContainer<std::vector< int > > 	test_and_print;

		test_and_print(c, size);
	}

	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::deque<int> c" << END << ": ";

		std::deque< int > c;
		size_t 	size = rand() % 10 + 1;


		TestSequenceContainer<std::deque< int > > test_and_print;

		test_and_print(c, size);
	}

	print_line();
	{
		std::cout << BLUE_BG << std::left << std::setw(20) << "std::list<int> c" << END << ": ";

		std::list< int > c;
		size_t 	size = rand() % 10 + 1;


		TestSequenceContainer<std::list< int > > test_and_print;

		test_and_print(c, size);
	}
	print_line();


}
