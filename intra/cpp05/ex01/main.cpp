/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:08 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:47:09 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <iomanip>

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

void	test_on_grades(int gradeSign, int gradeExec)
{
	try
	{
		Form form("Work contract", gradeSign, gradeExec);
		std::cout << form;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();

}
void	test_on_copy_constructor( std::string name, int gradeSign, int gradeExec)
{
	try
	{
		Form first(name, gradeSign, gradeExec);
		std::cout << first;

		Form second(first);
		std::cout << second;

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void	test_on_assignment_op(std::string  name1, int gradeSign1, int gradeExec1, std::string name2, int gradeSign2, int gradeExec2)
{
	try
	{
		Form first(name1, gradeSign1, gradeExec1);
		std::cout << first;

		Form second(name2, gradeSign2, gradeExec2);
		std::cout << second;

		first = second;

		std::cout << first;
		std::cout << second;

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void	test_on_signing_a_form( int gradeBureaucrat, int gradeSignForm, int gradeExecForm )
{
	try
	{
		Bureaucrat bob("Bob", gradeBureaucrat);
		std::cout << bob;

		Form form("Work contract", gradeSignForm, gradeExecForm);
		std::cout << form;

		bob.signForm(form);
		std::cout << form;

		bob.signForm(form);
		std::cout << form;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}



int main( void )
{

	print_title("Test on form's gradeExec and gradeSign limits");
	test_on_grades(150, 1);
	test_on_grades(151, 2);
	test_on_grades(0, 149);
	test_on_grades(1, 151);
	test_on_grades(1, -5);

	print_title("Test on signing a form: beSigned() and signForm()");
	test_on_signing_a_form(150, 149, 149);
	test_on_signing_a_form(5, 5, 2);

	print_title("Test on copy constructor");
	test_on_copy_constructor("Holidays", 65, 12);

	print_title("Test on assignment operator");
	test_on_assignment_op("Work contract", 65, 14, "Holidays", 150, 47);

}
