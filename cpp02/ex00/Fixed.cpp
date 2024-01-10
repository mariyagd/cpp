/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:52:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 12:09:02 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const& fixedSrc ) {
	std::cout << "Copy constructor called" << std::endl;
//	this->fixedPointValue = fixedSrc.getRawBits();
	*this = fixedSrc;
}

Fixed& Fixed::operator=( Fixed const& fixedRhs ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixedRhs)
		this->fixedPointValue = fixedRhs.getRawBits();
	return *this;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
