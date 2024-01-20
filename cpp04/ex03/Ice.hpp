#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice( void );								// ok
	virtual ~Ice( void );						// ok
	Ice(Ice const &src);						// ok
	Ice& operator=(Ice const & rhs);			// ok

	virtual Ice*	clone( void ) const;		// override ok
	void			use( ICharacter &target );	// override

};
#endif
