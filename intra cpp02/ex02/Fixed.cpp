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

/*
 Static value
 -------------------------------------------
 */

const int Fixed::nbFractionalBits = 8;


/*
 Constructors
 --------------------------------------------
 */

Fixed::Fixed (void) : fixedPointNumber(0) {
//	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed ( Fixed const& fixedSrc ) {
//	std::cout << "Copy constructor called" << std::endl;
//	this->fixedPointNumber = fixedSrc.getRawBits();
	*this = fixedSrc;
	return;
}

Fixed::Fixed ( int const intValue ) {
//	std::cout << "Int constructor called" << std::endl;
//	this->fixedPointNumber = static_cast<int>(intValue * pow( 2, nbFractionalBits ));
	this->fixedPointNumber = intValue * ( 1 << nbFractionalBits );
	return;
}

Fixed::Fixed( float const floatValue )
{
//	std::cout << "Float constructor called" << std::endl;
//	this->fixedPointNumber = static_cast<int>(round(floatValue * pow(2, nbFractionalBits)));
	this->fixedPointNumber = static_cast<int>(roundf(floatValue * (1 << nbFractionalBits)));
	return;
}

Fixed& Fixed::operator=( Fixed const& fixedRhs ) {
	if (this != &fixedRhs)
		this->fixedPointNumber = fixedRhs.getRawBits();
	return *this;
}

Fixed::~Fixed ( void ) {
//	std::cout << "Destructor called" << std::endl;
	return;
}

/*
 Getters and setters
 --------------------------------------------
 */

int	Fixed::getRawBits( void ) const {
	return this->fixedPointNumber;
}

void	Fixed::setRawBits( int const raw ) {
	this->fixedPointNumber = raw;
	return;
}

float Fixed::toFloat( void ) const
{
//  return static_cast<float>(this->fixedPointNumber / (pow(2, nbFractionalBits)));
   	return static_cast<float>(this->fixedPointNumber) / (1 << nbFractionalBits);
}

int Fixed::toInt( void ) const
{
//	return static_cast<int>(this->fixedPointNumber / (pow(2, nbFractionalBits)));
	return this->fixedPointNumber / (1 << nbFractionalBits);
}

std::ostream& operator<<(std::ostream& stream, Fixed const& src)
{
    stream << src.toFloat();
    return stream;
}

/*
  Comparison operators
  ---------------------------------
 */
bool	Fixed::operator>(Fixed const& other) const {
	if (this->fixedPointNumber > other.fixedPointNumber)
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const& other) const {
	if (this->fixedPointNumber < other.fixedPointNumber)
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const& other) const {
	if (this->fixedPointNumber >= other.fixedPointNumber)
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const& other) const {
	if (this->fixedPointNumber <= other.fixedPointNumber)
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const& other) const {
	if (this->fixedPointNumber == other.fixedPointNumber)
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const& other) const {
	if (this->fixedPointNumber != other.fixedPointNumber)
		return true;
	return false;
}

/*
  Arithmetic operators
  -------------------------------
 */

Fixed	Fixed::operator+(Fixed const& other) const {

	Fixed	result (this->toFloat() + other.toFloat());
	return result;
}

Fixed	Fixed::operator-(Fixed const& other) const {

	Fixed	result(this->toFloat() - other.toFloat());
	return result;
}

Fixed	Fixed::operator*(Fixed const& other) const {

	Fixed	result(this->toFloat() * other.toFloat());
	return result;
}

Fixed	Fixed::operator/(Fixed const& other) const {

	Fixed	result(this->toFloat() / other.toFloat());
	return result;
}

/*
 Increment and decrement operators:
 ---------------------------------------------------------------
 Pre-increment and pre-decrement operators increments or decrements
 the value of the object and returns a reference to the result.

 Post-increment and post-decrement creates a copy of the object,
 returns the copy from before the increment or decrement.

 Because a temporary copy of the object is constructed during
 post-increment and post-decrement, pre-increment or pre-decrement
 operators are usually more efficient in contexts where the returned
 value is not used.
 */

// pre-increment ++a
Fixed&	Fixed::operator++( void ) {
	this->fixedPointNumber += 1;
	return *this;
}

// pre-decrement --a
Fixed&	Fixed::operator--( void ) {
	this->fixedPointNumber -= 1;
	return *this;
}

// post-increment a++
Fixed	Fixed::operator++( int ) {
	Fixed	tmp(*this);
//	this->fixedPointNumber += 1;
	++(*this);
	return tmp;
}

// post-decrement a--
Fixed	Fixed::operator--( int ) {
	Fixed	tmp(*this);
//	this->fixedPointNumber -= 1;
	--(*this);
	return tmp;
}

/*
 	Min and max functions
 	---------------------------------
 */

 Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

 Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
	if (a < b)
		return a;
	return b;
}

 Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

 Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	if (a > b)
		return a;
	return b;
}
