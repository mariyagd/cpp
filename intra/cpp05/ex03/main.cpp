#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	print_line( void )
{
	std::cout << BLUE << std::setfill('-') << std::setw(50) << "-" << END << std::endl;
}

void	print_small_line( void )
{
	std::cout << BLUE << std::setfill('-') << std::setw(5) << "-" << END << std::endl;
}

void	print_title( std::string title )
{
	std::cout << std::endl << BLUE << title << END << std::endl;
	print_line();
}

void	tests_intern( Intern& intern, std::string formName, std::string formTaregt, Bureaucrat &bureaucrat)
{
	(void)bureaucrat;
	AForm* form;
	form = intern.makeForm(formName, formTaregt);
	if (!form)
		return;
	if (form->getType() == "shrubbery")
		std::cout << dynamic_cast< ShrubberyCreationForm & >(*form);
	else if (form->getType() == "robotomy")
		std::cout << dynamic_cast <RobotomyRequestForm & >(*form);
	else if (form->getType() == "presidential")
		std::cout << dynamic_cast< PresidentialPardonForm & >(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

int main( void )
{

	print_title("Tests on Intern");
	Intern intern;
	Bureaucrat bob("Bob", 1);
	std::cout << bob;
	print_small_line();

	tests_intern(intern, "shrubbery creation", "Garden", bob);
	print_small_line();

	tests_intern(intern, "robotomy request", "Bender", bob);
	print_small_line();

	tests_intern(intern, "presidential pardon", "Billy", bob);
	print_small_line();

	tests_intern(intern, "food list", "Billy", bob);
	print_small_line();
}
