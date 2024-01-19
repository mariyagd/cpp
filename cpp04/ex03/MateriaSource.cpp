#include "MateriaSource.hpp"

const size_t MateriaSource::_size = 4;

MateriaSource::MateriaSource( void ) : _inventory(new AMateria*[_size] ) {

	std::cout << "MateriaSource's Constructor called" << std::endl;
	return;
}

MateriaSource::~MateriaSource( void ) {

	std::cout << "MateriaSource's Destructor called" << std::endl;
	if (!this->_inventory)
		return;
	for ( size_t i = 0; i < _size; i++)
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

MateriaSource::MateriaSource( MateriaSource const &src) : _inventory(0) {

	std::cout << "MateriaSource's Copy constructor called" << std::endl;
	if (!src._inventory)
		return;
	this->_inventory = new AMateria*[_size];
	for (size_t i = 0; i < _size && src._inventory[i]; i++)
		this->_inventory[i] = src._inventory[i]->clone();
}

MateriaSource&	MateriaSource::operator=( MateriaSource const &rhs ) {

	std::cout << "MateriaSource's Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	for (size_t i = 0; i < _size; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria *m ) {

	for (size_t i = 0; i < (int)_size; i++)
	{
		if ( !this->_inventory[i] )
			this->_inventory[i] = m;
	}
	std::cout << "Materia " << m->getType() << " learned" << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const &type ) {

	if (!this->_inventory)
	{
		std::cout << ITALIC << REDDY << " This MateriaSource' inventory is empty" << END << std::endl;
	}
	for (size_t i = 0; i < (int)_size; i++)
	{
		if (this->_inventory[i]->getType() == type)
			return ( this->_inventory[i]->clone());
	}
	return 0;

}