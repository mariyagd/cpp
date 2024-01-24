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

	AForm			*form = 0;
	int const		size = 3;
	std::string		formTable[size] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	enum 			formEnum{ SHRUBBERY, ROBOTOMY, PRESIDENTIAL };

	int i;
	for (i = 0; i < size && formName != formTable[i]; i++);

	switch (i) {
		case SHRUBBERY :
			form = new ShrubberyCreationForm(formTarget);
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(formTarget);
			break;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cerr << RED << "Form name \"" << formName << "\" doesn't exists. Intern could not create it." <<  END << std::endl;
	}
	if (form != 0)
		std::cout << BOLD << "Intern created a form named \"" << form->getName() << "\"" <<  END << std::endl;
	return form;
}
