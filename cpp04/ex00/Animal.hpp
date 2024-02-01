/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 09:27:34 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {

protected:
	std::string _type;

public:
	Animal( void );
	virtual ~Animal( void );							// virtual
	Animal( Animal const& src );
	Animal& operator=(Animal const& rhs);

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;			// virtual

};

std::ostream& operator<<(std::ostream& stream, Animal const& animal);

#endif
