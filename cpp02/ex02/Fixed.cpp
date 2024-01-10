/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:52:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 15:40:52 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : fixedPointValue(0) {
	return;
}

Fixed::Fixed ( Fixed const& fixedSrc ) {
//	this->fixedPointValue = fixedSrc.getRawBits();
	*this = fixedSrc;
	return;
}

Fixed& Fixed::operator=( Fixed const& fixedRhs ) {
	if (this != &fixedRhs)
		this->fixedPointValue = fixedRhs.getRawBits();
	return *this;
}

Fixed::~Fixed ( void ) {
	return;
}

int	Fixed::getRawBits( void ) const {
	return this->fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	this->fixedPointValue = raw;
	return;
}

Fixed::Fixed ( int const intValue ) {
	//this->fixedPointValue = intValue * ( 1 << nbFractionalBits );
	this->fixedPointValue = intValue * pow( 2, nbFractionalBits );
	return;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(this->fixedPointValue / pow(2, this->nbFractionalBits));
}

int Fixed::toInt( void ) const {
    return (this->fixedPointValue / static_cast<int>(pow(2, this->nbFractionalBits)));
}

std::ostream& operator<<(std::ostream& stream, Fixed const& src) {
    stream << src.toFloat();
    return stream;
}

Fixed::Fixed( float const floatValue ) {
    this->fixedPointValue = roundf(floatValue * pow(2, this->nbFractionalBits));
	return;
}

bool Fixed::operator>( Fixed const& rhs ) const {
    return this->fixedPointValue > rhs.fixedPointValue;
}

bool Fixed::operator<( Fixed const& rhs ) const {
    return this->fixedPointValue < rhs.fixedPointValue;
}

bool Fixed::operator>=( Fixed const& rhs ) const {
    return this->fixedPointValue >= rhs.fixedPointValue;
}

bool Fixed::operator<=( Fixed const& rhs ) const {
    return this->fixedPointValue <= rhs.fixedPointValue;
}

bool Fixed::operator==( Fixed const& rhs ) const {
    return this->fixedPointValue == rhs.fixedPointValue;
}

bool Fixed::operator!=( Fixed const& rhs ) const {
    return this->fixedPointValue != rhs.fixedPointValue;
}

Fixed Fixed::operator+( Fixed const& rhs ) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue + rhs.fixedPointValue);
    return result;
}

Fixed Fixed::operator-( Fixed const& rhs ) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue - rhs.fixedPointValue);
    return result;
}

Fixed Fixed::operator*( Fixed const& rhs ) const {
    Fixed result;
    result.setRawBits((this->fixedPointValue * rhs.fixedPointValue) >> nbFractionalBits);
    return result;
}

Fixed Fixed::operator/( Fixed const& rhs ) const {
    Fixed result;
    result.setRawBits((this->fixedPointValue << nbFractionalBits) / rhs.fixedPointValue);
    return result;
}

Fixed& Fixed::operator++( void ) {
    ++this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed const& Fixed::min( Fixed const& a, Fixed const& b ) {
    return (a < b) ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a > b) ? a : b;
}
