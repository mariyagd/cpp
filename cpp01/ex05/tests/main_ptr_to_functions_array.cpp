#include <iostream>

void f(int);
void (*p1[2])(int);
void (*p2[2])(int) = {f, f}; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	p1[0] = &f;
	p1[1] = f;

	p1[0](a);
	p1[1](a);

	p2[0](a);
	p2[1](a);
	return 0;
}