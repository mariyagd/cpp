#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
public:
	Cure( void );								// ok
	virtual ~Cure( void );						// ok
	Cure(Cure const &src);						// ok
	Cure& operator=(Cure const & rhs);			// ok

	virtual Cure*	clone( void ) const;		// override ok
	void			use( ICharacter &target );	// override

};
#endif
