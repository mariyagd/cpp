#include "PresidentialPardonForm.hpp"

// Canonical form--------------------------------------------------------------------------------

 PresidentialPardonForm:: PresidentialPardonForm( void ) : AForm(), _target("") {

	std::cout << ITALIC << "Creating a default  PresidentialPardonForm with Target: ( no name )." << END << std::endl;
	return;
}

 PresidentialPardonForm::~ PresidentialPardonForm( void ) {

	std::cout << ITALIC << "PresidentialPardonForm with target " << this->getTarget() << " destroyed" << END << std::endl;
	return;
}

 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm &src) : AForm(src), _target(src._target) {

	std::cout << ITALIC << "Creating a copy of  PresidentialPardonForm with target \"" << this->getTarget() << "\"" << END << std::endl;
	return;
}

 PresidentialPardonForm&	 PresidentialPardonForm::operator=( PresidentialPardonForm const& src) {

	if ( this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout	<< ITALIC << "Assigning  PresidentialPardonForm with target " << src.getTarget() << " to " << this->getTarget() << END << std::endl;
	return *this;
}

// Parametrized constructor--------------------------------------------------------------------------------

 PresidentialPardonForm:: PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target( target ) {

	std::cout	<< ITALIC	<< "Creating a  PresidentialPardonForm target \"" << this->getTarget() << "\"" << END << std::endl;
	return;

}

// Member functions--------------------------------------------------------------------------------

void  PresidentialPardonForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true)
	{
		std::cout	<< BOLD << "Target " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl
					<< executor.getName() << " executed form \"" << this->getName() << "\" successfully" << END <<std::endl;
	}
	return;
}

// Getters--------------------------------------------------------------------------------

std::string  PresidentialPardonForm::getTarget( void ) const {

	return ( this->_target == "" ? "( no name )" : this->_target );
}

// for testing
std::string PresidentialPardonForm::getType( void ) const {

	return "presidential";
};

// Operator--------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& stream,  PresidentialPardonForm const& object ) {

	stream	<< BOLD << "PresidentialPardonForm exists with target \"" << object.getTarget()
			  << "\". Form's name: \"" << object.getName()
			  << "\", signed: " << ( object.getSigned() ? "true" : "false" )
			  << ", grade to sign: " << object.getGradeSign()
			  << ", grade to exec: " << object.getGradeExec()
			  << END << std::endl;
	return stream;
}