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

ScavTrap::ScavTrap( std::string name) :	ClapTrap(name) {	
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDammage = 20; 
	std::cout << "ScavTrap's Paramterized contructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap( src ){ 

	std::cout << "ScavTrap's Copy constructor called" << std::endl;
	return;
}

ScavTrap::~ScavTrap( void ) {
	
	std::cout << "ScavTrap's Destructor called" << std::endl;
	return;
}


ScavTrap& ScavTrap::operator=( ScavTrap const& rhs ) {

	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}


void	ScavTrap::guardGate( void ) {

	std::cout << this->_name << " ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ScavTrap can't attack " << target << " : 0 hit points : I'm so dead! No more battles, just chillin' in the afterlife." << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " ScavTrap can't attack " << target << " : 0 energy points: I'm so exhausted!" << std::endl;
		return;
	}
	if (this->_attackDammage == 0) {
		std::cout << this->_name << " ClapTrap attacks " << target << " but causes no dammage: 0 attack dammage points. I'm so weak!" << std::endl;
		return;
	}

	this->_energyPoints -= 1;
	std::cout 	<< this->_name << " ScavTrap attacks " << target
				<< " causing him to lose " << this->_attackDammage 
				<< " hit points. That must hurt " << target << "..."
				<< std::endl;

	return;
}
