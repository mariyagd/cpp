#include "phone.h"

Contact::Contact( void ) :
	_index(0),
	_firstName(""),
	_lastName(""),
	_nickName(""),
	_phoneNumber(""),
	_darkestSecret("") {

	//std::cout << "Constructor of class " << BOLD << "Contact" << RESET << " called" << std::endl;

	return;
}

Contact::~Contact( void ) {

//	std::cout << "Destructor of class " << BOLD << "Contact" << RESET << " called" << std::endl;
	return;
}


