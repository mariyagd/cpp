/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:20 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 15:13:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) : _foo( 0 ) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Sample::Sample( int const n ) : _foo( n ) {
	std::cout << "Parametric constructor called" << std::endl;
	return;
}

Sample::Sample( Sample const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Sample & Sample::operator=( Sample const& rhs ) {
	std::cout << "Assignment operator called" << std::endl;
	if ( this != &rhs )  // verifie si les adresses memoire sont differentes
	{
		this->_foo = rhs.getFoo();
	}
	return *this;
}

int	Sample::getFoo( void ) const {
	return this->_foo;
}

std::ostream & operator<<( std::ostream & o, Sample const & i ) {
	o << "The value of _foo is : " << i.getFoo();
	return o;
}
