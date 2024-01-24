/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:48:16 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:17 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Canonical form--------------------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm(), _target("") {

	std::cout << ITALIC << "Creating a default RobotomyRequestForm with Target: ( no name )." << END << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	std::cout << ITALIC << "RobotomyRequestForm with target " << this->getTarget() << " destroyed" << END << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {

	std::cout << ITALIC << "Creating a copy of RobotomyRequestForm with target \"" << this->getTarget() << "\"" << END << std::endl;
	return;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {

	if ( this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout	<< ITALIC << "Assigning RobotomyRequestForm with target " << src.getTarget() << " to " << this->getTarget() << END << std::endl;
	return *this;
}

// Parametrized constructor--------------------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotmyForm", 72, 45), _target( target ) {

	std::cout	<< ITALIC	<< "Creating a RobotomyRequestForm target \"" << this->getTarget() << "\"" << END << std::endl;
	return;

}

// Member functions--------------------------------------------------------------------------------

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true )
	{
		std::cout	<< BOLD << "[ Drilling noise ] Drrrrrrrrrrrrrrrrrrrrrrrrr..."
					<< "Target " << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl
					<< executor.getName() << " executed form \"" << this->getName() << "\" successfully" << END <<std::endl;
	}
	return;
}

// Getters--------------------------------------------------------------------------------

std::string RobotomyRequestForm::getTarget( void ) const {

	return ( this->_target == "" ? "( no name )" : this->_target );
}

// Operator--------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& stream, RobotomyRequestForm const& object ) {

	stream	<< BOLD << "RobotomyRequestForm exists with target \"" << object.getTarget()
			  << "\". Form's name: \"" << object.getName()
			  << "\", signed: " << ( object.getSigned() ? "true" : "false" )
			  << ", grade to sign: " << object.getGradeSign()
			  << ", grade to exec: " << object.getGradeExec()
			  << END << std::endl;
	return stream;
}
