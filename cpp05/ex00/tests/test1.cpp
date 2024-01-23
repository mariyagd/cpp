#include <string>
#include <stdexcept>
#include <iostream>

//void	test1( void )
//{
//	try
//	{
//		// Do some stuff here
//		if ( /*there is an error */)
//		{
//			throw std::exception();
//		}
//		else
//		{
//			//do some stuff
//		}
//	}
//	catch (std::exception &e)
//	{
//		//handle error
//	}
//}

void	test1( int a )
{
	try
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
	catch (std::exception &e)
	{
		std::cout << "Not a valid number" << std::endl;
	}
}

int main( void )
{
	int a = -10;
	test1(a);
}