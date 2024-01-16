#include <string>
#include <iostream>
/*
class Mother {
	protected:
		std::string _name;
		int _a;

	public:
		Mother() : _name(""), _a(0) { std::cout << "Mother's Default constructor called" << std::endl; }
		Mother(std::string name) : _name(name), _a(10) { std::cout << "Mother's Parametrized constructor called" << std::endl; }
		void print() { std::cout << "name: " << this->_name << " a = " << this->_a << std::endl; }
		~Mother() { std::cout << "Mother's Destructor called" << std::endl; }
};

class Daughter1 :  public Mother {
	public:
		Daughter1(std::string name) : Mother(name) { this->_a = 50; std::cout << "Daughter1's Parametrized constructor called" << std::endl;}
		~Daughter1() { std::cout << "Daughter1's Destructor called" << std::endl; }
};

class Daughter2 :  public Mother {
	public:
		Daughter2(std::string name) : Mother(name) { this->_a = 100; std::cout << "Daughter2's Parametrized constructor called" << std::endl; }
		~Daughter2() { std::cout << "Daughter2's Destructor called" << std::endl; }
};

class GrandDaughter : public Daughter1, public Daughter2 {
	public:
		GrandDaughter(std::string name) : Daughter1(name), Daughter2(name) { std::cout << "GrandDaughter's Parametrized constructor called" << std::endl;}
		~GrandDaughter() { std::cout << "GrandDaughter's Destructor called" << std::endl; }
};

int main() {
	GrandDaughter lili("lili");
	lili.print();
	return 0;
}
*/

class A1 {
	public:
			A1() { std::cout << "A1's Default constructor called" << std::endl ; }
			~A1() { std::cout << "A1's Destructor called" << std::endl ; }
};

class A2 {
	public:
			A2() { std::cout << "A2's Default constructor called" << std::endl ; }
			~A2() { std::cout << "A2's Destructor called" << std::endl ; }
};

class A3 {
	public:
			A3() { std::cout << "A3's Default constructor called" << std::endl ; }
			~A3() { std::cout << "A3's Destructor called" << std::endl ; }
};

class B1 :  virtual public A1 {
	public:
			B1() : A1() { std::cout << "B1's Default constructor called" << std::endl ; }
			~B1() { std::cout << "B1's Destructor called" << std::endl ; }
};

class B2 :  virtual public A1,  public A2 {
	public:
			B2() : A1(), A2() { std::cout << "B2's Default constructor called" << std::endl ; }
			~B2() { std::cout << "B2's Destructor called" << std::endl ; }
};

class C1 : public B1 {
	public:
			C1() : B1() { std::cout << "C1's Default constructor called" << std::endl ; }
			~C1() { std::cout << "C1's Destructor called" << std::endl ; }
};

class C2 : public B2, public A3 {
	public:
			C2() : B2(), A3() { std::cout << "C2's Default constructor called" << std::endl ; }
			~C2() { std::cout << "C2's Destructor called" << std::endl ; }
};


class X : public C1, public C2 {
	public:
			X() : C1(), C2() { std::cout << "X's Default constructor called" << std::endl ; }
			~X() { std::cout << "X's Destructor called" << std::endl ; }
};

int main() {
	X x;
	return 0;
}