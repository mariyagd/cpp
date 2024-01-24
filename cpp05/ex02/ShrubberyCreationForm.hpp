/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:49:00 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:49:02 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {

private:
	std::string 			_target;

public:
	ShrubberyCreationForm( void );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const& src);

	ShrubberyCreationForm( std::string target );

	void	execute( Bureaucrat const& executor ) const; //overrides
	void	drawTree( const Bureaucrat &executor ) const;

	std::string getTarget( void ) const;
};

std::ostream& operator<<( std::ostream&, ShrubberyCreationForm const& object);

#endif
