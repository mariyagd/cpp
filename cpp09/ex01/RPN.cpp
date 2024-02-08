#include "RPN.hpp"

// Coplien's form-------------------------------------------------------------------------------------------------------

Rpn::Rpn( void ) : _stack() {

	return;
}

Rpn::~Rpn( void ) {

	return;
}

Rpn::Rpn( const Rpn &src ) : _stack( src._stack ) {

	return;
}

Rpn &	Rpn::operator=( const Rpn & src ) {

	if (this != &src )
	{
		if ( !this->_stack.empty() )
			this->_stack = std::stack< int >();
		this->_stack = src._stack;
	}
	return *this;
}

// Parametrized constructor---------------------------------------------------------------------------------------------

Rpn::Rpn( const std::string & av ) : _stack() {

	std::istringstream iss( av );

	while ( iss.peek() != EOF)
	{
		std::string s = "";

		iss >> s;

		while ( !iss.fail() && isValidNumber(s) )								// add in stack if it's a digits
		{
			this->_stack.push(std::atoi(s.c_str() ) );
			s.clear();																// useful in case next call of iss streams an empty string. If you don't clear, you will keep in memory previous content.
			iss >> s;
		}
		if ( s.empty() && iss.peek() == EOF && this->_stack.size() == 1 )			// ./RPN "1" or ./RPN "1    " (only one number !) are valid inputs. In these two cases,  iss streams an empty string
			return;

// 		for debugging see stack evolution
//		std::cout << *this;

		if ( !iss.fail() && this->_stack.size() > 1 && isArithmeticCharacter( s ) )
		{
			int operand2 = this->_stack.top( ); this->_stack.pop( );
			int operand1 = this->_stack.top( ); this->_stack.pop( );				// operand1 is the second element in the stack!

			switch ( s[0] ) {
				case '+':
					this->_stack.push( operand1 + operand2 );
					break;
				case '-':
					this->_stack.push( operand1 - operand2 );
					break;
				case '*':
					this->_stack.push( operand1 * operand2 );
					break;
				case '/':
				{
					if ( operand2 != 0)												// can't make division by 0
						this->_stack.push( operand1 / operand2 );
					else
						throw std::runtime_error( "Division by 0!" );
				}
					break;
			}
		}
		else
			throw std::runtime_error( "Invalid input" );
	}
	if (this->_stack.size() != 1)												// at the end, the size of the stack should always be 1
		throw std::runtime_error( "Invalid input" );
	return;
}

// Valid number---------------------------------------------------------------------------------------------------------

bool	Rpn::isValidNumber( std::string & s ) {

	if ( isValidPositiveNumber(s) || isValidNegativeNumber(s) )
		return true;
	else
		return false;
}

bool	Rpn::isValidPositiveNumber( std::string & s ) {

	if ( s.size() == 1 && std::isdigit(s[0]) )
		return true;
	return false;
}

bool	Rpn::isValidNegativeNumber( std::string & s ) {

	if ( s.size() == 2 && (s[0] == '-' || s[0] == '+') && std::isdigit(s[1]) )
		return true;
	return false;
}

// Arithmetic character-------------------------------------------------------------------------------------------------

bool	Rpn::isArithmeticCharacter( std::string & s ) const {

	if ( s.size() != 1 )
		return false;
	if ( s[0] == '/' || s[0] == '*' || s[0] == '+' || s[0] == '-' )
		return true;
	return false;
}

// Getters--------------------------------------------------------------------------------------------------------------

std::stack< int >	Rpn::getStack( void ) const {

	return this->_stack;
}

// Output operator------------------------------------------------------------------------------------------------------

std::ostream &	operator<<( std::ostream & stream, Rpn const & rpn )
{
	std::stack< int >	copy_stack = rpn.getStack();
	while ( !copy_stack.empty() )
	{
		stream << copy_stack.top() << " ";
		copy_stack.pop();
	}
	stream << std::endl;

	return stream;
}

