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

Fixed::Fixed (void) : FixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const& fixedSrc ) {
	std::cout << "Copy constructor called" << std::endl;
//	this->FixedPointNumber = fixedSrc.getRawBits();
	*this = fixedSrc;
}

Fixed& Fixed::operator=( Fixed const& fixedRhs ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixedRhs)
		this->FixedPointNumber = fixedRhs.getRawBits();
	return *this;
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

Fixed::Fixed ( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
//	this->FixedPointNumber = intValue * ( 1 << nbFractionalBits );
	this->FixedPointNumber = intValue * pow( 2, nbFractionalBits );
}

Fixed::Fixed( float const floatValue )
{
    std::cout << "Float contructor called" << std::endl;
    this->FixedPointNumber = roundf(floatValue * pow(2, this->nbFractionalBits));
 //  this->FixedPointNumber = (int) roundf(floatValue * (1 << this->nbFractionalBits));
}


float Fixed::toFloat( void ) const
{
   return static_cast<float>(this->FixedPointNumber / pow(2, this->nbFractionalBits));
 //   return (float)(this->FixedPointNumber / (1 << this->nbFractionalBits)); -> mauvaise precision
}

int Fixed::toInt( void ) const
{
    return (this->FixedPointNumber / static_cast<int>(pow(2, this->nbFractionalBits)));
  //  return (this->FixedPointNumber / ( 1 << this->nbFractionalBits));
}

std::ostream& operator<<(std::ostream& stream, Fixed const& src)
{
    stream << src.toFloat();
    return stream;
}

