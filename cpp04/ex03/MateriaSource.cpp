#include "MateriaSource.hpp"

const size_t MateriaSource::_size = 4;

MateriaSource::MateriaSource( void ) : _inventory(new AMateria*[_size] ) {

	std::cout << ITALIC << DIM << "MateriaSource created" << END << std::endl;
//	std::cout << ITALIC << DIM <<< "MateriaSource's Constructor called" << std::endl;
	return;
}

MateriaSource::~MateriaSource( void ) {

//	std::cout << ITALIC << DIM << "MateriaSource's Destructor called" << END << std::endl;
	if (!this->_inventory)
		return;
	size_t size = getMateriaSourceInventorySize();
	for ( size_t i = 0; i < size; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = 0;
		}
	}
	delete [] this->_inventory;
	this->_inventory = 0;
	std::cout << ITALIC << DIM << "MateriaSource's inventory deleted successfully" << END << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const &src) : _inventory(0) {

//	std::cout << ITALIC << DIM <<< "MateriaSource's Copy constructor called" << END << std::endl;
	if (!src._inventory)
		return;
	this->_inventory = new AMateria*[_size];
	for (size_t i = 0; i < _size && src._inventory[i]; i++)
		this->_inventory[i] = src._inventory[i]->clone();
}

void	MateriaSource::deleteThisInventory( void ) {

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

MateriaSource&	MateriaSource::operator=( MateriaSource const &rhs ) {

//	std::cout << ITALIC << DIM <<< "MateriaSource's Copy assignment operator called" << END << std::endl;
	if (this == &rhs)
		return *this;
	deleteThisInventory();
	this->_inventory = new AMateria*[_size];
	for (size_t i = 0; i < _size; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria *m ) {

	std::cout << ITALIC << DIM << "MateriaSource is trying to learn a materia" << END << std::endl;
	if (!m) {
		std::cout << ITALIC << DIM << "Could not learn. This materia is a null pointer" << END << std::endl;
		return;
	} else if (!this->_inventory) {
		std::cout << ITALIC << DIM << "Could not learn " << m->getType() << " . No MateriaSource's inventory" << END << std::endl;
		return;
	} else if (getMateriaSourceInventorySize() == _size) {
		std::cout << ITALIC << DIM << "Could not learn " << m->getType() << ". MateriaSource's inventory is full" << END << std::endl;
		delete m;
		return;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory && this->_inventory[i] == m) {
			std::cout << ITALIC << DIM << "A materia with this address already exists. The materia is already learned" << END << std::endl;
			return;
		}
		if ( !this->_inventory[i] )
		{
			this->_inventory[i] = m;
			std::cout << ITALIC << DIM << "MateriaSource learned " << m->getType() << " successfully"<< END << std::endl;
			return;
		}
	}
	return;
}

AMateria*	MateriaSource::createMateria( std::string const &type ) {

	std::cout << ITALIC << DIM << "MateriaSource is trying to create " << type << END << std::endl;
	if (!this->_inventory) {
		std::cout << ITALIC << DIM << "Could not create materia " << type << ". This MateriaSource has no inventory" << END << std::endl;
		return 0;
	} else if (getMateriaSourceInventorySize() == 0) {
		std::cout << ITALIC << DIM << "Could not create " << type << ". MateriaSource's inventory is empty" << END << std::endl;
		return 0;
	}
	size_t size = getMateriaSourceInventorySize();
	for (size_t i = 0; i < size; i++)
	{
		if (this->_inventory[i]->getType() == type)
		{
			AMateria *materia = this->_inventory[i]->clone();
			std::cout << ITALIC << DIM << "MateriaSource created " << type << " successfully" << END << std::endl;
			return materia;
		}
	}
	std::cout << ITALIC << DIM << "Could not create " << type << ". This materia doesn't exist in MateriaSource's inventory" << END << std::endl;
	return 0;

}

size_t		MateriaSource::getMateriaSourceInventorySize( void ) const {

	size_t size = 0;
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_inventory[size])
			size++;
	}
	return size;
}

std::string MateriaSource::getMateriaSourceInventory( void ) const {

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

std::ostream&	operator<<( std::ostream& stream, MateriaSource const &materiaSource ) {

	stream	<< "Materia source size is "
			<< materiaSource.getMateriaSourceInventorySize()
			<< " : "
			<< materiaSource.getMateriaSourceInventory()
			<< std::endl;
	return stream;
}

AMateria*	MateriaSource::getAddress( size_t idx)
{
	if ( idx < 0 || idx > _size)
		return 0;
	if (!this->_inventory || !this->_inventory[idx])
		return 0;
	return this->_inventory[idx];
}