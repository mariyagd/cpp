#include <string>
#include <stdexcept>
#include <iostream>

//void	test2( void )
//{
//	if ( /*there is an error */)
//	{
//		throw std::exception();
//	}
//	else
//	{
//		//do some stuff
//	}
//}
//
//void	test3( void )
//{
//	try {
//		test2();
//	}
//	catch (std::exception &e) {
//		// handle error
//	}
//}

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