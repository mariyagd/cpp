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
//
//void	test4 ( void )
//{
//	class PEBKACException :: public std::exception
//	{
//		public:
//			virtual const char* what() const throw()
//			{
//				return ("Problem exists between keyboard and chair")
//			}
//	};
//
//	try
//	{
//		test3();
//	}
//	catch (PEBKACexception& e)
//	{
//		// Handle the fact that the user is an idiot
//	}
//	catch (std::exception& e)
//	{
//		//Handle other exceptions that are like std::exception
//	}
//}

void	test2( int a )
{
	if (a < 0 || a > 10)
	{
		throw std::exception();
	}
	else
	{
		std::cout << "Valid number" << std::endl;
	}
}

void	test3( int a )
{
	try
	{
		test2( a );
	}
	catch (std::exception &e) {
		std::cout << "Invalid number" << std::endl;
	}
}

void	test4 ( int a )
{
	class MyException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Negative number");
		}
	};

	try
	{
		if (a < 0)
			throw MyException();
	}
	catch (MyException& e)
	{
		std::cout << e.what() << std::endl;
 	}
	catch (std::exception& e)
	{
		std::cout << "Not fewfwef" << std::endl;
	}
}

int main( void )
{
	int a = -10;
	test4(a);


}