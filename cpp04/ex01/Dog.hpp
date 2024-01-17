/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 15:33:58 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

private:
	Brain		*_brain;

public:
	Dog( void );
	~Dog( void );
	Dog( Dog const& src );
	Dog& operator=(Dog const& rhs);

	void	makeSound( void ) const;
	
	// for testing-------------------------------------------------
	void			setBrainIdea(size_t i, std::string const idea) const;
	void			printBrainIdeas( std::ostream& stream ) const;

};

#endif
