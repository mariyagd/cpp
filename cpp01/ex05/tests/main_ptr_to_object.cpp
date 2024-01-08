#include <iostream>

/*
 * Le passage que vous avez cité indique que vous pouvez initialiser
 * un pointeur vers un objet avec la valeur de retour de l'opérateur
 * "address-of" appliqué à n'importe quelle expression de type objet,
 * y compris un autre pointeur.
 */

int	main(void)
{
	int n = 5;
	int* np = &n;          // pointer to int
	int* const* npp = &np; // non-const pointer to const pointer to non-const int

	std::cout << "n = " << n << std::endl;
	std::cout << "&n = " << &n << std::endl;
	std::cout << "np = " << np << std::endl;
	std::cout << "np = " << *np << std::endl;
	std::cout << "npp = " << npp << std::endl;
	std::cout << "*npp = " << *npp << std::endl << std::endl;

	int a[2] = {12, 89};
	int (*ap)[2] = &a;     // pointer to array of int

	std::cout << "&a = " << &a << std::endl;
	std::cout << "ap = " << ap << std::endl;
	std::cout << "*(ap) = " << *(ap) << std::endl << std::endl;

	std::cout << "&a[0] = " << &a[0] << std::endl;
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "ap[0] = " << (ap)[0] << std::endl;
	std::cout << "*ap[0] = " << (*ap)[0] << std::endl << std::endl;

	std::cout << "&a[1] = " << &a[1] << std::endl;
	std::cout << "a[1] = " << a[1] << std::endl;
	std::cout << "ap[1] = " << (ap)[1] << std::endl;
	std::cout << "*ap[1] = " << (*ap)[1] << std::endl << std::endl;



	struct S
	{
		int n;
	};

	S s = {1};
	int* sp = &s.n;        // pointer to the int that is a member of s

	std::cout << "&s.n = " << &s.n << std::endl;
	std::cout << "s.n = " << s.n << std::endl;
	std::cout << "sp = " << sp << std::endl;
	std::cout << "*sp = " << *sp << std::endl << std::endl;

	int nn = 25;
	int* p = &nn;     // pointer to n
	int& r = *p;     // reference is bound to the lvalue expression that identifies n

	std::cout << "&nn = " << &nn << std::endl;
	std::cout << "nn = " << nn << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *p << std::endl;
	std::cout << "&r = " << &r << std::endl;
	std::cout << "r = " << r << std::endl << std::endl;

	r = 7;           // stores the int 7 in n

	std::cout << "&nn = " << &nn << std::endl;
	std::cout << "nn = " << nn << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *p << std::endl; // lvalue-to-rvalue implicit conversion reads the value from n
	std::cout << "&r = " << &r << std::endl;
	std::cout << "r = " << r << std::endl;
}