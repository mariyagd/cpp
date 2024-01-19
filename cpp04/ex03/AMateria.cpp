
#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("default") {

	std::cout << "AMateria's Default constructor called" << std::endl;
	return ;
}

AMateria::~AMateria( void ) {

	std::cout << "AMateria's Destructor called" << std::endl;
	return ;
}

AMateria::AMateria( AMateria const &src ) : _type(src._type){

	std::cout << "AMateria's Copy constructor called" << std::endl;
	return ;
}

AMateria& AMateria::operator=( AMateria const &rhs ) {

	std::cout << "AMateria's Assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) {

	std::cout << "AMateria's Parametrized constructor called" << std::endl;
	return ;
}

std::string const&	AMateria::getType() const {

	return (this->_type);
}

void	AMateria::use(ICharacter &target) {

	(void)target;
	return ;
}