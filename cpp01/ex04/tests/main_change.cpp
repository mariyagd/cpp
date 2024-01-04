#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{

	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	std::string mot;
		monFlux >> mot;
	std::cout << mot << std::endl;

	monFlux.ignore();

	std::string ligne;
	getline(monFlux, ligne);
	std::cout << ligne << std::endl;

	return 0;
}