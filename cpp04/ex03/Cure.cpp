
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {

	std::cout << ITALIC << DIM << "Cure created" << END << std::endl;
//	std::cout << ITALIC << DIM << "Cure's Default constructor called" << END << std::endl;
	return ;
}

Cure::~Cure( void ) {

	std::cout << ITALIC << DIM << "Deleting cure" << END << std::endl;
//	std::cout << ITALIC << DIM << "Cure's Destructor called" << END << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src) {

//	std::cout << ITALIC << DIM << "Cure's Copy constructor called" << END << std::endl;
	return ;
}

Cure& Cure::operator=(Cure const &rhs) {

//	std::cout << ITALIC << DIM << "Cure's Copy assignment operator called" << END << std::endl;
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Cure* Cure::clone( void ) const {

	std::cout << ITALIC << DIM << "Cloning cure" << END << std::endl;
//	std::cout << ITALIC << DIM << "Cure's Cloning function called" << END << std::endl;
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target ) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}