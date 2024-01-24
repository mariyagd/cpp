/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:07 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:08 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Static variables initialization------------------------------------------------------------------------------------

const int AForm::_gradeMax = 1;
const int AForm::_gradeMin = 150;

//Canonical AForm-----------------------------------------------------------------------------------------------------

AForm::AForm( void ) : _name(""), _signed(false), _gradeSign(0), _gradeExec(0) {

	std::cout << ITALIC << "Default AForm created. Name: ( no name ), signed: false, grade to sign: 0, grade to exec: 0" << END << std::endl;
	return ;
}

AForm::~AForm( void ) {

	std::cout << ITALIC << "AForm " << this->getName() << " destroyed" << END << std::endl;
	return ;
}

AForm::AForm( AForm const &src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {

	std::cout << ITALIC << "Creating a copy of AForm \"" << this->getName() << "\"" << END << std::endl;
	return ;
}

AForm&	AForm::operator=( AForm const &src ) {

	std::cout	<< ITALIC << "Assigning AForm \"" << src.getName() << "\" to " << this->getName() << END << std::endl;

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

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

	std::cout	<< ITALIC	<< "Trying to create a AForm \"" << this->getName()
							<< "\", not signed, grade to sign: " << this->_gradeSign
							<< ", grade to exec: " << this->_gradeExec << END << std::endl;

	if (this->_gradeSign < _gradeMax || this->_gradeExec < _gradeMax)
		throw AForm::GradeTooHighException();
	else if (this->_gradeSign > _gradeMin || this->_gradeExec > _gradeMin)
		throw AForm::GradeTooLowException();
	return ;
}

// Getters------------------------------------------------------------------------------------------------------------
std::string const	AForm::getName( void ) const {

	return (this->_name.empty() ? "( no name )" : this->_name);
}

bool	AForm::getSigned( void ) const {

	return (this->_signed);
}

int		AForm::getGradeSign( void ) const {

	return (this->_gradeSign);
}

int		AForm::getGradeExec( void ) const {

	return (this->_gradeExec);
}

// Member functions---------------------------------------------------------------------------------------------------

void	AForm::beSigned( Bureaucrat &bureaucrat ) {

	if ((bureaucrat.getGrade() <= this->_gradeSign) && this->_signed == false)
	{
		this->_signed = true;
	}
	return ;
}

void  AForm::execute(const Bureaucrat &executor) const {

	std::cout << ITALIC << "Bureaucrat " << executor.getName() << " is trying to execute " << this->getName() << END << std::endl;

	if ( !this->getSigned() )
		std::cout << BOLD << "Bureaucrat " << executor.getName() << " could not execute this form. Form is not signed." << END << std::endl;
	else if (executor.getGrade() > this->_gradeExec)
	{
		std::cout << BOLD << "Bureaucrat " << executor.getName() << " could not execute this form. Grade is too low to execute this form." << END << std::endl;
		throw AForm::GradeTooLowException();
	}

}

// Exceptions functions------------------------------------------------------------------------------------------------

const char* AForm::GradeTooLowException::what() const throw() {

	return ("Exception thrown. Grade too low.");
}

const char* AForm::GradeTooHighException::what() const throw() {

	return ("Exception thrown. Grade too high.");
}


// Operator overload--------------------------------------------------------------------------------------------------

std::ostream&	operator<<( std::ostream &stream, AForm const &object ) {

	stream	<< BOLD
			<< "AForm \"" << object.getName()
			<< "\" exists. AForm's info: signed: " << ( object.getSigned() ? "true" : "false" )
			<< ", grade to sign: " << object.getGradeSign()
			<< ", grade to exec: " << object.getGradeExec()
			<< END << std::endl;
	return (stream);
}
