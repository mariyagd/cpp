#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main() {

	const char *filename = "only_title.csv";

	std::ifstream ifs( filename);

	while (ifs.good())
	{
		char s[256];
		ifs.get(s, sizeof(s), '-');
		std::cout << s << std::endl;
	}
	return 0;
}
