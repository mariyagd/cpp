#include <utility>
#include <iostream>

int main(void)
{
	std::pair<int, int > a( 0, 10);
	std::pair<int, int > b( 3, 6);

	if (a < b)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	if (a.first < b.first && a.second < b.second)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

}