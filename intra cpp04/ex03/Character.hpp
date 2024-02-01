/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:45:15 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:45:16 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {

private:
	std::string				_name;
	static const size_t		_size;
	AMateria 				**_inventory;

public:
	Character( void );										// ok
	Character(Character const &src);						// ok
	Character& operator=(Character const &rhs);				// ok

	Character(std::string const &name);						// ok

	~Character( void );										// override
	std::string	const&	getName( void ) const;				// override
	void				equip(AMateria* m);					// override
	void				unequip(int idx);					// override
	void				use(int idx, ICharacter& target);	// override

	// for constructors
	void				deleteThisInventory( void );

	// for testing
	size_t 				getInventorySize( void ) const;
	std::string			getInventory( void ) const;
	void				printInventoryAdresses( void ) const;
};

std::ostream &operator<<(std::ostream &stream, Character const &character);

#endif

// Path: Character.cpp
