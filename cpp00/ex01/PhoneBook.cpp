/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:20:18 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:20:19 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

/*
std::cout << "Constructor of class " << BOLD << "PhoneBook" << RESET << " called" << std::endl;
*/

PhoneBook::PhoneBook( void ) : _realIndex(0), _index(0), _tableSize(0) {

	std::cout <<  BOLD << GREEN
			  <<"|------------------------------------------------------------|" << std::endl
			  << "|                     Welcome to PhoneBook.                  |"<< std::endl
			  << "|                    This phonebook is empty.                |" << std::endl
			  << "|             Please enter ADD to add a new contact          |" << std::endl
			  << "|                  SEARCH to display a contact,              |" << std::endl
			  << "|          EXIT to exit the program and loose all contacts   |"<< std::endl
			  << "|------------------------------------------------------------|"
			  << RESET << std::endl;
}

/*
std::cout << "Destructor of class " << BOLD << "PhoneBook" << RESET << " called" << std::endl;
*/

PhoneBook::~PhoneBook( void ) {

	return ;
}

void	PhoneBook::_transformToUpper(std::string &command) const {

	if (command.empty())
		return;

	std::string::iterator it = std::begin(command);
	while (it != std::end(command)) {
		*it = std::toupper(*it);
		++it;
	}
}

void PhoneBook::userInput( void ) {

	std::string command("");
	std::string copy_command (command);

	while (copy_command != "EXIT")
	{

		std::cout << ITALIC << "Please enter a command: ADD, SEARCH, or EXIT: " << RESET;
		std::getline(std::cin, command);
		_eraseWhiteSpaces(command);
		copy_command = command;
		_transformToUpper(copy_command);
		if (copy_command == "ADD")
			_addContact();
		else if (copy_command == "SEARCH")
			_searchContact();
		else if (copy_command != "EXIT")
			std::cout << BOLD << command << RESET << ": invalid command. Please try again." << std::endl;
	}
	std::cout << UNDERLINE << "You entered: EXIT" << RESET << std::endl;
	std::cout << BOLD << "You exited the program and lost all contacts." << RESET << std::endl;
}

void PhoneBook::_addContact( void ) {

	std::cout << UNDERLINE << "You entered: ADD" << RESET << std::endl;
	if (this->_realIndex >= 8)
	{
		this->_index = this->_realIndex;
		while (this->_index >= 8)
			this->_index = this->_index % 8;
		this->_tableSize = 8;
	}
	else {
		this->_index = this->_realIndex;
		this->_tableSize = this->_realIndex + 1;
	}
	if (_index >= 8)
	{
		_index = _index % 8;
		_tableSize = 8;
	}
	this->_contact[_index].setIndex(_index);

	_addFirstName();
	_addLastName();
	_addNickName();
	_addPhoneNumber();
	_addDarkestSecret();
	std::cout << GREEN << BOLD << ITALIC << "Contact added successfully!" << RESET << std::endl;
	this->_realIndex++;
}

void PhoneBook::_searchContact( void ) const {

	int 		i;
	std::string inputLine;

	std::cout << UNDERLINE << "You entered: SEARCH" << RESET << std::endl;
	if (this->_tableSize == 0) {
		std::cout << BOLD << "This PhoneBook is empty. Please add some contacts." << RESET << std::endl;
	}
	else {
		std::cout << BOLD
				  << "|----------|----------|----------|----------|" << std::endl << "|"
				  << std::setw(10) << "Index" << "|"
				  << std::setw(10) << "First Name" << "|"
				  << std::setw(10) << "Last Name" << "|"
				  << std::setw(10) << "Nick Name" << "|" << std::endl
				  << "|----------|----------|----------|----------|" << RESET << std::endl;


		for (i = 0; i < this->_tableSize; i++) {
			std::cout << "|" << std::setw(10) << this->_contact[i].getIndex() << "|"
					  << std::setw(10) << this->_contact[i].truncFirstName() << "|"
					  << std::setw(10) << this->_contact[i].truncLastName() << "|"
					  << std::setw(10) << this->_contact[i].truncNickName() << "|" << std::endl
					  << "|----------|----------|----------|----------|" << std::endl;
		}
		std::cout << ITALIC
				  << "Please enter the index of the contact you want to see,"
				  << " or type \"EXIT\" to exit this SearchBook: " << RESET;

		getline(std::cin, inputLine);
		i = _isNumber(inputLine, _tableSize);
		while (i < 0)
		{
			if (i == -2)
			{
				std::cout <<  UNDERLINE << "You entered: EXIT search" << RESET << std::endl;
				return ;
			}
			std::cout << "Invalid index." << std::endl
					  << ITALIC << "Please enter the index of the contact you want to see,"
					  			<< " or type \"EXIT\" to exit this SearchBook: " << RESET;
			getline(std::cin, inputLine);
			i = _isNumber(inputLine, _tableSize);
		}
		std::cout << std::left
				  << BOLD << std::setw(15) << "Index " << ": " << RESET
		          << this->_contact[i].getIndex() << std::endl
				  << BOLD << std::setw(15) << "First Name " << ": " << RESET
				  << this->_contact[i].getFirstName() << std::endl
				  << BOLD << std::setw(15) << "Last Name " << ": " << RESET
				  << this->_contact[i].getLastName() << std::endl
				  << BOLD << std::setw(15) << "Nickname " << ": " << RESET
				  << this->_contact[i].getNickName() << std::endl
				  << BOLD << std::setw(15) << "Phone number " << ": " << RESET
				  << this->_contact[i].getPhoneNumber() << std::endl
				  << BOLD << std::setw(15) << "Darkest secret " << ": " << RESET
				  << this->_contact[i].getDarkestSecret() << std::endl;
	}
}