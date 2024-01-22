#include "Form.hpp"

// Static variables initialization------------------------------------------------------------------------------------
const int Form::_gradeMax = 1;
const int Form::_gradeMin = 150;

//Canonical form-----------------------------------------------------------------------------------------------------
Form::Form( void ) : _name(""), _signed(false), _gradeSign(0), _gradeExec(0) {

	std::cout << DIM << ITALIC << "Default form created. Name: ( no name ), signed: false, grade to sign: 0, grade to exec: 0" << END << std::endl;
	return ;
}

Form::~Form( void ) {

	std::cout << DIM << ITALIC << "Form " << ( this->getName() ) << " destroyed." << END << std::endl;
	return ;
}

Form::Form( Form const &src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {

	std::cout	<< DIM << ITALIC
				<< "Trying to copy a form with name: "
				<< ( this->getName() )
				<< ", signed: " << ( this->_signed ? "true" : "false" )
				<< ", grade to sign: " << this->_gradeSign
				<< ", grade to exec: " << this->_gradeExec
				<< END << std::endl;

	testGrade( this->_gradeSign );
	testGrade( this->_gradeExec );
	return ;
}

Form&	Form::operator=( Form const &src ) {

	if (this == &src) {
		return (*this);
	}

	std::cout	<< DIM << ITALIC
				<< "Assigning " << src.getName()
				<< "'s signed to " <<  ( this->getName() )
				<< END << std::endl;

	this->_signed = src._signed;

	if (!this->_gradeSign && !this->_gradeExec && this->_name.empty() && src._gradeSign && src._gradeExec && !src._name.empty())
	{
		std::cout	<< DIM << ITALIC << "This a default form, full assignment autorized. "
					<< "Assigning " << src._name << "'s name, gradeSign and gradeExec to ( no name )" << END << std::endl;
		const_cast<std::string&>(this->_name) = src._name;
		const_cast<int&>(this->_gradeSign) = src._gradeSign;
		const_cast<int&>(this->_gradeExec) = src._gradeExec;

		testGrade( this->_gradeSign );
		testGrade( this->_gradeExec );
	}
	return (*this);
}

// Parametric form----------------------------------------------------------------------------------------------------
Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

	std::cout	<< DIM << ITALIC
				<< "Trying to create a form with name: "
				<< this->getName()
				<< ", signed: false, grade to sign: "
				<< this->_gradeSign << ", grade to exec: "
				<< this->_gradeExec
				<< END << std::endl;

	testGrade( this->_gradeSign );
	testGrade( this->_gradeExec );
	return ;
}

// Getters------------------------------------------------------------------------------------------------------------
std::string const	Form::getName( void ) const {

	return (this->_name.empty() ? "( no name )" : this->_name);
}

bool	Form::getSigned( void ) const {

	return (this->_signed);
}

int		Form::getGradeSign( void ) const {

	return (this->_gradeSign);
}

int		Form::getGradeExec( void ) const {

	return (this->_gradeExec);
}

// Member functions---------------------------------------------------------------------------------------------------

void	Form::beSigned( Bureaucrat &bureaucrat ) {

	bureaucrat.signForm( *this );

	if (bureaucrat.getGrade() <= this->_gradeSign)
	{
		if (!this->_signed)
			this->_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
	return ;
}

// Exceptions tester--------------------------------------------------------------------------------------------------
void	Form::testGrade( int grade ) const {

	if (grade < _gradeMax)
		throw Form::GradeTooHighException();
	else if (grade > _gradeMin)
		throw Form::GradeTooLowException();
}

// Exceptions functions------------------------------------------------------------------------------------------------
const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception thrown. Grade too low.");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception thrown. Grade too high.");
}


// Operator overload--------------------------------------------------------------------------------------------------
std::ostream&	operator<<( std::ostream &stream, Form const &object ) {

	stream	<< BOLD
			<< "Form \"" << ( object.getName().empty() ? "( no name )" : object.getName() )
			<< "\" exists. Form's info: signed: " << ( object.getSigned() ? "true" : "false" )
			<< ", grade to sign: " << object.getGradeSign()
			<< ", grade to exec: " << object.getGradeExec()
			<< END << std::endl;
	return (stream);
}