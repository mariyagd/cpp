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
	for (i = 0 ; i < s.size() && std::isspace(s[i]); i++);
	s = s.substr(i);
	for (i = s.size() - 1 ; i < s.size() && std::isspace(s[i]); i--, s.pop_back());
}


void	ScalarConverter::print(const int i, const char c, const float f, const double d) const {

	if (!f && d)
	{
		std::cout << "int: impossible"<< std::endl;
		std::cout << "char: impossible"<< std::endl;
		std::cout << "float: impossible"<< std::endl;
	}
	else if (!i && d)
	{
		std::cout << "int: impossible"<< std::endl;
		std::cout << "char: impossible"<< std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else
	{
		std::cout << "int: " << i << std::endl;
		if ( (c >= 0 && c <= 32) || c == 127 )
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: \'" << c << "\'" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1)<< d << std::endl;

}

typeEnum	ScalarConverter::findType(std::string& s) const {

	size_t	i = 0;
	int 	pointCount = 0;

	switch (s.size()) {
		case 1 : {
			if (!std::isdigit(s[0], std::locale()))
				return CHAR;
			return INT;
		}
		case 3 : {
			if (s[0] == '\'' && s[2] == '\'') {
				s = s[1];
				return CHAR;
			}
		}
		default:
			break;
	}
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; std::isdigit(s[i]) || s[i] == '.'; ++i)
	{
		if (s[i] == '.')
			pointCount++;
	}
	if ( s.empty() || pointCount > 1 || i != s.size())
	{
		throw (std::invalid_argument("Exception thrown: Invalid argument: Not a digit"));
	}
	else if (i == s.size() - 1 && s[i] == 'f')
	{
		s.pop_back();
		return FLOAT;
	}
	else if (i == s.size() && pointCount == 1)
		return DOUBLE;
	else
		return INT;

}

void	ScalarConverter::convertType(enum typeEnum type, int& i, char& c, float& f, double& d) const {

	switch (type) {
		case CHAR : {
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		}
		case INT : {
			( i > 127 || i < 0) ? c = 0 : c = static_cast<char>(d);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		}
		case FLOAT : {
			( f > 127.0f || f < 0.0f ) ? c = 0 : c = static_cast<char>(f);
			( f > 0 && f > static_cast<float>( std::numeric_limits<int>::max()) ) ? i = 0 : ( f < 0 && f < static_cast<float>( std::numeric_limits<int>::min()) ) ? i = 0 : i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		}
		case DOUBLE : {

			(d > 127.0 || d < 0.0) ? c = 0 : c = static_cast<char>(d);
			( d > 0 && d > static_cast<double>( std::numeric_limits<int>::max()) ) ?  i = 0 : ( d < 0 && d < static_cast<double>( std::numeric_limits<int>::min()) ) ? i = 0 : i = static_cast<int>(d);
			( d < 0 && d > static_cast<double>( std::numeric_limits<float>::min()) ) ? f = 0 : ( d < 0 && d < static_cast<double>( std::numeric_limits<float>::min()) ) ? f = 0 : f = static_cast<float>(d);
			break;
		}
		default :
			return;
	};
}


void	ScalarConverter::convert( std::string s ) {

	ScalarConverter 		converter;
	typeEnum				type;
	double					d = 0.0;
	float					f = 0.0f;
	char					c = 0;
	int						i = 0;


	converter.deleteWhiteSpace(s);
	type = converter.findType(s);

	std::cout << "type = " << type << std::endl;
	std::cout << "s = " << s << std::endl;
	std::istringstream 		iss(s);
		switch (type)
	{
		case CHAR : {
			iss >> c;
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
		default:
			return;
	};
	if (iss.fail())
		throw (std::overflow_error("Exception thrown: Invalid argument: Input overflow"));
	converter.convertType(type, i, c, f, d);
	converter.print(i, c, f, d);



}

