#include <iostream>
#include <string>
#include <limits>

#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define END "\033[0m"

int main() {
	std::string s;
	int i;
	float f;
	double d;

	std::cout << "Please enter a string: ";
	std::cin >> s;
	std::cout << BLUE << "You entered string: " << s << END << std::endl;

	std::cout << "Please enter an int: ";
	std::cin >> i;
	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << RED << "Invalid input, try again: " << END;
		std::cin >> i;
	}
	std::cout << BLUE << "You entered int: " << i << END << std::endl;

	std::cout << "Please enter a float: ";
	std::cin >> f;
	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << RED << "Invalid input, try again: " << END;
		std::cin >> f;
	}
	std::cout << BLUE << "You entered float: " << f << END << std::endl;

	std::cout << "Please enter a double: ";
	std::cin >> d;
	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << RED << "Invalid input, try again: " << END;
		std::cin >> d;
	}
	std::cout << BLUE << "You entered double: " << d << END << std::endl;

	return 0;
}

