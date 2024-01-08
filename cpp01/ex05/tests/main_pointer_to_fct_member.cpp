#include <iostream>

class C
{
public:
	C() {};
	~C() {};
	void f(int n) { std::cout << n << '\n'; }

};

int main(void)
{
	void	(C::*p)(int) = &C::f;
	C	c;
	C*	cp = &c;

	(c.*p)(1);
	(cp->*p)(2);
}

/*
struct C { int m; };

int main()
{
	int C::* p = &C::m;          // pointer to data member m of class C
	C c = {7};
	std::cout << c.*p << '\n';   // prints 7
	C* cp = &c;
	cp->m = 10;
	std::cout << cp->*p << '\n'; // prints 10
}
 */