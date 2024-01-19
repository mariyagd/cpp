
#include "Character.hpp"

const size_t Character::_size = 4;

Character::Character( void ) : _name("default"), _inventory(new AMateria*[_size]) {

	std::cout << "Character's Default constructor called" << std::endl;
	return ;
}

Character::Character(Character const &src) : _name(src._name), _inventory(0) {

	std::cout << "Character's Copy constructor called" << std::endl;
	if (!src._inventory)
		return;
	this->_inventory = new AMateria*[_size];
	for (size_t i = 0; i < _size && src._inventory[i]; i++)
	{
		this->_inventory[i] = src._inventory[i]->clone();
	}
return ;
}

Character&		Character::operator=(Character const &rhs) {

	std::cout << "Character's Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		if (this->_inventory)
		{
			delete [] this->_inventory;
			this->_inventory = new AMateria*[_size];
			for (size_t i = 0; i < _size; i++)
			{
				this->_inventory[i] = rhs._inventory[i]->clone();
			}
		}
	}
	return (*this);
}

Character::Character( std::string const &name ) : _name(name), _inventory( new AMateria*[_size]) {

	std::cout << "Character's Parametrized constructor called" << std::endl;
	return;
}

Character::~Character( void ) {

	std::cout << "Character's Destructor called" << std::endl;
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

std::string const&	Character::getName() const {

	return this->_name;
}

void	Character::equip( AMateria* m ) {

	if (!this->_inventory)
		return;
	for (size_t i = 0; i < _size; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m->clone();
			return;
		}
	}
}

void	Character::unequip( int idx ) {

	AMateria	*tmp = this->_inventory[_size]->clone();
	if (!this->_inventory || !this->_inventory[idx] || idx < 0 || idx >= (int)_size)
		return;
	delete this->_inventory[idx];
	this->_inventory[idx] = 0;

	int i = _size - 1;
	while (i > idx)
	{
		if (this->_inventory[i] && this->_inventory[i - 1])
		{
			tmp = this->_inventory[i - 1]->clone();
			delete this->_inventory[i - 1];
			this->_inventory[i - 1] = this->_inventory[i]->clone();
			delete this->_inventory[i];
			this->_inventory[i] = 0;
		}
		i--;
	}
	if (i == idx && tmp)
	{
		this->_inventory[i] = tmp->clone();
		delete tmp;
		tmp = 0;
	}
}

void	Character::use(int idx, ICharacter &target) {

	if (!this->_inventory || !this->_inventory[idx] || idx < 0 || idx >= (int)_size )
		return;
	this->_inventory[idx]->use( target );
}
