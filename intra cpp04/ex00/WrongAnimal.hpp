/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:54 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 14:50:13 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {

protected:
	std::string _type;

public:
	WrongAnimal( void );
	~WrongAnimal( void );
	WrongAnimal( WrongAnimal const& src );
	WrongAnimal& operator=(WrongAnimal const& rhs);

	std::string		getType( void ) const;
	void	makeSound( void ) const;

};

std::ostream& operator<<(std::ostream& stream, WrongAnimal const& animal);

#endif
