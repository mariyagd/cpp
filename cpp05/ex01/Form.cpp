/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:04 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:47:05 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Static variables initialization------------------------------------------------------------------------------------

const int Form::_gradeMax = 1;
const int Form::_gradeMin = 150;

//Canonical form-----------------------------------------------------------------------------------------------------

Form::Form( void ) : _name(""), _signed(false), _gradeSign(0), _gradeExec(0) {

	std::cout << ITALIC << "Default form created. Name: ( no name ), signed: false, grade to sign: 0, grade to exec: 0" << END << std::endl;
	return ;
}

Form::~Form( void ) {

	std::cout << ITALIC << "Form " << this->getName() << " destroyed" << END << std::endl;
	return ;
}

Form::Form( Form const &src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {

	std::cout	<< ITALIC << "Creating a copy of form \"" << this->getName() << "\"" << END << std::endl;
	return ;
}

Form&	Form::operator=( Form const &src ) {

	std::cout	<< ITALIC << "Assigning form \"" << src.getName() << "\" to " << this->getName() << END << std::endl;

	if (this != &src)
	{
		this->_signed = src._signed;
		const_cast<std::string &>(this->_name) = src._name;
		const_cast<int &>(this->_gradeSign) = src._gradeSign;
		const_cast<int &>(this->_gradeExec) = src._gradeExec;
	}
	return (*this);
}

// Parametrized constructor------------------------------------------------------------------------------------------

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

	std::cout	<< ITALIC	<< "Trying to create a form \"" << this->getName()
							<< "\", not signed, grade to sign: " << this->_gradeSign
							<< ", grade to exec: " << this->_gradeExec << END << std::endl;

	if (this->_gradeSign < _gradeMax || this->_gradeExec < _gradeMax)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > _gradeMin || this->_gradeExec > _gradeMin)
		throw Form::GradeTooLowException();
	return ;
}

// Getters------------------------------------------------------------------------------------------------------------
std::string const	Form::getName( void ) const {

	return (this->_name.empty() ? "( no name )" : this->_name);
}

bool	Form::getSigned( void ) const {

	return (this->_signed);
}

int		Form::getGradeSign( void ) const {

	return (this->_gradeSign);
}

int		Form::getGradeExec( void ) const {

	return (this->_gradeExec);
}

// Member functions---------------------------------------------------------------------------------------------------

void	Form::beSigned( Bureaucrat &bureaucrat ) {

	if ((bureaucrat.getGrade() <= this->_gradeSign) && this->_signed == false)
			this->_signed = true;
	return ;
}

// Exceptions functions------------------------------------------------------------------------------------------------

const char* Form::GradeTooLowException::what() const throw() {

	return ("Exception thrown. Grade too low.");
}

const char* Form::GradeTooHighException::what() const throw() {

	return ("Exception thrown. Grade too high.");
}


// Operator overload--------------------------------------------------------------------------------------------------

std::ostream&	operator<<( std::ostream &stream, Form const &object ) {

	stream	<< BOLD
			<< "Form \"" << object.getName()
			<< "\" exists. Form's info: signed: " << ( object.getSigned() ? "true" : "false" )
			<< ", grade to sign: " << object.getGradeSign()
			<< ", grade to exec: " << object.getGradeExec()
			<< END << std::endl;
	return (stream);
}
