/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
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
	std::cout << "FragTrap's Parametrized constructor called" << std::endl;
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

	std::cout << "FragTrap's Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}


void	FragTrap::highFivesGuys( void ) const {

	std::cout << this->_name << " FragTrap request a high five." << std::endl;
	return;
}