/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:10 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:11 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// static members initialization-----------------------------------------------------------------------------------

const int Bureaucrat::_gradeMax = 1;
const int Bureaucrat::_gradeMin = 150;

// Canonical form constructors--------------------------------------------------------------------------------------

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(0) {

	std::cout << ITALIC << "Creating a default bureaucrat ( no name )  with grade 0 " << END << std::endl;
	return;
}

Bureaucrat::~Bureaucrat( void ) {

	std::cout << ITALIC << "Bureaucrat " << this->getName() << " destroyed" <<  END << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {

	std::cout << ITALIC << "Creating a copy of bureaucrat " << src.getName() << END << std::endl;		// no need to test grade because the source is tested in the parametrized constructor
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {

	std::cout << ITALIC << "Assigning bureaucrat " << rhs.getName() << " to " << this->getName() << END << std::endl;

	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs._name;
		this->_grade = rhs._grade;
	}
	return *this;																					// no need to test grade because the source is tested in the parametrized constructor
}

// Parametrized constructor----------------------------------------------------------------------------------------

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)  {

	std::cout << ITALIC << "Trying to create bureaucrat " << this->getName() << " with grade " << grade <<  END << std::endl;
	if (this->_grade < _gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > _gradeMin)
		throw Bureaucrat::GradeTooLowException();
	return;
}

// Getters functions----------------------------------------------------------------------------------------------

std::string	Bureaucrat::getName( void ) const {

	return ( this->_name.empty() ? "( no name )" :  this->_name );
}

int	Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

// Increment & decrement functions--------------------------------------------------------------------------------

void	Bureaucrat::increment() {

	std::cout << ITALIC << "Incrementing bureaucrat " << this->getName() <<  "'s grade" << END << std::endl;
	this->_grade -= 1;
	if (this->_grade < _gradeMax)
		throw Bureaucrat::GradeTooHighException();
	return;
}

void	Bureaucrat::decrement() {

	std::cout << ITALIC << "Decrementing bureaucrat " << this->getName() <<  "'s grade" << END << std::endl;
	this->_grade += 1;
	if (this->_grade > _gradeMin)
		throw Bureaucrat::GradeTooLowException();
	return;
}

// Operator---------------------------------------------------------------------------------------------------

std::ostream&	operator<<( std::ostream &stream, Bureaucrat const &object ) {

	stream << BOLD << "Bureaucrat " << object.getName() << " exists with grade " << object.getGrade() << END << std::endl;
	return stream;
}


// Exception classes--------------------------------------------------------------------------------------------

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception thrown. Grade is too high.");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception thrown. Grade is too low.");
}

// Member functions--------------------------------------------------------------------------------------------

void	Bureaucrat::signForm( AForm &form ) {

	std::cout << ITALIC << this->getName() << " tries to sign form \"" << form.getName() << "\"" << END << std::endl;
	if ( this->_grade <= form.getGradeSign() )
	{
		if ( form.getSigned() == false )
		{
			form.beSigned(*this);
			std::cout << BOLD << "Bureaucrat " << this->getName() << " signed form \"" << form.getName() << "\" successfully" << END << std::endl;
		}
		else
			std::cout << BOLD << "Bureaucrat " << this->getName() << " could not sign form \"" << form.getName() << "\" because it is already signed" << END << std::endl;
	}
	else
	{
		std::cout << BOLD << "Bureaucrat " << this->getName() << " could not sign form \"" << form.getName() << "\" because his grade is too low" << END << std::endl;
		throw AForm::GradeTooLowException();
	}
	return ;
}

void	Bureaucrat::executeForm( const AForm &form ) {

	try
	{
		form.execute(*this);
	}
	catch ( const AForm::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << END << std::endl;

	}
}
