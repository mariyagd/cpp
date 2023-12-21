#include "phone.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << BOLD << "Please open this program without any arguments." << RESET << std::endl;
		return 1;
	}
	PhoneBook	PhoneBook;
	return 0;
}