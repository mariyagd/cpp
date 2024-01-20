
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {

	std::cout << ITALIC << DIM << "Ice ice created" << END << std::endl;
//	std::cout << ITALIC << DIM << "Ice's Default constructor called" << END << std::endl;
	return ;
}

Ice::~Ice( void ) {

	std::cout << ITALIC << DIM << "Deleting ice" << END << std::endl;
//	std::cout << ITALIC << DIM << "Ice's Destructor called" << END << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src) {

//	std::cout << ITALIC << DIM << "Ice's Copy constructor called" << END << std::endl;
	return ;
}

Ice& Ice::operator=(Ice const &rhs) {


//	std::cout << ITALIC << DIM << "Ice's Copy assignment operator called" << END << std::endl;
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Ice* Ice::clone( void ) const {

	std::cout << ITALIC << DIM << "Cloning ice" << END << std::endl;
//	std::cout << ITALIC << DIM << "Ice's Cloning function called" << END << std::endl;
	return (new Ice(*this));
}

void	Ice::use( ICharacter &target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}