/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 14:51:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {

	this->_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::~Cat( void ) {
	
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat::Cat( Cat const& src ) : Animal(src) {
	
	std::cout << "Cat Copy constructor called" << std::endl;
	return;
}


Cat&	Cat::operator=(Cat const& rhs) {

	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

void	Cat::makeSound( void ) const {

	std::cout << "Miouw miouw mrr miouw mrrr Miouw" << std::endl;
	return;
}
