#include "Base.hpp"
#include <iostream>

int main( void )
{
	{
		std::cout << "Generating 20 random classes and verify wi Base" << std::endl;
		for (int i = 0; i < 30; i++)
		{
			Base *p = generate();
			identify(p);
			identify(*p);

			std::cout << "--------------" << std::endl;
			delete p;
		}
	}
}

