/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:45:43 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:45:45 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

	// for constructors
	void			deleteThisInventory( void );

	// for testing
	size_t			getMateriaSourceInventorySize( void ) const;
	std::string		getMateriaSourceInventory( void ) const;
	AMateria*		getAddress( size_t idx);

};

std::ostream&	operator<<( std::ostream& stream, MateriaSource const &materiaSource );

#endif
