/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:23 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:24 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Canonical form--------------------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(), _target("") {

	std::cout << ITALIC << "Creating a default ShrubberyCreationForm with Target: ( no name )." << END << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	std::cout << ITALIC << "ShrubberyCreationForm with target " << this->getTarget() << " destroyed" << END << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {

	std::cout << ITALIC << "Creating a copy of ShrubberyCreationForm with target \"" << this->getTarget() << "\"" << END << std::endl;
	return;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {

	if ( this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout	<< ITALIC << "Assigning ShrubberyCreationForm with target " << src.getTarget() << " to " << this->getTarget() << END << std::endl;
	return *this;
}

// Parametrized constructor--------------------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target( target ) {

	std::cout	<< ITALIC	<< "Creating a ShrubberyCreationForm target \"" << this->getTarget() << "\"" << END << std::endl;
	return;

}

// Member functions--------------------------------------------------------------------------------

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true)
		drawTree(executor);
	return;
}

void	ShrubberyCreationForm::drawTree(const Bureaucrat &executor) const {

	std::ofstream file(this->getTarget().append("_shrubbery"), std::ios::app);
	if (file.is_open())
	{
		file	<< "      /\\           " << std::endl
				<< "     /\\*\\     	" << std::endl
				<< "    /\\O\\*\\    	" << std::endl
				<< "   /*/\\/\\/\\    	" << std::endl
				<< "  /\\O\\/\\*\\/\\  	" << std::endl
				<< " /\\*\\/\\*\\/\\/\\ " << std::endl
				<< "/\\O\\/\\/*/\\/O/\\ " << std::endl
				<< "      ||            " << std::endl
				<< "      ||            " << std::endl
				<< "      ||            " << std::endl;

		std::cout << BOLD << "Bureaucrat " << executor.getName() << " executed form \"" << this->getName() << "\" successfully. Drew tree in file " << this->getTarget().append("_shrubbery") << END << std::endl;

		file.close();
	}
	else
	{
		std::cout << RED << "Could not create or open file " << this->getTarget().append("_shrubbery") << std::endl;
	}
	return;
}

// Getters--------------------------------------------------------------------------------

std::string ShrubberyCreationForm::getTarget( void ) const {

	return ( this->_target == "" ? "( no name )" : this->_target );
}

// Operator--------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& stream, ShrubberyCreationForm const& object ) {

	stream	<< BOLD
			<< "Form: " << object.getName()
			<< ", target: \"" << object.getTarget()
			<< "\", signed: " << ( object.getSigned() ? "true" : "false" )
			<< ", grade to sign: " << object.getGradeSign()
			<< ", grade to exec: " << object.getGradeExec()
			<< END << std::endl;
	return stream;
}
