/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:11 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:47:12 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define ITALIC		"\033[2;3m"
# define END		"\033[0m"
# define BLUE		"\033[1;34m"
# define BOLD		"\033[1m"
# define RED		"\033[1;31m"

class Form;

class Bureaucrat {
	
private:
	std::string const		_name;
	int						_grade;
	static const int 		gradeMin;
	static const int 		gradeMax;


public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src );
	Bureaucrat&	operator=( Bureaucrat const &rhs );

	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void			increment( void );
	void			decrement( void );

	void			signForm( Form &form );

	class GradeTooHighException : public std::exception
	{

	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:
		const char* what() const throw();
	};
};

std::ostream&	operator<< ( std::ostream &stream, Bureaucrat const &object );

#endif



