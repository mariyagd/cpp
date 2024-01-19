#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class ICharacter;


class Ice : public AMateria
{

public:
	Ice( void );								// ok
	virtual ~Ice( void );						// ok
	Ice(Ice const &src);						// ok
	Ice& operator=(Ice const & rhs);			// ok

	void			use( ICharacter &target );	// override

	virtual Ice*	clone( void ) const;		// ok
};
#endif
