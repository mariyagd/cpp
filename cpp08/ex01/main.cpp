#include "Span.hpp"
#include <iostream>
#include <iomanip>

#define BLUE		"\033[1;34m"
#define END			"\033[0m"
#define BLUE_BG		"\033[44m"
#define RED			"\033[1;31m"



void	print_small_line( void ) {

	std::cout << BLUE << std::setw(20) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');

}

void	print_line( void ) {

	std::cout << BLUE << std::setw(100) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');
}


int main(void)
{
	print_line();
	{
		std::cout << BLUE << "Subject test" << END << std::endl;
		print_line();

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	print_line();
	{
		std::cout << BLUE << "Test on operators" << END << std::endl;
		print_line();

		std::cout	<< BLUE << std::left << std::setw(20) << "Type"
					<< std::setw(20) << "Content"
					<< std::setw(20)<< " Longest"
					<< std::setw(20)<< " Shortest" << END << std::endl;


		Span sp(10);
		std::cout << std::left << std::setw(20) << "Original" << sp;
		try
		{
			std::cout << std::left << std::setw(20) << sp.longestSpan() << std::endl;
		}
		catch (const Span::SpanException &e)
		{
			std::cerr << RED << e.what() << END << std::endl;
		}
		try
		{
			std::cout << std::left << std::setw(20) << sp.shortestSpan() << std::endl;
		}
		catch (const Span::SpanException &e)
		{
			std::cerr << RED << e.what() << END << std::endl;
		}
//		for (int i = 0; i < 10; i++)
//		{
//			sp.addNumber(rand() % 10);
//		}
//		std::cout << std::left << std::setw(20) << "Original addNumber" << ": " << sp;
//
//		Span copy(sp);
//		std::cout << std::left << std::setw(20) << "Copy" << ": "  << copy;
//
//		Span assign;
//		std::cout << std::left << std::setw(20) << "Default" << ": " << assign;
//
//		assign = sp;
//		std::cout << std::left << std::setw(20) << "Assign" << ": " << assign;

	}
	print_line();
//	{
//		std::cout << BLUE << "Span with 10'000 numbers" << END << std::endl;
//		print_line();
//
//		const unsigned int size = 10000;
//		Span sp(size);
//		std::cout << std::left << std::setw(20) << "Original" << ": " << sp;
//
//		for (unsigned int i = 0; i < size; i++)
//		{
//			sp.addNumber(rand() % size);
//		}
//		std::cout << std::left << std::setw(20) << "Original addNumber" << ": " << sp;
//	}
	return 0;
}