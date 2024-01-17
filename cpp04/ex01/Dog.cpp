/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 15:34:07 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal(), _brain(new Brain) {

	this->_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
	return;
}

Dog::~Dog( void ) {
	
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}

Dog::Dog( Dog const& src ) : Animal(src), _brain(0) {
	
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
	return;
}


Dog&	Dog::operator=(Dog const& rhs) {

	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void	Dog::makeSound( void ) const {

	std::cout << "Wouf wouf! WOUF WOUF WOUF!!!" << std::endl;
	return;
}

void	Dog::setBrainIdea( size_t i, std::string idea ) const {

	this->_brain->setIdeas(i, idea);
	return;
}

void	Dog::printBrainIdeas( std::ostream& stream ) const {

	stream << *this->_brain;
	return;
}
