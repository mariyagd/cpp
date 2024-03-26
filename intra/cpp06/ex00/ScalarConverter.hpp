#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>						// for std::istringstream
# include <cctype> 						// for std::isdigit
# include <exception>					// for stdexcept
# include <cmath>						// for std::modf

# define END		"\033[0m"
# define RED		"\033[1;31m"

enum	typeEnum { CHAR, CHAR_ISSPACE, INT, FLOAT, DOUBLE };

class ScalarConverter {

private:
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( ScalarConverter const& src );
	ScalarConverter&	operator=( ScalarConverter const& src );

	void		print(int& i, char& c, float& f, double& d) const;
	void		convertType(enum typeEnum, int& i, char& c, float& f, double& d) const;
	void		deleteWhiteSpace( std::string &s) const;
	typeEnum	findType( std::string& s) const;

public:
	static void		convert( std::string s );
};

#endif