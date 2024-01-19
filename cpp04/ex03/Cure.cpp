
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {

	std::cout << "Cure's Default constructor called" << std::endl;
	return ;
}

Cure::~Cure( void ) {

	std::cout << "Cure's Destructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src) {

	std::cout << "Cure's Copy constructor called" << std::endl;
	return ;
}

Cure& Cure::operator=(Cure const &rhs) {

	std::cout << "Cure's Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Cure* Cure::clone( void ) const {

	return (new Cure(*this));
}

void	Cure::use( ICharacter &target ) {

	std::cout << " * heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}