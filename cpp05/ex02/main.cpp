#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum 			formEnum{ SHRUBBERY, ROBOTOMY, PRESIDENTIAL };

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

void	test_double_exec_shrubberry(std::string target, int grade)
{
	try
	{
		ShrubberyCreationForm form(target);
		std::cout << form;

		Bureaucrat bob("Bob", grade);
		std::cout << bob;

		bob.signForm(form);
		bob.executeForm(form);
		bob.executeForm(form);
		bob.executeForm(form);
	}
	catch (const AForm::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const AForm::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();

}


void	print_form_info(const int i, AForm *form)
{
	switch (i) {
		case SHRUBBERY :
			std::cout << dynamic_cast<ShrubberyCreationForm&>(*form);
			break;
		case ROBOTOMY:
			std::cout << dynamic_cast<RobotomyRequestForm&>(*form);
			break;
		case PRESIDENTIAL:
			std::cout << dynamic_cast<PresidentialPardonForm&>(*form);
			break;
	}
}

void	test_exec( std::string formName, AForm *form, std::string formTarget, int bureaucratGrade )
{
	try
	{
		const int 		size = 3;
		std::string		formTable[size] = { "shrubbery", "robotomy", "presidential" };

		int i;
		for (i = -1; i < size && formName != formTable[i]; i++);

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
				return;
		}

		print_form_info(i, form);

		Bureaucrat bob("Bob", bureaucratGrade);
		std::cout << bob;

		bob.executeForm(*form);

		bob.signForm(*form);
		print_form_info(i, form);
		bob.executeForm(*form);
	}
	catch (const AForm::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const AForm::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	delete form;
	form = 0;
}

int main( void )
{
	AForm *form = 0;
	print_line();

	// Shrubbery tests------------------------------------------------------------------------------------
	print_title("Test on Shrubbery form execution");

	test_exec("shrubbery", form, "home", 137);
	print_line();

	test_exec("shrubbery", form, "work", 138);
	print_line();

	print_title("Test on Shrubbery form double execution");
	test_double_exec_shrubberry( "garden", 1);

	// Robotomy tests------------------------------------------------------------------------------------
	print_title("Test on Robotomy form execution");

	test_exec("robotomy", form, "computers", 45);
	print_line();

	test_exec("robotomy", form, "home", 46);
	print_line();

	// Presidential tests------------------------------------------------------------------------------------
	print_title("Test on Presidential form execution");

	test_exec("presidential", form, "John", 5);
	print_line();

	test_exec("presidential", form, "David", 6);
	print_line();

}
