
/*
#include <iostream>
#include <sstream>
#include <string>

int main() {
	std::string s = "2011-02-05 | 36";

	std::istringstream iss(s);

	std::string date, value;
	char pipe;

	iss >> date >> pipe >> value;

	std::cout << " date: " << date << std::endl
			  << " pipe: " << pipe << std::endl
			  << " value: " << value << std::endl;

	return 0;
}
*/

#include <iostream>
#include <sstream>
#include <string>

int main() {
	std::string s = "couou";

	std::istringstream iss(s);

	std::string s2;
	std::string s3;
	iss >> s2;
	std::cout << s2 << std::endl;

//	int year, month, date, value;
//	char pipe, hyphen1, hyphen2;
//
//	iss >> year >> hyphen1 >> month >> hyphen2 >> date >> pipe >> value;
//	if (iss.fail())
//	{
//		std::cout << "failed" << std::endl;
//		return 1;
//	}
//
//	std::cout << "year: " << year << std::endl
//			  << "hyphen1: " << hyphen1 << std::endl
//			  << "month: " << month << std::endl
//			  << "hyphen2: " << hyphen2 << std::endl
//			  << "date: " << date << std::endl
//			  << "pipe: " << pipe << std::endl
//			  << "value: " << value << std::endl;

	return 0;
}
