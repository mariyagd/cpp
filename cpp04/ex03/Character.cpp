/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:44:23 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:44:24 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

const size_t Character::_size = 4;

Character::Character( void ) : _name("default"), _inventory(new AMateria*[_size]) {

//	std::cout << ITALIC << DIM << "Character's Default constructor called" << END << std::endl;
	return ;
}



Character::Character(Character const &src) : _name(src._name), _inventory(0) {

//	std::cout << ITALIC << DIM << "Character's Copy constructor called" << END << std::endl;
	if (!src._inventory) {
		std::cout << ITALIC << DIM << "Copy " << src._name << " has no inventory. No copy. " << END << std::endl;
		return;
	}
	this->_inventory = new AMateria*[_size];
	if (src.getInventorySize() == 0) {
		std::cout << ITALIC << DIM << "Copy " << src._name << " successfully. Copied an empty inventory." << END << std::endl;
		return;
	}
	for (size_t i = 0; i < _size && src._inventory[i]; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
	std::cout << ITALIC << DIM << "Copy " << src._name << " successfully" << END << std::endl;
	return ;
}

void	Character::deleteThisInventory( void ) {

	if (!this->_inventory)
		return;
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = 0;
		}
	}
	delete [] this->_inventory;
	this->_inventory = 0;
}

Character&		Character::operator=(Character const &rhs) {

//	std::cout << ITALIC << DIM << "Character's Assignment operator called" << END << std::endl;
	if (this == &rhs) {
		return *this;
	}
	this->_name = rhs._name;
	if (!rhs._inventory) {
		std::cout << "Assignment " << rhs._name << " has no inventory. No assignment. " << std::endl;
	}
	deleteThisInventory();
	this->_inventory = new AMateria*[_size];
	for (size_t i = 0; i < _size; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	std::cout << ITALIC << DIM << rhs._name << " assigned successfully." << END << std::endl;
	return (*this);
}

Character::Character( std::string const &name ) : _name(name), _inventory( new AMateria*[_size]) {

	std::cout << ITALIC << DIM << "Character " << name << " created" << END << std::endl;
//	std::cout << ITALIC << DIM << "Character's Parametrized constructor called" << END << std::endl;
	return;
}

Character::~Character( void ) {

//	std::cout << ITALIC << DIM << "Character's Destructor called" << END << std::endl;
	if (!this->_inventory)
		return;
	deleteThisInventory();
	std::cout << ITALIC << DIM << this->_name << "'s inventory deleted successfully." << END << std::endl;
}

std::string const&	Character::getName() const {

	return this->_name;
}

void	Character::equip( AMateria* m ) {

	std::cout << ITALIC << DIM << this->_name  << " is trying to equip a materia." << END << std::endl;
	if (!this->_inventory) {
		std::cout << ITALIC << DIM << "Could not equip " << this->_name << ". No materia inventory." << END << std::endl;
		return;
	} else if (!m) {
		std::cout << ITALIC << DIM << "Could not equip " << this->_name << ". This materia is a null pointer." << END << std::endl;
		return;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory[i] && this->_inventory[i] == m) {
			std::cout << ITALIC << DIM << this->_name << " is already equipped with this materia. Same addresses: " << m << END << std::endl;
			return;
		}
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			std::cout << ITALIC << DIM << "Character " << this->_name << " successfully equipped with " << m->getType() << END << std::endl;
			return;
		}
	}
	std::cout << ITALIC << DIM << "Could not equip " << this->_name << ". Materia inventory is already full" << END << std::endl;
	return;
}

void	Character::unequip( int idx ) {

	std::cout << ITALIC << DIM << this->_name << " is trying to unquipp a materia in inventory[" << idx << "]" << END << std::endl;
	if ( idx < 0 || idx >= (int)_size ) {
		std::cout << ITALIC << DIM << "Could not unequip " << this->_name  << ". Invalid index." << END << std::endl;
		return;
	} else if (!this->_inventory) {
		std::cout << ITALIC << DIM << "Could not unequip " << this->_name << ". No inventory." << END << std::endl;
		return;
	} else if (getInventorySize() == 0) {
		std::cout << ITALIC << DIM << "Could not unequip " << this->_name << ". Empty inventory."  << END << std::endl;
		return;
	} else if (!this->_inventory[idx]) {
		std::cout << ITALIC << DIM << "Could not unequip " << this->_name << ". Inventory is empty at index " << idx   << END << std::endl;
		return;
	}

	AMateria **new_inventory = new AMateria*[_size];

	for (size_t i = 0, j = 0; i < _size; i++) {
		if (this->_inventory[i] && i != (size_t)idx) {
			new_inventory[j] = this->_inventory[i]->clone();
			j++;
		}
	}
	deleteThisInventory();
	this->_inventory = new_inventory;
	std::cout << ITALIC << DIM << this->_name << " is successfully unequipped" << END << std::endl;
}


void	Character::use(int idx, ICharacter &target) {

	std::cout << ITALIC << DIM << this->_name << " is trying to use a materia in inventory[" << idx << "]" << END << std::endl;
	if (idx < 0 || idx >= (int)_size ) {
		std::cout << ITALIC << DIM << "Could not use materia. Invalid index" << END << std::endl;
		return;
	} else if (!this->_inventory )
	{
		std::cout << ITALIC << DIM << "Could not use materia. No inventory" << END << std::endl;
		return;
	} else if (!this->_inventory[idx]) {
		std::cout << ITALIC << DIM << "Could not use materia. No materia at index " << idx << END << std::endl;
		return;
	} else if (getInventorySize() == 0 ) {
		std::cout << ITALIC << DIM << "Could not use materia. Empty inventory" << END << std::endl;
		return;
	} else if (!this->_inventory[idx]) {
		std::cout << ITALIC << DIM << "Could not use materia. No materia at index " << idx << END << std::endl;
		return;
	}
	this->_inventory[idx]->use( target );
}

size_t	Character::getInventorySize( void ) const {

	size_t size = 0;

	if (!this->_inventory)
		return 0;
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory[i])
			size++;
	}
	return size;
}

std::string	Character::getInventory( void ) const {

	std::string inventory;

	if (!this->_inventory)
		return ("( no inventory )");
	else if (this->_inventory && this->_inventory[0])
		inventory = this->_inventory[0]->getType();
	else
		inventory = "( empty inventory )";
	for (size_t i = 1; i < _size; i++)
	{
		if (this->_inventory[i])
			inventory += ", " + this->_inventory[i]->getType();
	}
	return inventory;
}

void	Character::printInventoryAdresses( void ) const {

	if (!this->_inventory || !this->_inventory[0])
	{
		std::cout << "( no addresses )" << std::endl;
		return;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory[i])
			std::cout << this->_inventory[i] << " ";
	}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Character const &character) {

	stream	<< character.getName()
			<< "'s inventory's size is "
			<< character.getInventorySize()
			<< " : "
			<< character.getInventory() << END << std::endl;

	return stream;
}

