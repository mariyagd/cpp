#include "Base.hpp"
#include <iostream>
#define BLUE 	"\033[1;34m"
#define END	 	"\033[0m"

int main( void )
{
	std::cout << BLUE << "-----------------------------------------------------------" << END << std::endl;
	{
		std::cout << BLUE << "Generating 20 random classes" << END  << std::endl;
		std::cout << "-----------------------------------------------------------" << END  << std::endl;
		for (int i = 0; i < 30; i++)
		{
			Base *p = generate();
			identify(p);
			identify(*p);

			std::cout << BLUE << "--------------" << END << std::endl;
			delete p;
		}
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class Base *p = 0" << std::endl;
		std::cout << "-----------------------------------------------------------" << END  << std::endl;
		Base *p = 0;

			identify(p);
			if (p != 0)
				identify(*p);
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class Base *p = new Base" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		Base *p = new Base;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class A *p = new A" << END  << std::endl;
		std::cout << "-----------------------------------------------------------" << END  << std::endl;
		A *p = new A;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class B *p = new B" << END  << std::endl;
		std::cout << "-----------------------------------------------------------" << END  << std::endl;
		B *p = new B;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class C *p = new C" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		C *p = new C;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class D deriving from class Base, D *p = new D" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		D *p = new D;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class Mixed deriving from class A, B and C; Base *p = new Mixed" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		Base *p = new Mixed;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class AC deriving from class A, and C; Base *p = new AC" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		Base *p = new AC;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}
	std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
	{
		std::cout << BLUE << "Creating a class Test deriving from class A, and Another Base; Base *p = new Test" << END  << std::endl;
		std::cout << BLUE << "-----------------------------------------------------------" << END  << std::endl;
		Base *p = new Test;

		identify(p);
		if (p != 0)
			identify(*p);
		delete p;
	}

}

