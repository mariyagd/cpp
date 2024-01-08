#include <cassert>
#include <iostream>

// Pointeur à la fin d'un objet

struct C
{
	int x, y;
} c;

int	main(void)
{
	c.x = 6;
	int *px = &c.x;   // value of px is "pointer to c.x"
	int *pxe = px + 1; // value of pxe is "pointer past the end of c.x"

	std::cout << "x = " << c.x << std::endl;
	std::cout << "px = " << *px <<std::endl;
	std::cout << "pxe = " << *pxe <<std::endl;

	c.y = 17;
	int *py = &c.y;   // value of py is "pointer to c.y"

	std::cout << "y = " << c.y << std::endl;
	std::cout << "py = " << *py <<std::endl;
	std::cout << "pxe = " << *pxe <<std::endl;

	assert(pxe == py); // == tests if two pointers represent the same address
// may or may not fire

	std::cout << "pxe == py" << std::endl;

	*pxe = 1; // undefined behavior even if the assertion does not fire
	std::cout << "py = " << *py <<std::endl;
	std::cout << "pxe = " << *pxe <<std::endl;
}
