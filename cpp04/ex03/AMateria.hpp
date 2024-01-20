
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "Colors.h"

class ICharacter;

class AMateria
{
protected:
	std::string 			_type;

public:
	AMateria( void );								// ok
	virtual ~AMateria( void );						// ok
	AMateria(AMateria const &src);					// ok
	AMateria& operator=(AMateria const &rhs);		// ok

	AMateria(std::string const &type);				// ok

	std::string const&	 getType( void ) const;		// ok
	virtual AMateria*	clone( void ) const = 0;	// nothing to do
	virtual void		use( ICharacter &target );	// to be overriden
};

#endif
