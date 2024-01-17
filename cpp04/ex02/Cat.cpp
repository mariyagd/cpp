/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 15:27:26 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal(), _brain(new Brain) {

	this->_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::~Cat( void ) {
	
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}

Cat::Cat( Cat const& src ) : Animal(src), _brain(0) {
	
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
	return;
}


Cat&	Cat::operator=(Cat const& rhs) {

	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void	Cat::makeSound( void ) const {

	std::cout << "Miouw miouw mrr miouw mrrr Miouw" << std::endl;
	return;
}

void	Cat::setBrainIdea( size_t i, std::string idea ) const {

	this->_brain->setIdeas(i, idea);
	return;
}

void	Cat::printBrainIdeas( std::ostream& stream ) const {

	stream << *this->_brain;
	return;
}

