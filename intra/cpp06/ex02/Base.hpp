#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>

class Base {

public:
	virtual ~Base( void ) {};
};

class A : virtual public Base {

public:
	A ( void ) {};
	~A( void ) {};
};

class B : virtual public Base {

public:
	B ( void ) {};
	~B( void ) {};
};

class C : virtual public Base {

public:
	C( void ) {};
	~C( void ) {};
};


Base*	generate(void);

void	identify(Base* p);
void	identify(Base& p);


// for testing  -> class A, B and C must be virtual for these tests. Cause -> diamond problem

class D : public Base {

public:
	D( void ) {};
	~D( void ) {};
};


class Mixed : public A, public B, public C {

public:
	Mixed( void ) {};
	 ~Mixed( void ) {};
};

class AC : public A, public C {

public:
	AC( void ) {};
	~AC( void ) {};
};

class AnotherBase {

public:
	AnotherBase( void ) {};
	~AnotherBase( void ) {};
};

class Test : public A, public AnotherBase {

public:
	~Test( void ) {};
	Test( void ) {};
};

#endif

