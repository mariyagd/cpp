/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 14:23:19 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

private:
	Brain		*_brain;

public:
	Cat( void );
	~Cat( void );
	Cat( Cat const& src );
	Cat& operator=(Cat const& rhs);

	void	makeSound( void ) const;
	
	// for testing-------------------------------------------------
	void			setBrainIdea(size_t i, std::string const idea) const;
	void			printBrainIdeas( std::ostream& stream ) const;

};

#endif
