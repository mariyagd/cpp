#include <iostream>
#include <string>

int main(void)
{
	std::string command("                     mariya          hihi            \t\t\t");
	size_t	i(0);
	size_t 	first;
	size_t 	last;

	std::cout << "|" << command << "|" << std::endl;
	if (command.empty())
		return 0;
	while (i < command.length() && isspace(command[i]))
		i++;
	if (i != 0)
		command.erase(0, i);

	i = command.length();
	while (i > 0 && isspace(command[i - 1]))
		i--;
	if (i != command.length())
		command.erase(i);
	std::cout << "|" << command << "|" << std::endl;


	first = command.find_first_of(' ');
	while (first != std::string::npos && first != command.length())
	{
		last = first;
		while (isspace(command[last]))
			last++;
		if (last != first)
		{
			std::cout << first << std::endl;
			std::cout << last << std::endl;
			command = command.replace(first, last - first, " ");
			std::cout << "|" << command << "|" << std::endl;
			first = command.find_first_of(' ', first + 1);
		}
		else
			first = std::string::npos;
	}
	std::cout << "|" << command << "|" << std::endl;

	return 0;
}