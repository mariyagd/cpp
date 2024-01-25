#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# define ITALIC		"\033[2;3m"
# define END		"\033[0m"
# define BLUE		"\033[1;34m"
# define BOLD		"\033[1m"
# define RED		"\033[1;31m"

#include <sstream>
#include <cctype> //isdigit
#include <limits>


enum	typeEnum { CHAR, INT, FLOAT, DOUBLE };	// INFF_NEG, INFF_POS, NANF, INF_NEG, INF_POS, _NAN };

class ScalarConverter {

private:
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( ScalarConverter const& src );
	ScalarConverter&	operator=( ScalarConverter const& src );

	void		print(const int i, const char c, const float f, const double d) const;
	typeEnum	findType( std::string& s) const;
	void		convertType(enum typeEnum, int& i, char& c, float& f, double& d) const;
	void		deleteWhiteSpace( std::string &s) const;

public:
	static void		convert( std::string s );
};

#endif