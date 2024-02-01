/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 13:13:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal() {

	this->_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
	return;
}

Dog::~Dog( void ) {
	
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog::Dog( Dog const& src ) : Animal(src) {
	
	std::cout << "Dog Copy constructor called" << std::endl;
	return;
}


Dog&	Dog::operator=(Dog const& rhs) {

	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

void	Dog::makeSound( void ) const {

	std::cout << "Wouf wouf! WOUF WOUF WOUF!!!" << std::endl;
	return;
}
