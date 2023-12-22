/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:19:43 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:19:45 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

/*
std::cout << "Constructor of class " << BOLD << "Contact" << RESET << " called" << std::endl;
*/

Contact::Contact( void ) :
	_index(0),
	_firstName(""),
	_lastName(""),
	_nickName(""),
	_phoneNumber(""),
	_darkestSecret("") {

	return;
}

/*
std::cout << "Destructor of class " << BOLD << "Contact" << RESET << " called" << std::endl;
*/

Contact::~Contact( void ) {

	return;
}

void	Contact::_eraseWhiteSpace(std::string &command) {

	size_t	i(0);
	size_t 	first;
	size_t 	last;

	if (command.empty())
		return ;
	while (i < command.length() && std::isspace(command[i]))
		i++;
	if (i != 0)
		command.erase(0, i);

	i = command.length();
	while (i > 0 && std::isspace(command[i - 1]))
		i--;
	if (i != command.length())
		command.erase(i);


	first = command.find_first_of(" \t\n\r\f\v");
	while (first != std::string::npos && first < command.length())
	{
		last = first;
		while (std::isspace(command[last]))
			last++;
		if (last != first)
			command = command.replace(first, last - first, " ");
		first = command.find_first_of(" \t\n\r\f\r", first + 1);
	}
}
