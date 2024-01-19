
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	static const size_t		_size;
	AMateria 				**_inventory;

public:
	MateriaSource( void );
	~MateriaSource( void );
	MateriaSource( MateriaSource const &src);
	MateriaSource&	operator=( MateriaSource const &rhs );

	void		learnMateria( AMateria* );
	AMateria*	createMateria( std::string const &type );
};

#endif