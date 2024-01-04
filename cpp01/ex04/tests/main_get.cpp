#include <iostream>
#include <fstream>

int	main(void)
{
	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	char c;
	while (monFlux.get(c))
		std::cout << c;
	return 0;
}