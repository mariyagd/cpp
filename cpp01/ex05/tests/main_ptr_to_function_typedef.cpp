#include <iostream>

typedef void F(int);
F f;
F* p1 = &f;						// same as void (*p1)(int) = &f;
F* p2[2] = {f, f};  // same as void (*p2[2])(int) = {f, f}; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	p1(a);
	p2[0](a);
	p2[1](a);
	return 0;
}