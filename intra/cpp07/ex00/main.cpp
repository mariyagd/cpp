#include <iostream>
#include <iomanip>
#include "whatever.hpp"

void	print_small_line( void ) {

	std::cout << std::setfill('-') << std::setw(15) << "" << std::endl;
}

void	print__line( void ) {

	std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
}

int main( void ) {

	print__line();
	{
		bool a = true;
		bool b = false;
		bool min_val;
		bool max_val;

		std::cout << "a = " << std::boolalpha << a << " b = " << b << std::endl;
		print_small_line();

		swap<bool>(a, b);
		std::cout << "swap: " << "a = " << a << " b = " << b << std::endl;

		min_val = min<bool>(a, b);
		max_val = max<bool>(a, b);
		std::cout << "min: " << min_val << std::endl;
		std::cout << "max: " << max_val << std::endl;
	}
	print__line();
	{
		int a = 695;
		int b = 56;
		int min_val;
		int max_val;

		std::cout << "a = " << a << " b = " << b << std::endl;
		print_small_line();

		swap<int>(a, b);
		std::cout << "swap: " << "a = " << a << " b = " << b << std::endl;

		min_val = min<int>(a, b);
		max_val = max<int>(a, b);
		std::cout << "min: " << min_val << std::endl;
		std::cout << "max: " << max_val << std::endl;
	}
	print__line();	
	{
		float a = 10.456f;
		float b = 10.456f;
		float min_val;
		float max_val;

		std::cout << "a = " << a << "f" << " b = " << b << "f" << std::endl;
		print_small_line();

		swap<float>(a, b);
		std::cout << "swap: " << "a = " << a << "f" << " b = " << b << "f" << std::endl;

		min_val = min<float>(a, b);
		max_val = max<float>(a, b);
		std::cout << "min: " << min_val << "f" << std::endl;
		std::cout << "max: " << max_val << "f" << std::endl;
	}
	print__line();
	{
		char a = 'a';
		char b = 'A';
		char min_val;
		char max_val;

		std::cout << "a = \'" << a << "\'"<< " b = \'" << b << "\'"<< std::endl;
		print_small_line();

		swap<char>(a, b);
		std::cout << "swap: " << "a = \'" << a << "\'"<< " b = \'" << b << "\'"<< std::endl;

		min_val = min<char>(a, b);
		max_val = max<char>(a, b);
		std::cout << "min: \'" << min_val << "\'"<< std::endl;
		std::cout << "max: \'" << max_val << "\'"<< std::endl;
	}
	print__line();
	{
		std::string a = "alphabet";
		std::string b = "zet";
		std::string min_val;
		std::string max_val;

		std::cout << "a = " << a << " b = " << b << std::endl;
		print_small_line();

		::swap<std::string>(a, b);
		std::cout << "swap: " << "a = " << a << " b = " << b << std::endl;

		min_val = min<std::string>(a, b);
		max_val = max<std::string>(a, b);
		std::cout << "min: " << min_val << std::endl;
		std::cout << "max: " << max_val << std::endl;
	}
	print__line();
	{
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	
}