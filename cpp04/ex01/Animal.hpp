/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 15:04:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {

protected:
	std::string _type;

public:
	Animal( void );
	virtual ~Animal( void );
	Animal( Animal const& src );
	Animal& operator=(Animal const& rhs);

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;

	
	//only for testing-------------------------------------------------
	virtual	void			setBrainIdea(size_t i, std::string const idea) const;
	virtual	void			printBrainIdeas( std::ostream& stream ) const;

};

std::ostream& operator<<(std::ostream& stream, Animal const& animal);

#endif
