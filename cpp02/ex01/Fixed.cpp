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
//	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}


Fixed::Fixed ( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
	//this->fixedPointValue = intValue * ( 1 << nbFractionalBits );
	this->fixedPointValue = intValue * pow( 2, nbFractionalBits );
}

Fixed::Fixed( float const floatValue )
{
    std::cout << "Float contructor called" << std::endl;
    //this->fixedPointValue = roundf(floatValue * pow(2, this->nbFractionalBits));
    this->fixedPointValue = roundf(floatValue * ( 1 << this->nbFractionalBits));
}


float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->fixedPointValue / pow(2, this->nbFractionalBits));
    //return static_cast<float>(this->fixedPointValue / (1 << this->nbFractionalBits));
}

int Fixed::toInt( void ) const
{
    return (this->fixedPointValue / static_cast<int>(pow(2, this->nbFractionalBits)));
   // return (this->fixedPointValue / static_cast<int>( 1 << this->nbFractionalBits));
}

std::ostream& operator<<(std::ostream& stream, Fixed const& src)
{
    stream << src.toFloat();
    return stream;
}

