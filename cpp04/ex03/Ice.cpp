
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {

	std::cout << "Ice's Default constructor called" << std::endl;
	return ;
}

Ice::~Ice( void ) {

	std::cout << "Ice's Destructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src) {

	std::cout << "Ice's Copy constructor called" << std::endl;
	return ;
}

Ice& Ice::operator=(Ice const &rhs) {

	std::cout << "Ice's Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Ice* Ice::clone( void ) const {

	return (new Ice(*this));
}

void	Ice::use( ICharacter &target ) {

	std::cout << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}