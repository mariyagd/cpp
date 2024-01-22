#include <string>
#include <stdexcept>
#include <iostream>

void	test2( int a )
{
	if ( a < 0)
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Valid number" << std::endl;
	}
}

void	test3( int a)
{
	try {
		test2(a);
	}
	catch (std::exception &e) {
		std::cout << "Not a valid number" << std::endl;
	}
}

int main( void )
{
	int a = -10;
	test3(a);


}