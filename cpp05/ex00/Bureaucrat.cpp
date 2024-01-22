#include "Bureaucrat.hpp"

// static members initialization-----------------------------------------------------------------------------------

const int Bureaucrat::gradeMax = 1;
const int Bureaucrat::gradeMin = 150;

// Canonical form constructors--------------------------------------------------------------------------------------

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(0) {

	std::cout << DIM << ITALIC << "Creating a default bureaucrat ( no name )  with grade 0 " << END << std::endl;
	return;
}

Bureaucrat::~Bureaucrat( void ) {

	std::cout << DIM << ITALIC << "Bureaucrat " << ( this->_name.empty() ? "( no name )" :  this->_name ) << " destroyed" <<  END << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {

	std::cout << DIM << ITALIC << "Creating a copy of " << ( src._name.empty() ? "( no name )" : src._name) << " with grade " << src._grade << "." <<  END << std::endl;
	testGrade();
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {

	if (this == &rhs)
		return *this;

	std::cout << DIM << ITALIC << "Assigning " << ( rhs._name.empty() ? "( no name )" : rhs._name) << "'s'grade " << rhs._grade << " to " << ( this->_name.empty() ? "( no name )" :  this->_name ) <<  END << std::endl;
	this->_grade = rhs._grade;
	testGrade();

	if ( this->_name.empty() && !rhs._name.empty())
	{
		std::cout << DIM << ITALIC << "Assigning " << rhs._name << "'s'name to ( no name )" <<  END << std::endl;
		const_cast<std::string&>(this->_name) = rhs._name;
	}
	return *this;
}

// Parametrized constructor----------------------------------------------------------------------------------------

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)  {

	std::cout << DIM << ITALIC << "Trying to create " << ( name.empty() ? "( no name )" : name) << " with grade " << grade << "." <<  END << std::endl;
	testGrade();
	return;
}

void	Bureaucrat::testGrade( void ) const {

	if (this->_grade < gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > gradeMin)
		throw Bureaucrat::GradeTooLowException();
	return;
}

// Member functions----------------------------------------------------------------------------------------------

std::string	Bureaucrat::getName( void ) const {

	return ( this->_name.empty() ? "( no name )" :  this->_name );
}

int	Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

// Increment & decrement functions--------------------------------------------------------------------------------

void	Bureaucrat::increment() {

	std::cout << DIM << ITALIC << "Incrementing " << (this->_name.empty() ? "( no name )" :  this->_name ) <<  "'s grade" << END << std::endl;
	this->_grade -= 1;
	if (this->_grade < gradeMax)
		throw Bureaucrat::GradeTooHighException();
	return;
}

void	Bureaucrat::decrement() {

	std::cout << DIM << ITALIC << "Decrementing " << (this->_name.empty() ? "( no name )" :  this->_name ) <<  "'s grade" << END << std::endl;
	this->_grade += 1;
	if (this->_grade > gradeMin)
		throw Bureaucrat::GradeTooLowException();
	return;
}

// Operator---------------------------------------------------------------------------------------------------

std::ostream&	operator<<( std::ostream &stream, Bureaucrat const &object ) {

	stream << object.getName() << " exists with grade " << object.getGrade() << std::endl;
	return stream;
}


// Exception classes--------------------------------------------------------------------------------------------

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception thrown. Grade is too high.");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception thrown. Grade is too low.");
}