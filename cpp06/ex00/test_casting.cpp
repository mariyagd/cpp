#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

void	print_line( void )
{
	std::cout << std::setfill('-') << std::setw(50) << "-" << std::endl;
}

void	print_title(std::string s)
{
	std::cout << s << std::endl;
	print_line();
}

void	print(std::string s, char &c, int&i, float& f, double& d)
{
	print_title(s);
	std::cout << "char: " << c << " (int)char: " << (int)c << std::endl;
	std::cout << "int: " << i << std::endl;
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

	std::cout << "max char   " << std::setw(20) <<(int)std::numeric_limits<char>::max() << std::endl;
	std::cout << "min char   " << std::setw(20) << (int)std::numeric_limits<char>::min() << std::endl;
	std::cout << "max int    " << std::setw(20) << std::numeric_limits<int>::max() << std::endl;
	std::cout << "min int    " << std::setw(20) << std::numeric_limits<int>::min() << std::endl;
	std::cout << "max float  " << std::setw(20) << std::numeric_limits<float>::max() << std::endl;
	std::cout << "min float  " << std::setw(20) << std::numeric_limits<float>::min() << std::endl;
	std::cout << "max double " << std::setw(20) << std::numeric_limits<double>::max() << std::endl;
	std::cout << "min double " << std::setw(20) << std::numeric_limits<double>::min() << std::endl;
	print_line();
	{
		std::istringstream iss("3253286453864538776453186845138687645138645314864584651328645132645386453168458645316453121213531465.0");
		iss >> f;
		if (iss.fail())
			std::cout << "fail" << std::endl;
		else
		{
			std::cout << "no fail" << std::endl;

		}
		c = static_cast<char>(f);
		i = static_cast<int>(i);
		d = static_cast<double>(f);
		print("Test int bigger that char max", c, i, f, d);
			std::cout << std::numeric_limits<float>::infinity() << std::endl;
			std::cout << std::numeric_limits<double>::infinity() << std::endl;
		if (std::numeric_limits<float>::has_infinity)
		{
			std::cout << "has infinity" << std::endl;
		} else
			std::cout << "no infinity" << std::endl;
	}

}