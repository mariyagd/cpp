#include "Intern.hpp"

// Canonical form---------------------------------------------------------------------------------------------

Intern::Intern( void ) {

	std::cout << ITALIC << "Default Intern created" << END << std::endl;
	return;
}

Intern::~Intern( void ) {

	std::cout << ITALIC << "Intern destroyed" << END << std::endl;
	return;
}

Intern::Intern( Intern const &src ) {

	(void)src;
	std::cout << ITALIC << "Copying Intern" << END << std::endl;
	return;
}

Intern&	Intern::operator=( Intern const &src ) {

	(void)src;
	std::cout << ITALIC << "Assigning an Intern" << END << std::endl;
	return *this;
}

// Member functions------------------------------------------------------------------------------------

AForm*	Intern::makeForm(std::string formName, std::string formTarget) {

	AForm	*form = 0;
	int const size = 3;
	std::string formTable[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	enum 		formEnum{ SHRUBBERY, ROBOTOMY, PRESIDENTIAL };

	int flag = -1;

	for ( int i = 0; i < size; i++) {
		if (formName == formTable[i]) {
			flag = i;
			break;
		}
	}
	switch (flag) {
		case SHRUBBERY :
			form = new ShrubberyCreationForm(formTarget);
			std::cout << BOLD << "Intern created a form named \"" << form->getName() << "\"" <<  END << std::endl;
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(formTarget);
			break;
			std::cout << BOLD << "Intern created a form named \"" << form->getName() << "\"" <<  END << std::endl;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(formTarget);
			break;
			std::cout << BOLD << "Intern created a form named \"" << form->getName() << "\"" <<  END << std::endl;
		default:
		{
			std::cerr << RED << "Form name \"" << formName << "\" doesn't exists. Intern could not create it." <<  END << std::endl;
		}
	}
	return form;
}
