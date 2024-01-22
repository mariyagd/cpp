/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:52:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 13:17:31 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nbFractionalBits = 8;

Fixed::Fixed (void) : FixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed ( Fixed const& fixedSrc ) {
	std::cout << "Copy constructor called" << std::endl;
//	this->FixedPointNumber = fixedSrc.getRawBits();
	*this = fixedSrc;
	return;
}

Fixed& Fixed::operator=( Fixed const& fixedRhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixedRhs)
		this->FixedPointNumber = fixedRhs.getRawBits();
	return *this;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->FixedPointNumber;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->FixedPointNumber = raw;
	return;
}
