#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <sstream>
# include <string>
# include <ostream>
# include <iostream>


class Rpn {

private:
	std::stack< int >	_stack;

public:
	Rpn( void );
	~Rpn( void );
	Rpn( Rpn const & src );
	Rpn &	operator=( Rpn const & src );

	Rpn( const std::string & av );

	std::stack< int >	getStack( void ) const;
	bool	isArithmeticCharacter( std::string & s ) const;

	bool	isValidNumber( std::string & s );
	bool	isValidPositiveNumber( std::string & s );
	bool	isValidNegativeNumber( std::string & s );

};

std::ostream &	operator<<( std::ostream & stream, Rpn const & rpn )    ;

#endif