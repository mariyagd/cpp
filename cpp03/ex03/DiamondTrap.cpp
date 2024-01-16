/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:27:58 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:20:33 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors----------------------------------------------------------------

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap() {

	std::cout << "DiamondTrap's Default constructor called" << std::endl;
	return;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << "DiamondTrap's Destructor called" << std::endl;
	return;
}

// this->ClapTrap::_name <=> unmasking
DiamondTrap::DiamondTrap( std::string name) : ScavTrap(name), FragTrap(name) {

	this->_name = name;
	this->ClapTrap::_name = name.append("_clap_name");
	this->_energyPoints = 50;
	std::cout << "DiamondTrap's Parametrized constructor called" << std::endl;
	return;
}

//-------------------------------doesn't work with : ScavTrap(src), FragTrap(src)
DiamondTrap::DiamondTrap( DiamondTrap const& src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {

	std::cout << "DiamondTrap's Copy constructor called" << std::endl;
	this->_name = src._name;
	return;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const& rhs ) {

	std::cout << "DiamondTrap's Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	return *this;
}

// Methods----------------------------------------------------------------

void DiamondTrap::whoAmI( void ) {

	std::cout	<< "Who am I? : My DiamondTrap name is "
				<< ( this->_name == "" ? "(no_name)" : this->_name )
				<< " and my ClapTrap name is "
				<< ( ClapTrap::_name == "" ? "(no_name)" : ClapTrap::_name )
				<< std::endl;
	return;
}

// resolution of diamond problem
void	DiamondTrap::attack( const std::string& target ) {

	ScavTrap::attack(target);
	return;
}

