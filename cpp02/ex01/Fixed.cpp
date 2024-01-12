/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:52:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 19:44:32 by mdanchev         ###   lausanne.ch       */
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

/*
 pow(2, nbFractionalBits) returns a double
 double x intValue -> returns a double -> cast it to int

 1 << nbFractionalBits returns an int
*/

Fixed::Fixed ( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
//	this->FixedPointNumber = static_cast<int>(intValue * pow( 2, nbFractionalBits ));
	this->FixedPointNumber = intValue * ( 1 << nbFractionalBits );
	return;
}

/*
 pow(2, this->fractionalBits) returns a double
 double x floatValue returns a double -> use round instead of roundf

 1 << nbFractionalBits returns an int
 int x floatValue returns a float -> use roundf
 */

Fixed::Fixed( float const floatValue ) {
	std::cout << "Float constructor called" << std::endl;
//	this->FixedPointNumber = static_cast<int>(round(floatValue * pow(2, nbFractionalBits)));
	this->FixedPointNumber = static_cast<int>(roundf(floatValue * (1 << nbFractionalBits)));
	return;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const {
	return this->FixedPointNumber;
}

void	Fixed::setRawBits( int const raw ) {
	this->FixedPointNumber = raw;
	return;
}

float Fixed::toFloat( void ) const
{
//	return static_cast<float>(this->FixedPointNumber / pow(2, nbFractionalBits));
	return static_cast<float> (this->FixedPointNumber) / (1 << nbFractionalBits);
}

int Fixed::toInt( void ) const
{
//	return static_cast<int>(this->FixedPointNumber / (pow(2, nbFractionalBits)));
	return (this->FixedPointNumber / (1 << nbFractionalBits));
}

std::ostream& operator<<(std::ostream& stream, Fixed const& src)
{
    stream << src.toFloat();
    return stream;
}

