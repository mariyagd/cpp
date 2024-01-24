/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:48 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:50 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class  PresidentialPardonForm : public AForm {

private:
	std::string 			_target;

public:
	 PresidentialPardonForm( void );
	~ PresidentialPardonForm( void );
	 PresidentialPardonForm(  PresidentialPardonForm const &src );
	 PresidentialPardonForm&	operator=(  PresidentialPardonForm const& src);

	 PresidentialPardonForm( std::string target );

	void	execute( Bureaucrat const& executor ) const; //overrides

	std::string getTarget( void ) const;
};

std::ostream& operator<<( std::ostream&,  PresidentialPardonForm const& object);

#endif
