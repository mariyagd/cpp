#include "phone.h"

void	PhoneBook::_addFirstName(void) {

	std::cout << BOLD << "First name: " << RESET;
	getline(std::cin, this->_contact[_index].setFirstName());

	while (!this->_contact[_index].isValidFirstName())
	{
		std::cout << ITALIC << "This field cannot be empty." << RESET << std::endl;
		std::cout << BOLD << "First name: " << RESET;
		getline(std::cin, this->_contact[_index].setFirstName());
	}
}

void	PhoneBook::_addLastName(void) {

	std::cout << BOLD << "Last name: " << RESET;
	getline(std::cin, this->_contact[_index].setLastName());
	while (!this->_contact[_index].isValidLastName())
	{
		std::cout << ITALIC << "This field cannot be empty." << RESET << std::endl;
		std::cout << BOLD << "Last name: " << RESET;
		getline(std::cin, this->_contact[_index].setLastName());
	}
}

void PhoneBook::_addNickName(void) {

	std::cout << BOLD << "Nickname: " << RESET;
	getline(std::cin, this->_contact[_index].setNickName());
	while (!this->_contact[_index].isValidNickName())
	{
		std::cout << ITALIC << "This field cannot be empty." << RESET << std::endl;
		std::cout << BOLD << "Nickname: " << RESET;
		getline(std::cin, this->_contact[_index].setNickName());
	}
}

void PhoneBook::_addPhoneNumber(void) {

	std::cout << BOLD << "Phone number: " << RESET;
	getline(std::cin, this->_contact[_index].setPhoneNumber());
	while (!this->_contact[_index].isValidPhoneNumber())
	{
		std::cout << ITALIC << "Empty field or invalid phone number." << RESET << std::endl;
		std::cout << BOLD << "Phone number: " << RESET;
		getline(std::cin, this->_contact[_index].setPhoneNumber());
	}
}

void PhoneBook::_addDarkestSecret( void ) {

	std::cout << BOLD << "Darkest secret: " << RESET;
	getline(std::cin, this->_contact[_index].setDarkestSecret());
	while (!this->_contact[_index].isValidDarkestSecret())
	{
		std::cout << ITALIC << "This field cannot be empty." << RESET << std::endl;
		std::cout << BOLD << "Darkest secret: " << RESET;
		getline(std::cin, this->_contact[_index].setDarkestSecret());
	}
}