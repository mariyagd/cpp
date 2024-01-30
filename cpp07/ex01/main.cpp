#include <iostream>
#include <iomanip>
#include "iter.hpp"

void	print_small_line( void ) {

	std::cout << std::setfill('-') << std::setw(15) << "" << std::endl;
}

void	print__line( void ) {

	std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
}

void	ft_int_array(int & i)
{
	i = 65;
	(void)i;
	return;
}

void	ft_string_array(std::string& s) {

	s.append("o");
	return;
}

int main( void ) {

	
	print__line();
	{
		std::cout << "Array of int[5]" << std:: endl;
		print_small_line();

		const int size = 5;
		int array[size] = {1, 1, 1, 1, 1};

		print_array<int, int>(array, size);
		print_small_line();

		iter< int, int, void(int &) >(array, size,  transform<int>);
		print_array<int, int>(array, size);
	}
	print__line();
	{
		std::cout << "Array of char [5]" << std:: endl;
		print_small_line();

		const int size = 5;
		char array[size] = {'z', 'z', 'z', 'z', 'z'};

		print_array<char, int>(array, size);
		print_small_line();

		iter< char, int, void(char &) >(array, size,  transform<char>);
		print_array<char, int>(array, size);
	}
	print__line();
	{
		std::cout << "empty array, std::string[0]" << std:: endl;
		print_small_line();

		const size_t size = 0;
		std::string array[size];
		print_array<std::string, size_t>(array, size);

		print_small_line();
		iter< std::string, size_t, void(std::string &) >(array, size,  &ft_string_array);
		print_array<std::string, size_t>(array, size);
	}
	print__line();
	{
		std::cout << "Array of double[5]" << std:: endl;
		print_small_line();

		const int size = 5;
		double array[size] = {1, 1, 1, 1, 1};

		print_array<double, int>(array, size);
		print_small_line();

		iter< double, int, void(double &) >(array, size, transform_decimal<double>);
		print_array<double, int>(array, size);
	}
	print__line();
	{
		std::cout << "Array of double *array = nullptr" << std:: endl;
		print_small_line();

		const int size = 5;
		double *array = nullptr;

		print_array<double, int>(array, size);
		print_small_line();

		iter< double, int, void(double &) >(array, size, transform_decimal<double>);
		print_array<double, int>(array, size);
	}

}