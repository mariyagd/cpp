#include <iostream>
#include <map>
#include <unordered_map>

int main() {
	// Exemple d'utilisation de map
	std::map<int, std::string> mapExemple;
	mapExemple.insert(std::make_pair(1, "Premier"));
	mapExemple.insert(std::make_pair(2, "Deuxième"));
	mapExemple.insert(std::make_pair(1, "Autre valeur1")); // Cette insertion ne remplace pas la première paire
	mapExemple.insert(std::make_pair(2, "Autre valeur2")); // Cette insertion ne remplace pas la première paire
	mapExemple.insert(std::make_pair(3, "Deuxième")); // Cette insertion ne remplace pas la première paire

	std::cout << "Taille de mapExemple : " << mapExemple.size() << std::endl; // Affiche 2

	for (auto it = mapExemple.begin(); it != mapExemple.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}

	// Exemple d'utilisation de multimap
	std::multimap<int, std::string> multimapExemple;
	multimapExemple.insert(std::make_pair(1, "Premier"));
	multimapExemple.insert(std::make_pair(2, "Deuxième"));
	multimapExemple.insert(std::make_pair(1, "Autre valeur")); // Cette insertion ajoute une nouvelle paire avec la même clé

	std::cout << "Taille de multimapExemple : " << multimapExemple.size() << std::endl; // Affiche 3

for (auto it = multimapExemple.begin(); it != multimapExemple.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}

	return 0;
}
