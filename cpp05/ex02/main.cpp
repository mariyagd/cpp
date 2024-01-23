#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void	test_exec_shrubberry(std::string target, int grade)
{
	try
	{
		ShrubberyCreationForm form(target);
		std::cout << form;

		Bureaucrat bob("Bob", grade);
		std::cout << bob;

		bob.executeForm(form);

		bob.signForm(form);
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

void	test_exec_robotomy(std::string target, int grade)
{
	try
	{
		RobotomyRequestForm form(target);
		std::cout << form;

		Bureaucrat bob("Bob", grade);
		std::cout << bob;

		bob.executeForm(form);

		bob.signForm(form);
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

void	test_exec_president(std::string target, int grade)
{
	try
	{
		PresidentialPardonForm form(target);
		std::cout << form;

		Bureaucrat bob("Bob", grade);
		std::cout << bob;

		bob.executeForm(form);

		bob.signForm(form);
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


int main( void )
{

	print_title("Test on Shrubbery form execution");
	test_exec_shrubberry( "home", 137);
	test_exec_shrubberry( "work", 138);

//	print_title("Test on Shrubbery form double execution");
//	test_double_exec_shrubberry( "garden", 1);

//	print_title("Test on Robotomy form execution");
//	test_exec_robotomy( "home", 45);
//	test_exec_robotomy( "work", 46);

//	print_title("Test on Presidential form execution");
//	test_exec_president( "John", 5);
//	test_exec_president( "David", 6);

}
