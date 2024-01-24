#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>

//enum	scalarEnum { CHAR, INT, FLOAT, DOUBLE, INFF_NEG, INFF_POS, NANF, INF_NEG, INF_POS, _NAN };

class ScalarConverter {

private:
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( ScalarConverter const& src );
	ScalarConverter&	operator=( ScalarConverter const& src );

//	scalarEnum getType( std::string &scalar );

public:
	static void		convert( std::string scalar );
};

#endif