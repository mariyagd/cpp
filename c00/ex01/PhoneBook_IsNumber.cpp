#include "phone.h"

int PhoneBook::_isNumber(std::string& str, int _tableSize) const {

	int i(0);
	std::string maxInt("2147483647");

	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	if (str == "EXIT")
		return -2;
	if (str[i] == '\0' || str[i] == '\n') {
		std::cout << "Empty input. ";
		return -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9') {
			std::cout << "Not a number or not a valid number. ";
			return -1;
		}
		if (str[i] == ' ') {
			std::cout << "Multiple inputs. ";
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
	if (std::stoi(str) > _tableSize) {
		std::cout << "Index is not in the table. ";
		return -1;
	}
	return std::stoi(str);
}