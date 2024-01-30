#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <iomanip>
#include <string>

#define BLUE	"\033[1;34m"
#define END		"\033[0m"
# define RED	"\033[1;31m"


void	print_smsome_line( void ) {

	std::cout << BLUE << std::setw(15) << std::setfill('-') << "" << END << std::endl;
}

void	print_line( void ) {

	std::cout << BLUE << std::setw(100) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');
}

void	print_title ( void )
{
	print_line();

	std::cout	<< BLUE
				 << std::left << std::setw(29) << "Operation  "
				 << std::left << std::setw(60) << " Content"
				 << "Size"
				 << END << std::endl;

	print_line();
}

int	main(void) {

	print_title();
	{
		Array<int> array(5);
		std::cout	<< std::left << std::setw(30) << "Array<int> array[5]" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		try
		{
			array.setElement(0, 4);
			array.setElement(1, 6);
			array.setElement(2, 9);
			array.setElement(3, 7);
			array.setElement(4, 8);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< std::left << std::setw(30) << "Set all elements" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		Array<int> copy(array);
		std::cout	<< std::left << std::setw(30) << "Copy array" << copy
					<< std::setw(10) << std::setfill(' ') << "" << copy.size() << std::endl;

		Array<int> a;
		std::cout	<< std::left << std::setw(30) << "Array a before assignment" << a
					<< std::setw(10) << std::setfill(' ') << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(30) << "Array a after assignment" << a
					<< std::setw(10) << std::setfill(' ') << "" << a.size() << std::endl;

		std::cout	<< std::endl << std::left << std::setw(30) << "Set value at index 5 (out of bounds)" << std::endl;
		try
		{
			array.setElement(5, 2);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
		Array<float> array(5);
		std::cout	<< std::left << std::setw(30) << "Array<float> array[5]" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		try
		{
			array.setElement(0, 4.5f);
			array.setElement(1, 6.5f);
			array.setElement(2, 9.5f);
			array.setElement(3, 7.5f);
			array.setElement(4, 8.5f);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< std::left << std::setw(30) << "Set all elements" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		Array<float> copy(array);
		std::cout	<< std::left << std::setw(30) << "Copy array" << copy
					<< std::setw(10) << std::setfill(' ') << "" << copy.size() << std::endl;

		Array<float> a;
		std::cout	<< std::left << std::setw(30) << "Array a before assignment" << a
					<< std::setw(21) << std::setfill(' ') << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(30) << "Array a after assignment" << a
					<< std::setw(10) << std::setfill(' ') << "" << a.size() << std::endl;

		std::cout	<< std::endl << std::left << std::setw(30) << "Set value at index 6 (out of bounds)" << std::endl;
		try
		{
			array.setElement(6, 2.5f);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
		Array<double> array(5);
		std::cout	<< std::left << std::setw(30) << "Array<double> array[5]" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		try
		{
			array.setElement(0, 4.5);
			array.setElement(1, 6.5);
			array.setElement(2, 9.5);
			array.setElement(3, 7.5);
			array.setElement(4, 8.5);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< std::left << std::setw(30) << "Set all elements" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		Array<double> copy(array);
		std::cout	<< std::left << std::setw(30) << "Copy array" << copy
					<< std::setw(10) << std::setfill(' ') << "" << copy.size() << std::endl;

		Array<double> a;
		std::cout	<< std::left << std::setw(30) << "Array a before assignment" << a
					<< std::setw(21) << std::setfill(' ') << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(30) << "Array a after assignment" << a
					<< std::setw(10) << std::setfill(' ') << "" << a.size() << std::endl;

		std::cout	<< std::endl << std::left << std::setw(30) << "Set value at index 6 (out of bounds)" << std::endl;
		try
		{
			array.setElement(6, 2.5);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
		Array<std::string> array(5);
		std::cout	<< std::left << std::setw(30) << "Array<std::string> array[5]"
					<< array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		try
		{
			array.setElement(0, "aa");
//			array.setElement(1, "bb");
			array.setElement(2, "cc");
//			array.setElement(3, "dd");
			array.setElement(4, "ee");
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< std::left << std::setw(30) << "Set some elements" << array
					<< std::setw(10) << std::setfill(' ') << "" << array.size() << std::endl;

		Array<std::string> copy(array);
		std::cout	<< std::left << std::setw(30) << "Copy array" << copy
					<< std::setw(10) << std::setfill(' ') << "" << copy.size() << std::endl;

		Array<std::string> a;
		std::cout	<< std::left << std::setw(30) << "Array a before assignment" << a
					<< std::setw(51) << std::setfill(' ') << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(30) << "Array a after assignment" << a
					<< std::setw(10) << std::setfill(' ') << "" << a.size() << std::endl;

		std::cout	<< std::endl << std::left << std::setw(30) << "Set value at index 5 (out of bounds)" << std::endl;
		try
		{
			array.setElement(5, "ff");
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_line();

}