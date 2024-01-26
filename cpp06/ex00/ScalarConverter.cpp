#include "ScalarConverter.hpp"

// Canonical form------------------------------------------------------------------------
ScalarConverter::ScalarConverter( void ) {

	// throw
	return;
}

ScalarConverter::~ScalarConverter( void ) {
	return;
}

ScalarConverter::ScalarConverter( const ScalarConverter &src ) {

	(void)src;
	return;
}

ScalarConverter&	ScalarConverter::operator=( ScalarConverter const& src ) {

	(void)src;
	return *this;
}

// Static method----------------------------------------------------------------------------

void		ScalarConverter::deleteWhiteSpace( std::string &s) const {

	size_t i;
	if (s.size() == 1)
		return;
	for (i = 0 ; i < s.size() && std::isspace(s[i]); i++);
	s = s.substr(i);
	for (i = s.size() - 1 ; i < s.size() && std::isspace(s[i]); i--, s.pop_back());
}


typeEnum	ScalarConverter::findType(std::string& s) const {

	size_t	i = 0;
	int 	decimalPointCount = 0;
	int 	exposantCount = 0;

	switch (s.size()) {

		case 1 :
			if ( std::isdigit(s[0]) )																		// if you have a single number like 4 you should take it as an int
				return INT;
			if (isspace(s[0]))																				// if you have space : " "
				return CHAR_ISSPACE;
			return CHAR;
		case 2 :
			if (s[0] == '\\' && s.find_first_of("trfnv", 1) != std::string::npos ) {					// if you have \t, \r, \v, \f, \n
				s = s[1];
				return CHAR_ISSPACE;
			}
		case 3 :
			if (s[0] == '\'' && s[2] == '\'') {																	// if you have '4' you should take it as a char not int
				s = s[1];
				return CHAR;
			}
		case 4 :
			if (s[0] == '\'' && s[3] == '\'' && s[1] == '\\' && s.find_first_of("trfnv", 2) != std::string::npos) {	// if you have '\t', '\r', '\v', '\f', '\n'
				s = s[2];
				return CHAR_ISSPACE;
			}
		default:
			break;
	}

	if (s == "nanf" || s == "+inff" || s == "-inff")
		return FLOAT;
	if (s == "nan" || s == "+inf" || s == "-inf")
		return DOUBLE;

	if (s[i] == '+' || s[i] == '-')																				// Check for sign
		i++;
	for (; std::isdigit(s[i]) || s[i] == '.' || s[i] == 'e'; ++i)
	{
		if (s[i] == '.')                                                                                        // Check for decimal point
			decimalPointCount++;
		if (s[i] == 'e')
		{
			if (decimalPointCount <= 1&& (s[i + 1] == '+' || s[i + 1] == '-') && exposantCount == 0) {
				exposantCount++;
				i++;
			}
			else
				throw (std::invalid_argument("Exception thrown: Invalid argument: Not a digit"));
		}
	}

	switch (decimalPointCount) {

		case 0 :
			if (i == s.size() && exposantCount == 0)
				return INT;
		case 1 :
			if (i == s.size() - 1 && s[i] == 'f')
				return FLOAT;
			else if (i == s.size())
				return DOUBLE;
		default:
			throw (std::invalid_argument("Exception thrown: Invalid argument: Not a digit"));		// Handle invalid input with stdexcept

	}
	return INT;
}

//			( f > 0 && f > static_cast<float>( std::numeric_limits<int>::max()) ) ? i = 0 : \
//			( f < 0 && f < static_cast<float>( std::numeric_limits<int>::min()) ) ? i = 0 : i = static_cast<int>(f);

void	ScalarConverter::convertType(enum typeEnum type, int& i, char& c, float& f, double& d) const {


	switch (type) {
		case CHAR :
		case CHAR_ISSPACE : {
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		}
		case INT : {
			( i > 127 || i < 0 ) ? c = 0 : c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		}
		case FLOAT : {

			( f > 127.0f || f < 0.0f ) ? c = 0 : c = static_cast<char>(f);

			if (f > 0)
				f > static_cast<float>( std::numeric_limits<int>::max()) ? i = 0 : i = static_cast<int>(f);
			else
				f < static_cast<float>( std::numeric_limits<int>::min()) ? i = 0 : i = static_cast<int>(f);

			d = static_cast<double>(f);
			break;
		}
		case DOUBLE : {

			(d > 127.0 || d < 0.0 ) ? c = 0 : c = static_cast<char>(d);
			( d > 0 && d > static_cast<double>( std::numeric_limits<int>::max()) ) ?  i = 0 : \
			( d < 0 && d < static_cast<double>( std::numeric_limits<int>::min()) ) ? i = 0 : i = static_cast<int>(d);

			if (d > 0)
			{
				d > static_cast<double>( std::numeric_limits<float>::max()) ? f = 0.0f : \
                d < static_cast<double>( std::numeric_limits<float>::min()) ? f = 0.0f : f = static_cast<float>(d);
			}
			else
				d < static_cast<double>( std::numeric_limits<float>::lowest()) ? f = 0.0f : f = static_cast<float>(d);

		}
		default :
			return;
	};
}

void	ScalarConverter::print( int& i, char& c, float& f, double& d) const {

	if (!f && !(d >= 0.0 && d < 1.0))
	{
		std::cout << "int: impossible"<< std::endl;
		std::cout << "char: impossible"<< std::endl;
		std::cout << "float: impossible"<< std::endl;
	}

	else if (!i && !(d >= 0.0 && d < 1.0))
	{
		std::cout << "int: impossible"<< std::endl;
		std::cout << "char: impossible"<< std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else
	{
		std::cout << "int: " << i << std::endl;
		if ( !c && !(d >= 0.0 && d < 1.0) )
			std::cout << "char: impossible"<< std::endl;
		else if ( std::isprint(c) )
			std::cout << "char: \'" << c << "\'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void	ScalarConverter::convert( std::string s ) {

	ScalarConverter 		converter;
	std::istringstream 		iss;
	typeEnum				type;
	double					d = 0.0;
	float					f = 0.0f;
	char					c = 0;
	int						i = 0;



	converter.deleteWhiteSpace(s);
	type = converter.findType(s);

	if (type == FLOAT)
		s.pop_back();

	iss.str(s);


	switch (type)
	{
		case CHAR : {
			iss >> c;
			break;
		}
		case CHAR_ISSPACE : {
			s == "t" ? c = '\t' : s == "v" ? c = '\v' : s == "r" ? c = '\r' : s == "n" ? c = '\n' : s == "f" ? c = '\f' : s == " " ? c = ' ' : c = 0;
			break;
		}
		case INT :  {
			iss >> i;
			break;
		}
		case FLOAT : {
			iss >> f;
			break;
		}
		case DOUBLE : {
			iss >> d;
			break;
		}
	};
	if (iss.fail())
	{
		throw (std::overflow_error("Exception thrown: Invalid argument: Input overflow"));
	}
	converter.convertType(type, i, c, f, d);
	converter.print(i, c, f, d);
}

