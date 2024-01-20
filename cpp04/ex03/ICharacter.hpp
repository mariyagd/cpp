#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter {

public:
	virtual ~ICharacter( void ) {}										// nothing to do
	virtual std::string	const&	getName( void ) const = 0;				// nothing to do
	virtual void				equip(AMateria* m) = 0;					// nothing to do
	virtual void				unequip(int idx) = 0;					// nothing to do
	virtual void				use(int idx, ICharacter& target) = 0;	// nothing to do
};

#endif