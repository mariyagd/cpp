#include "phone.h"

int PhoneBook::_isNumber(std::string& str, int _tableSize) const {

	int i(0);
	std::string maxInt("2147483647");

	_eraseWhiteSpaces(str);
	if (str.empty()) {
		std::cout << "Empty input. ";
		return -1;
	}
	_transformToUpper(str);
	if (str == "EXIT")
		return -2;
	while (str[i])
	{
		if (!std::isdigit(str[i])) {
			std::cout << "Not a number or not a valid number. ";
			return -1;
		}
		i++;
	}
	if (str.length() >= maxInt.length() && str > maxInt) {
		std::cout << "Not a int. ";
		return -1;
	}
	if (str[0] == '0' && str.length() > 1) {
		std::cout << "Not a valid number. ";
		return -1;
	}
	if (std::stoi(str) >= _tableSize) {
		std::cout << "Index is not in the table. ";
		return -1;
	}
	return std::stoi(str);
}