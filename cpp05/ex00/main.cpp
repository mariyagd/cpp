#include "./Bureaucrat.hpp"
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

void	test_on_grades(int grade)
{
	try
	{
		Bureaucrat mariya("Mariya", grade);							// <--- scope evaluations stops here
		std::cout << BOLD << mariya << END;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();

}

void	test_on_incrementation( int grade )
{
	try
	{
		Bureaucrat mariya("Mariya", grade);							// <--- scope evaluations stops here
		std::cout << BOLD << mariya << END;

		for (int i = 0; i  < 5; i++)
		{
			mariya.increment();
			std::cout << BOLD << mariya << END;
		}

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void test_on_decrementation( int grade ) {

	try
	{
		Bureaucrat mariya("Mariya", grade);							// <--- scope evaluations stops here
		std::cout << BOLD << mariya << END;

		for (int i = 0; i  < 5; i++)
		{
			mariya.decrement();
			std::cout << BOLD << mariya << END;
		}

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void	test_on_copy_constructor( std::string name, int grade)
{
	try
	{
		Bureaucrat first(name, grade);
		std::cout << BOLD << first << END;

		Bureaucrat second(first);
		std::cout << BOLD << second << END;

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void	test_on_assignment_op(std::string  name1, int grade1, std::string name2, int grade2)
{
	try
	{
		Bureaucrat first(name1, grade1);
		std::cout << BOLD << first << END;

		Bureaucrat second(name2, grade2);
		std::cout << BOLD << second << END;

		first = second;
		std::cout << BOLD << first << END;

	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	print_small_line();
}

void	test_assign_op_default( void )
{
	try
	{
		Bureaucrat first;
		std::cout << BOLD << first << END;

		Bureaucrat second("Bob", 12);
		std::cout << BOLD << second << END;

		first = second;
		std::cout << BOLD << first << END;

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

	print_title("Test on grade's limits");
	test_on_grades(150);
	test_on_grades(151);
	test_on_grades(1);
	test_on_grades(0);

	print_title("Test on incrementation: increment 5 times");
	test_on_incrementation(150);
	test_on_incrementation(1);

	print_title("Test on decrementation: decrement 5 times");
	test_on_decrementation(150);
	test_on_decrementation(1);

	print_title("Test on copy constructor");
	test_on_copy_constructor("Mariya", 65);

	print_title("Test on assignment operator");
	test_on_assignment_op("Mariya", 65, "Vlad", 150);

	print_title("Test on assignment operator with a default bureaucrat");
	test_assign_op_default();


}