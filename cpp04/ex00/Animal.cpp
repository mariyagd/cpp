/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 14:51:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal") {

	std::cout << "Animal Default constructor called" << std::endl;
	return;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal::Animal( Animal const& src ) {
	
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal&	Animal::operator=(Animal const& rhs) {

	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	Animal::getType( void ) const {

	return this->_type;
}

std::ostream& operator<<( std::ostream& stream, Animal const& animal )
{
	stream << "Animal type: " << animal.getType() << std::endl;
	return stream;
}

void	Animal::makeSound( void ) const {

	std::cout << "***Animal sound***" << std::endl;
	return;
}
