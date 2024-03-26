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

void	ScalarConverter::convert( std::string scalar ) {


	if (scalar.size() == 1)
	{
		std::cout << "int: " << static_cast<int>(scalar[0]) << std::endl;
		std::cout << "char: " << scalar[0] << std::endl;
		std::cout << "float: " << static_cast<float>(scalar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(scalar[0]) << ".0" << std::endl;
		return;
	}

	int		a = 0;
	float	f = 0.0f;
	double	d = 0.0;
	char	c = 0;


	try
	{
		a = std::stoi(scalar);
		std::cout << "int: " << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		f = std::stof(scalar);
		if ( f - static_cast<int>(f)  == 0 && f >= 0.0 && f <= 127.0)
		{
			c = static_cast<char>(f);
			if ( (c >= 0 && c <= 32) || c == 127 )
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: \'" << c << "\'" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "float: " << f  << (f - static_cast<int>(f) == 0.0f ? ".0f" : "" ) << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		d = std::stod(scalar);
		std::cout << "double: " << d  << (d - static_cast<int>(d) == 0.0 ? ".0" : "" ) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

