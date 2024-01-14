/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrag.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:27:58 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:20:33 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {

	std::cout << "FragTrap's default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name) :	ClapTrap(name) {	
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDammage = 30; 
	std::cout << "FragTrap's Paramterized contructor called" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const& src ) : ClapTrap( src ){ 

	std::cout << "FragTrap's Copy constructor called" << std::endl;
	return;
}

FragTrap::~FragTrap( void ) {
	
	std::cout << "FragTrap's Destructor called" << std::endl;
	return;
}


FragTrap& FragTrap::operator=( FragTrap const& rhs ) {

	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}


void	FragTrap::highFivesGuys( void ) {

	std::cout << this->_name << " FragTrap request a high five." << std::endl;
	return;
}

void FragTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0) {
		std::cout << this->_name << " FragTrap can't attack " << target << " : 0 hit points : I'm so dead! No more battles, just chillin' in the afterlife." << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " FragTrap can't attack " << target << " : 0 energy points: I'm so exhausted!" << std::endl;
		return;
	}
	if (this->_attackDammage == 0) {
		std::cout << this->_name << " ClapTrap attacks " << target << " but causes no dammage: 0 attack dammage points. I'm so weak!" << std::endl;
		return;
	}

	this->_energyPoints -= 1;
	std::cout 	<< this->_name << " FragTrap attacks " << target
				<< " causing him to lose " << this->_attackDammage 
				<< " hit points. That must hurt " << target << "..."
				<< std::endl;

	return;
}
