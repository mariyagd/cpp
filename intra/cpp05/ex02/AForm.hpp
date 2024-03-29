/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:34 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:36 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;

	static const int 	_gradeMax;
	static const int 	_gradeMin;


public:
	AForm( void );
	virtual ~AForm( void );													// virtual destructor
	AForm( AForm const &src);
	AForm &operator=( AForm const &src );

	AForm(std::string name, int gradeSign, int gradeExec);

	std::string const	getName( void ) const;
	bool				getSigned( void ) const;
	int					getGradeSign( void ) const;
	int					getGradeExec( void ) const;

	void				beSigned( Bureaucrat &bureaucrat );


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	virtual void execute( Bureaucrat const &executor ) const = 0;			// pure virtual
};

std::ostream &operator<<( std::ostream &stream, AForm const &object );

#endif
