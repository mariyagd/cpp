/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:15 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:47:16 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	std::string const	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;

	static const int 	_gradeMax;
	static const int 	_gradeMin;


public:
	Form( void );
	~Form( void );
	Form( Form const &src);
	Form &operator=( Form const &src );

	Form(std::string name, int gradeSign, int gradeExec);

	std::string const	getName( void ) const;
	bool				getSigned( void ) const;
	int					getGradeSign( void ) const;
	int					getGradeExec( void ) const;

	void				beSigned( const Bureaucrat & bureaucrat );


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &stream, Form const &object );

#endif
