#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <iomanip>
#include <string>

#define BLUE		"\033[1;34m"
#define END			"\033[0m"
#define RED			"\033[1;31m"

# define GREEN		"\033[42m"
# define YELLOW		"\033[43m"




void	print_small_line( void ) {

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
				 << std::left << std::setw(33) << "Operation  "
				 << std::left << std::setw(47) << " Content"
				 << "Size"
				 << END << std::endl;

	print_line();
}

int	main(void) {

	print_title();
	{
// Original Array<int> ------------------------------------------------------------------------------------------------------------------------

		Array<int> array(5);
		std::cout	<< std::left << std::setw(35) << "Array<int> array[5]"
					<< array << std::setw(10) << ""
					<< array.size() << std::endl;

// Set elements Array<int> --------------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = 4;
			array[1] = 6;
			array[2] = 9;
			array[3] = 7;
			array[4] = 8;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Set all elements"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;

// Copy Array<int> -----------------------------------------------------------------------------------------------------------------------------

		Array<int> copy(array);
		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

// Change original Array<int> -------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = 1;
			array[1] = 1;
			array[2] = 1;
			array[3] = 1;
			array[4] = 1;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Modifying original array"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;

		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array should not change"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

// Assign Array<int> ----------------------------------------------------------------------------------------------------------------------------

		Array<int> a;
		std::cout	<< std::left << std::setw(35) << "Array a before assignment" << a
					<< std::setw(36) << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(35) << "Array a after assignment" << a
					<< std::setw(10) << "" << a.size() << std::endl;

// Out of range Array<int> ----------------------------------------------------------------------------------------------------------------------------

		std::cout	<< std::endl << "Set value at index 5 (out of bounds)" << std::endl;
		try
		{
			array[5] = 2;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
// Original Array<float> ------------------------------------------------------------------------------------------------------------------------

		Array<float> array(5);
		std::cout	<< std::left << std::setw(35) << "Array<float> array[5]" << array
					<< std::setw(10) << "" << array.size() << std::endl;

// Set elements Array<float> --------------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = 4.5f;
			array[1] = 6.5f;
			array[2] = 9.5f;
			array[3] = 7.5f;
			array[4] = 8.5f;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Set all elements" << array
					<< std::setw(10) << "" << array.size() << END << std::endl;

// Copy Array<float>  -----------------------------------------------------------------------------------------------------------------------------

		Array<float> copy(array);
		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array" << copy
					<< std::setw(10) << "" << copy.size() << END << std::endl;

// Change COPY Array<float>  -------------------------------------------------------------------------------------------------------------------

		try
		{
			copy[0] = 1;
			copy[1] = 1;
			copy[2] = 1;
			copy[3] = 1;
			copy[4] = 1;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< YELLOW << std::left << std::setw(35) << "Modyfing COPY array"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

		std::cout	<< GREEN << std::left << std::setw(35) << "Original should not change"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;


// Assign Array<float>  ----------------------------------------------------------------------------------------------------------------------------

		Array<float> a;
		std::cout	<< std::left << std::setw(35) << "Array a before assignment" << a
					<< std::setw(36) << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(35) << "Array a after assignment" << a
					<< std::setw(10) << "" << a.size() << std::endl;

// Out of range Array<float> ----------------------------------------------------------------------------------------------------------------------------

		std::cout	<< std::endl << "Set value at index 6 (out of bounds)" << std::endl;
		try
		{
			array[6] =  2.5f;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{

// Original Array<double> ------------------------------------------------------------------------------------------------------------------------

		Array<double> array(5);
		std::cout	<< std::left << std::setw(35) << "Array<double> array[5]" << array
					<< std::setw(10) << "" << array.size() << std::endl;

// Set elements Array<double> --------------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = 4.5;
			array[1] = 6.5;
			array[2] = 9.5;
			array[3] = 7.5;
			array[4] = 8.5;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Set all elements" << array
					<< std::setw(10) << "" << array.size() << END << std::endl;

// Copy Array<double>  -----------------------------------------------------------------------------------------------------------------------------

		Array<double> copy(array);
		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array" << copy
					<< std::setw(10) << "" << copy.size() << END << std::endl;

// Change original Array<double> -------------------------------------------------------------------------------------------------------------------

try
		{
			array[0] = 0.5;
			array[1] = 0.5;
			array[2] = 0.5;
			array[3] = 0.5;
			array[4] = 0.5;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Modifying original array"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;

		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array should not change"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

// Change COPY Array<double>  -------------------------------------------------------------------------------------------------------------------

		try
		{
			copy[0] = 4.4;
			copy[1] = 4.4;
			copy[2] = 4.4;
			copy[3] = 4.4;
			copy[4] = 4.4;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< YELLOW << std::left << std::setw(35) << "Modyfing COPY array"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

		std::cout	<< GREEN << std::left << std::setw(35) << "Original should not change"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;


// Assign Array Array<double> ----------------------------------------------------------------------------------------------------------------------------

		Array<double> a;
		std::cout	<< std::left << std::setw(35) << "Array a before assignment" << a
					<< std::setw(36) << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(35) << "Array a after assignment" << a
					<< std::setw(10) << "" << a.size() << std::endl;

// Out of range Array<double> ----------------------------------------------------------------------------------------------------------------------------

		std::cout	<< std::endl << "Set value at index 6 (out of bounds)" << std::endl;
		try
		{
			array[6] = 2.5;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
// Original Array<std::string> ------------------------------------------------------------------------------------------------------------------------

		Array<std::string> array(5);
		std::cout	<< std::left << std::setw(35) << "Array<std::string> array[5]"
					<< array
					<< std::setw(10) << "" << array.size() << std::endl;

// Set elements Array<std::string> --------------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = "aa";
			array[2] = "cc";
			array[4] = "ee";
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Set some elements" << array
					<< std::setw(10) << "" << array.size() << END << std::endl;

 // Copy Array Array<std::string> -----------------------------------------------------------------------------------------------------------------------------

		Array<std::string> copy(array);
		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array" << copy
					<< std::setw(10) << "" << copy.size() << END << std::endl;

// Change original Array<std::string> -------------------------------------------------------------------------------------------------------------------

		try
		{
			array[1] = "bb";
			array[3] = "dd";
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< GREEN << std::left << std::setw(35) << "Modifying original array"
					<< array << std::setw(10) << ""
					<< array.size() << END << std::endl;

		std::cout	<< YELLOW << std::left << std::setw(35) << "Copy array should not change"
					<< copy << std::setw(10) << ""
					<< copy.size() << END << std::endl;

// Assign Array Array<std::string> ----------------------------------------------------------------------------------------------------------------------------

		Array<std::string> a;
		std::cout	<< std::left << std::setw(35) << "Array a before assignment" << a
					<< std::setw(36) << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(35) << "Array a after assignment" << a
					<< std::setw(10) << "" << a.size() << std::endl;

// Out of range Array<std::string> ----------------------------------------------------------------------------------------------------------------------------

		std::cout	<< std::endl << "Set value at index 5 (out of bounds)" << std::endl;
		try
		{
			array[5] = "ff";
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_title();
	{
// Original Array<bool> ------------------------------------------------------------------------------------------------------------------------

		Array<bool> array(5);
		std::cout	<< std::left << std::setw(35) << "Array<bool> array[5]"
					 << array
					 << std::setw(7) << "" << array.size() << std::endl;

// Set elements Array<bool> --------------------------------------------------------------------------------------------------------------------------

		try
		{
			array[0] = true;
			array[2] = true;
			array[4] = true;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout	<< std::left << std::setw(35) << "Set some elements" << array
					 << std::setw(10) << "" << array.size() << std::endl;

 // Copy Array Array<bool> -----------------------------------------------------------------------------------------------------------------------------

		Array<bool> copy(array);
		std::cout	<< std::left << std::setw(35) << "Copy array" << copy
					 << std::setw(10) << "" << copy.size() << std::endl;

// Assign Array Array<bool> ----------------------------------------------------------------------------------------------------------------------------

		Array<bool> a;
		std::cout	<< std::left << std::setw(35) << "Array a before assignment" << a
					 << std::setw(38) << "" << a.size() << std::endl;

		a = array;
		std::cout	<< std::left << std::setw(35) << "Array a after assignment" << a
					 << std::setw(10) << "" << a.size() << std::endl;

// Out of range Array<bool> ----------------------------------------------------------------------------------------------------------------------------

		std::cout	<< std::endl << "Set value at index 5 (out of bounds)" << std::endl;
		try
		{
			array[5] = true;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	print_line();
	{
		int *a = new int();
		std::cout << *a << std::endl;
		delete a;
	}
}