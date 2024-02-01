/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:44:15 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 13:11:06 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define BLUE	"\033[0;34m"
# define END		"\033[0m"
# define ITALIC "\033[3m"

class Brain {

	private:
		static const size_t		_size;
		std::string				*_ideas;

	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain &src );
		Brain	&operator=( const Brain &src );

		//for testing-------------------------------------------------
		void			setIdeas( size_t index, std::string const idea );
		std::string		getIdeas( size_t index ) const;
		size_t			getIdeasSize( void ) const;
		size_t			getSizeMax( void ) const;
};

std::ostream& operator<<(std::ostream& stream, Brain const& brain);

#endif
