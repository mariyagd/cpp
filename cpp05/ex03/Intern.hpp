#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern( void );
	~Intern( void );
	Intern( Intern const& src );
	Intern& operator=( Intern const& src );

	AForm*	makeForm(std::string formName, std::string formTarget);

};


#endif