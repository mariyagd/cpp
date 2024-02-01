
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

void	try_longest(const Span & sp) {
	try
	{
		std::cout << BLUE << std::endl << "Longest" << END << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const Span::SpanException &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
}

void try_shortest( const Span & sp )
{
	try
	{
		std::cout << BLUE << std::endl << "Shortest" << END << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const Span::SpanException &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
}

void try_addNumber( Span & sp, int num )
{
	try
	{
		sp.addNumber(num);
	}
	catch (const Span::SpanException &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
}

int main(void) {
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

		std::cout << sp;

		sp.shortestSpan();
		sp.longestSpan();
	}
	print_line();
	{
		std::cout << BLUE << "Test operators" << END << std::endl;
		print_line();

		Span sp(20);
		for (int i = 0; i < 10; i++)
		{
			sp.addNumber(rand() % 10);
		}
		std::cout << std::left << std::setw(20) << "Span" << sp;

		Span copy(sp);
		std::cout << std::left << std::setw(20) << "Copy" << copy;

		Span assign;
		std::cout << std::left << std::setw(20) << "Default" << assign;

		assign = sp;
		std::cout << std::left << std::setw(20) << "Assign" << assign;

	}
	print_line();
	{
		std::cout << BLUE << "Test exceptions" << END << std::endl;
		print_line();

		Span sp(1);
		std::cout << BLUE << "Span" << END << std::endl << sp;

		// Tests will fail because the span is empty---------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		try_longest(sp);
		try_shortest(sp);

		// Add one number and test --------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		std::cout << BLUE << std::endl << "Add number" << END << std::endl;

		try_addNumber(sp, 35);

		std::cout << sp;

		try_longest(sp);
		try_shortest(sp);

		// Add another number, test will fail because max size is 1------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		std::cout << BLUE << std::endl << "Add number" << END << std::endl;
		try_addNumber(sp, 98);
	}
	print_line();
	{
		std::cout << BLUE << "Test on addRange" << END << std::endl;
		print_line();

		const unsigned int size = 10;

		// Span 1--------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		Span sp1(size);

		for (unsigned int i = 0; i < size; i++)
		{
			try_addNumber(sp1, i + 1 );
		}

		std::cout << BLUE << "Span 1" << END << std::endl << sp1;


		// Span 2 takes the whole range of Span 1 because hase the same size---------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		Span sp2(size);

		std::cout << BLUE << std::endl << "Span 2" << END << std::endl << sp2;

		std::cout << BLUE << std::endl << "Add the whole range of Span1 in Span2. Span2 becomes:" << END << std::endl;
		try
		{
			sp2.addRange(sp1.getVector().begin(), sp1.getVector().end());
		}
		catch (const Span::SpanException &e)
		{
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << sp2;


		// Span 3 can't take the whole range, so it will throw an exception---------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		Span sp3(size / 2);

		std::cout << BLUE << std::endl << "Span 3" << END << std::endl << sp3;
		std::cout << BLUE << std::endl << "Add the whole range of Span1 in Span3. Span3 becomes:" << END << std::endl;

		try
		{
			sp3.addRange(sp1.getVector().begin(), sp1.getVector().end());
		}
		catch (const Span::SpanException &e)
		{
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << sp3;

		// So we will try to add the first half of the range of Span1 ---------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------
		std::cout << BLUE << std::endl << "Add the first half of the range of Span1 in Span3. Span3 becomes:" << END << std::endl;

		try
		{
			sp3.addRange(sp1.getVector().begin(), sp1.getVector().end() - size / 2);
		}
		catch (const Span::SpanException &e)
		{
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << sp3;

	}
	print_line();
	{
		std::cout << BLUE << "Test on occurrences" << END << std::endl;
		print_line();

		// If there are occurrences, shortest distance will be 0
		const unsigned int size = 6;
		Span sp(size);

		try_addNumber(sp, 10);
		try_addNumber(sp, 80);
		try_addNumber(sp, 30);
		try_addNumber(sp, 100);
		try_addNumber(sp, 0);
		try_addNumber(sp, 100);

		std::cout << BLUE << "Span" << END << std::endl << sp;

		try_longest(sp);
		try_shortest(sp);

	}
	print_line();
	{
		std::cout << BLUE << "Span with size 10'000" << END << std::endl;
		print_line();

		const unsigned int size = 10000;
		Span sp(size);

		std::vector< int > v;
		for (unsigned int i = 0; i < size; i++)
		{
			v.push_back(i);
		}

		sp.addRange(v.begin(), v.end());
		std::cout << BLUE "Span" << END << std::endl << sp;

		try_longest(sp);
		try_shortest(sp);
	}
	return 0;
}