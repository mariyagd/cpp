#include <iostream>
#include <vector>
#include <cmath>

// Fonction pour générer les nombres de Jacobsthal jusqu'à un certain indice
std::vector<int> generateJacobsthalNumbers(int maxIndex) {
	std::vector<int> jacobsthalNumbers;
	jacobsthalNumbers.push_back(0); // J(0)
	jacobsthalNumbers.push_back(1); // J(1)

	for (int i = 2; i <= maxIndex; ++i) {
		int jacobsthalNumber = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
		jacobsthalNumbers.push_back(jacobsthalNumber);
	}

	return jacobsthalNumbers;
}

int main() {
	int maxIndex = 10; // Indice maximum pour générer les nombres de Jacobsthal
	std::vector<int> jacobsthalNumbers = generateJacobsthalNumbers(maxIndex);

	// Affichage des nombres de Jacobsthal générés
	std::cout << "Jacobsthal numbers up to index " << maxIndex << ": ";
	for (int i = 0; i <= maxIndex; ++i) {
		std::cout << jacobsthalNumbers[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}