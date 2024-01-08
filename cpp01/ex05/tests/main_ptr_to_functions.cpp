#include <iostream>

void f(int);
void (*p1)(int) = &f;
void (*p2)(int) = f; // same as &f

int	f1(int);

void	f(int a)
{
	std::cout << a << std::endl;
}

int	f1(int a)
{
	return a + 1;
}

int	main(void)
{
	int	a = 10;
	f(a);
	(*p1)(a);
	p1(a);
	p2(a);

	int (*p3)(int) = f1;
	int b = p3(0);
	f(b);

	return 0;
}