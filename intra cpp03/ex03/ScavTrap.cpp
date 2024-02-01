/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:27:58 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:08:53 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {

	std::cout << "ScavTrap's default constructor called" << std::endl;
	return;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap's Destructor called" << std::endl;
	return;
}

// inherited members in derived class can only be initialized by the base class’s constructor
ScavTrap::ScavTrap( std::string name) :	ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDammage = 20;
	std::cout << "ScavTrap's Parametrized constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap( src ) {

	std::cout << "ScavTrap's Copy constructor called" << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=( ScavTrap const& rhs ) {

	std::cout << "ScavTrap's Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}

void	ScavTrap::guardGate( void ) const {

	std::cout << this->_name << " ScavTrap is now in Gate keeper mode." << std::endl;
}

// unmasking -> using the function that was masked
void ScavTrap::attack( const std::string& target ) {

	std::cout << "From ScavTrap attack(): ";
	ClapTrap::attack(target);
	return;
}
