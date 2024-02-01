/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 14:51:55 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal") {

	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( WrongAnimal const& src ) {
	
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = src;
	return;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs) {

	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	WrongAnimal::getType( void ) const {

	return this->_type;
}

std::ostream& operator<<( std::ostream& stream, WrongAnimal const& animal )
{
	stream << "WrongAnimal type: " << animal.getType() << std::endl;
	return stream;
}

void	WrongAnimal::makeSound( void ) const {

	std::cout << "***WrongAnimal sound***" << std::endl;
	return;
}
