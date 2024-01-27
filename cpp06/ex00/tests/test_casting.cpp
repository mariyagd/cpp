#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
# define ITALIC		"\033[2;3m"
# define BLUE		"\033[1;34m"
# define BOLD		"\033[1m"
# define END		"\033[0m"


void	print_line( void )
{
	std::cout << BLUE << std::setfill('-') << std::setw(50) << "-" << END << std::endl;
}

void	print_title(std::string s)
{
	std::cout << BLUE << s << END << std::endl;
	print_line();
}

void	print(char &c, int&i, float& f, double& d)
{
	std::cout << "int: " << i << std::endl;

	if (!std::isprint(c))
		std::cout << "char: Non displayable"<< std::endl;
	else
		std::cout << "char: \'" << c << "\'"<< std::endl;

	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
	print_line();
}


int main(void)
{
	int i = 0;
	float f;
	double d;
	char c;

	std::cout << "max char      " << std::setw(20) <<(int)std::numeric_limits<char>::max() << std::endl;
	std::cout << "min char      " << std::setw(20) << (int)std::numeric_limits<char>::min() << std::endl;
	std::cout << "max int       " << std::setw(20) << std::numeric_limits<int>::max() << std::endl;
	std::cout << "min int       " << std::setw(20) << std::numeric_limits<int>::min() << std::endl;
	std::cout << "max float     " << std::setw(20) << std::numeric_limits<float>::max() << std::endl;
	std::cout << "min float     " << std::setw(20) << std::numeric_limits<float>::min() << std::endl;
	std::cout << "lowest float  " << std::setw(20) << std::numeric_limits<float>::lowest() << std::endl;
	std::cout << "max double    " << std::setw(20) << std::numeric_limits<double>::max() << std::endl;
	std::cout << "min double    " << std::setw(20) << std::numeric_limits<double>::min() << std::endl;
	std::cout << "lowest double " << std::setw(20) << std::numeric_limits<double>::lowest() << std::endl;

	print_line();
	{
		print_title("Test float 3253286453864538776453186845138687645138645314864584651328645132645386453168458645316453121213531465.0");
		std::istringstream iss("3253286453864538776453186845138687645138645314864584651328645132645386453168458645316453121213531465.0");
		iss >> f;
		if (iss.fail())
		{
			std::cout << "iss failed. overflow" << std::endl;
			print_line();

		}
		else
		{
			std::cout << "iss successful" << std::endl;
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			print( c, i, f, d);
		}
	}

	{
		print_title("Test float -1.1756f");
		std::istringstream iss("-1.1756");
		iss >> f;
		if (iss.fail())
		{
			std::cout << "iss failed. overflow" << std::endl;
			print_line();
		}
		else
		{
			std::cout << "iss successful" << std::endl;
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			print( c, i, f, d);
		}
	}

	{
		print_title("Test float 1.17549e-38 (float min)");
		std::istringstream iss("1.17549e-38");
		iss >> f;
		if (iss.fail())
		{
			std::cout << "iss failed. overflow" << std::endl;
			print_line();
		}
		else
		{
			std::cout << "iss successful" << std::endl;
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			print( c, i, f, d);
		}
	}
	{
		print_title("Test float 0.000000005f");
		std::istringstream iss("0.000000005");
		iss >> f;
		if (iss.fail())
			std::cout << "iss failed" << std::endl;
		else
			std::cout << "iss ok" << std::endl;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		print( c, i, f, d);
	}
	{
		print_title("Test double 9e+1");
		std::istringstream iss("9e+1");
		iss >> d;
		(d > 127.0 || d < 0.0 ) ? c = 0 : c = static_cast<char>(d);
		f = static_cast<int>(d);
		i = static_cast<double>(d);
		print( c, i, f, d);
	}
	{
		print_title("Test float 10e-10f");
		std::istringstream iss("10e-10");
		iss >> f;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		print( c, i, f, d);
	}

	{
		print_title("Test float 99.2658544");
		std::istringstream iss("99.2658544");
		iss >> f;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		print( c, i, f, d);
	}

	{
		print_title("Test char c = 'c'");
		std::istringstream iss("c");
		iss >> c;
		f = static_cast<char>(c);
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		print(c, i, f, d);
	}
	{
		print_title("Test c= \"\\t\" (tab)");

		c = '\t';
		f = static_cast<char>(c);
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		print(c, i, f, d);
	}

	{
		print_title("Test float 2147.483648");
		std::istringstream iss("2147.483648");
		iss >> f;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		print(c, i, f, d);
	}
	{
		print_title("Float modulo");
		f = 8565984651845613.45654268453645323f;
		float ff;
		float d = std::modf(f, &ff) == 0;
		if (d == 0)
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
		{
			std::cout << "ici " << f << "f" << std::endl;
		}
		std::cout << "modf() makes " << ff << " + " << d << '\n';
//		float fr = modff(f, &ff);
//		std::cout << "modf() makes " << fr << " + " << ff << '\n';
	}
}