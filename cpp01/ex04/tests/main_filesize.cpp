#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	// open a file for reading
	std::ifstream myFile("text.txt");
	std::streampos begin, end, size;

	begin = myFile.tellg();
	std::cout << "Current get position: " << begin << std::endl;

	//change the get position
	myFile.seekg(0, std::ios::end);

	end = myFile.tellg();
	std::cout << "Current get position: " << end << std::endl;

	size = end - begin;
	std::cout << "Size of file is: " << size << std::endl;

	myFile.close();
	return 0;

}