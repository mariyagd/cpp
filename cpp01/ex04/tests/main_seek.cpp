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

	std::streampos current;

	current = monFlux.tellg();
	std::cout << "A l'ouverture du fichier le curseur se trouve à: " << current << std::endl;

	monFlux.seekg(10);
	current = monFlux.tellg();
	std::cout << "Apres déplacement de 10 octets, le curseur se trouve à: " << current << std::endl;

	monFlux.seekg(20, std::ios::beg);
	current = monFlux.tellg();
	std::cout << "Apres déplacement de 20 octets depuis le debut, le curseur se trouve à: " << current << std::endl;
	return 0;
}