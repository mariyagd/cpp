// get_time example
#include <iostream>     // std::cin, std::cout
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm
#include <string>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include "../BitcoinExchange.hpp"

/*
int main ()
{
	std::string line = "2011-02-23 65.36";
	struct std::tm tm = {};

	std::istringstream iss(line);
	(void)	line;

	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (iss.fail())
	{
		std::cout << "Parse failed\n";
		tm.tm_year = 0;
		tm.tm_mon = 0;
		tm.tm_mday = 0;
		std::cout << std::put_time(&tm, "%Y-%m-%d");

		return -1;
	}
	std::cout << "ok\n";

	std::cout << std::put_time(&tm, "%Y-%m-%d");
	return 0;
}*/

int main ()
{
	std::string line = "2011-02-23,65";
	std::istringstream iss(line);

	std::string s_date;
	std::string s_rate;
	getline(iss, s_date, ',');
	getline(iss, s_rate);

	int year, month, day;
	char hyphen1, hyphen2;

	iss.clear();
	iss.ignore();
	iss.str(s_date);

	iss >> year >> hyphen1 >> month >> hyphen2 >> day;

	if (!iss.fail())
	{
		std::cout << "ok: " << year << std::endl;
	}
	else
	{
		std::cout << "Error: " << year << std::endl;
		iss.clear();
		iss.ignore();
	}
	return 0;
}