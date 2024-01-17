/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 14:46:18 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {

	this->_type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
	return;
}

WrongCat::~WrongCat( void ) {
	
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat::WrongCat( WrongCat const& src ) : WrongAnimal(src) {
	
	std::cout << "WrongCat Copy constructor called" << std::endl;
	return;
}


WrongCat&	WrongCat::operator=(WrongCat const& rhs) {

	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;
}

void	WrongCat::makeSound( void ) const {

	std::cout << "WrongCat: Miouw miouw mrr" << std::endl;
	return;
}
