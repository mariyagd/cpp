/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:58:17 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:07:18 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors----------------------------------------------------------------

ClapTrap::ClapTrap ( void ) :				_name(""), 
											_hitPoints(0),
											_energyPoints(0),
											_attackDammage(0)
{
	std::cout << "ClapTrap's Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap ( std::string name ) :	_name(name),
											_hitPoints(10),
											_energyPoints(10),
											_attackDammage(0) 
{
	std::cout << "ClapTrap's Parametrized constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap ( ClapTrap const& src ) : _name(src._name),
											 _hitPoints(src._hitPoints),
											 _energyPoints(src._energyPoints),
											 _attackDammage(src._attackDammage)
{
	std::cout << "ClapTrap's Copy constructor called" << std::endl;
	return;
}

ClapTrap::~ClapTrap ( void ) {
	
	std::cout << "ClapTrap's Destructor called" << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {

	std::cout << "ClapTrap's Copy assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDammage = rhs._attackDammage;
	return *this;
}

// Public methods--------------------------------------------------------------

void	ClapTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ClapTrap can't attack " << target << " : 0 hit points : I'm so dead! No more battles, just chillin' in the afterlife." << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " ClapTrap can't attack " << target << " : 0 energy points: I'm so exhausted!" << std::endl;
		return;
	}
	if (this->_attackDammage == 0) {
		std::cout << this->_name << " ClapTrap attacks " << target << " but causes no damage: 0 attack damage points. I'm so weak!" << std::endl;
		return;
	}

	this->_energyPoints -= 1;
	std::cout 	<< this->_name << " ClapTrap attacks " << target
				<< " causing him to lose " << this->_attackDammage 
				<< " hit points. How does it feel " << target << "?"
				<< std::endl;

	return;
}

void	ClapTrap::takeDamage( unsigned int ammount ) {
	
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " can't take damage: 0 hit points : I'm so dead! You can't hurt me anymore!" << std::endl;
		return;
	}
	if (ammount == 0) {
		std::cout << this->_name << " was attacked with 0 attack damage points. No injuries incurred. Maybe next time!" << std::endl;
		return;
	}
	if (this->_hitPoints >= ammount) {
		this->_hitPoints -= ammount;
		std::cout	<< this->_name << " takes damage " << ammount << " hit points. Ouuuch!!!! That's bad!"<< std::endl;
	} else {
		this->_hitPoints = 0;
		std::cout	<< this->_name << " takes damage " << ammount << " hit points and dies. R.I.P " << this->_name << std::endl;
	}
	return;
}

void	ClapTrap::beRepaired( unsigned int ammount ) {

	if (this->_hitPoints == 0) {
		std::cout << this->_name << " can't repair: 0 hit points : I'm so dead! Feeling repaired in heaven." << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " can't repair: 0 energy points: I'm so exhausted!" << std::endl;
		return;
	}
	
	this->_hitPoints += ammount;
	this->_energyPoints -= 1;
	std::cout << this->_name << " is reparing getting " << ammount << " hit points. Yeaaah, life is great!" << std::endl;
	return;
}

// Getters---------------------------------------------------------------------

std::string ClapTrap::getName( void ) const {
	return this->_name;
}

unsigned int ClapTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDammage( void ) const {
	return this->_attackDammage;
}

// Operator--------------------------------------------------------------------

std::ostream& operator<<( std::ostream& stream, ClapTrap const& object ) {

	stream 	<< (object.getName() == "" ? "(no name)" : object.getName());
	if (object.getHitPoints() == 0)
		stream << " is dead!" ;
	stream	<< " has " << object.getHitPoints() << " hit points, "
			<< object.getEnergyPoints() << " energy points and " 
			<< object.getAttackDammage() << " attack damage points."
			<< std::endl;

	return stream;
}
